#include "system.h"
#include "boot.h"
#include <board.h>

#define DBG_TAG "system"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

extern int rt_hw_spi_flash_init(void);

g_system_t g_system = {0};

static int system_init(void) {
    int rc = rt_hw_spi_flash_init();
    if (rc != RT_EOK) return -RT_ERROR;

    rc = fal_init();
    if (rc <= 0) return -RT_ERROR;

    g_system.app_part = fal_partition_find(APP_PART_NAME);
    if (g_system.app_part == RT_NULL) {
        LOG_E("App partition not find.");
        return -RT_ERROR;
    }

    g_system.download_part = fal_partition_find(DOWNLOAD_PART_NAME);
    if (g_system.download_part == RT_NULL) {
        LOG_E("Download partition not find.");
        return -RT_ERROR;
    }

    return RT_EOK;
}

void system_process(void) {
    switch (g_system.step) {
        case SYSTEM_STEP_INIT: {
            int rc = system_init();
            if (rc != RT_EOK) {
                g_system.step = SYSTEM_STEP_ERROR;
                break;
            }

            g_system.step++;
        } break;

        case SYSTEM_STEP_VERIFY_DOWNLOAD: {
            const struct fal_partition *app_part = g_system.app_part;
            const struct fal_partition *download_part = g_system.download_part;
            firm_pkg_t *download_header = &g_system.download_header;
            g_system.download_verify_rc = -RT_ERROR;

            int rc = check_part_firm(download_part, download_header);
            if (rc != RT_EOK) {
                LOG_E("Get OTA \"%s\" partition firmware filed!", download_part->name);
                g_system.step++;
            } else {
                if ((download_header->raw_size + sizeof(firm_pkg_t)) > app_part->len) {
                    LOG_E("The partition \'%s\' length is (%d), need (%d)!", app_part->name,
                          app_part->len, download_header->raw_size + sizeof(firm_pkg_t));

                    fal_partition_erase_all(download_part);
                    g_system.step++;
                    break;
                }

                g_system.download_verify_rc = RT_EOK;
                g_system.step = SYSTEM_STEP_UPDATE;
            }
        } break;

        /* SYSTEM_STEP_WAIT_SYNC
           SYSTEM_STEP_BOOT_PROCESS
           预留，可以作为强制停留在 Boot 功能
         */
        case SYSTEM_STEP_WAIT_SYNC:
            g_system.step++;
            break;

        case SYSTEM_STEP_BOOT_PROCESS:
            g_system.step++;
            break;

        case SYSTEM_STEP_UPDATE: {
            const struct fal_partition *app_part = g_system.app_part;
            const struct fal_partition *download_part = g_system.download_part;
            firm_pkg_t *download_header = &g_system.download_header;

            if (g_system.download_verify_rc == RT_EOK) {
                int rc = firm_upgrade(download_part, download_header, app_part);
                if (rc == RT_EOK) {
                    fal_partition_erase_all(download_part);
                    boot_app_enable();
                } else {
                    __disable_irq();
                    NVIC_SystemReset();
                }
            } else {
                firm_pkg_t app_header = {0};
                int rc = check_part_firm(app_part, &app_header);
                if (rc != RT_EOK) LOG_W("Force the %s partition to run!", app_part->name);

                boot_app_enable();
            }
        } break;

        case SYSTEM_STEP_ERROR:
            LOG_E("init error.");
            rt_thread_mdelay(1000);
            break;

        default:
            g_system.step = SYSTEM_STEP_ERROR;
            break;
    }
}
