#ifndef __COMMON_H
#define __COMMON_H
#include <fal.h>

#define BOOT_BKP           ERTC_DT15
#define BOOT_APP_ADDR      0x08010000UL
#define APP_PART_NAME      "app"
#define DOWNLOAD_PART_NAME "download"

typedef struct {
    char type[4];
    uint16_t algo;
    uint16_t algo2;
    uint32_t time_stamp;
    char app_part_name[16];
    char version_name[24];
    char res[24];
    uint32_t body_crc32;
    uint32_t hash_code;
    uint32_t raw_size;
    uint32_t pkg_size;
    uint32_t hdr_crc32;
} __attribute__((packed)) firm_pkg_t;

enum {
    SYSTEM_STEP_INIT = 0,
    SYSTEM_STEP_VERIFY_DOWNLOAD,
    SYSTEM_STEP_WAIT_SYNC,
    SYSTEM_STEP_BOOT_PROCESS,
    SYSTEM_STEP_UPDATE,
    SYSTEM_STEP_ERROR
};

typedef struct {
    const struct fal_partition *app_part;
    const struct fal_partition *download_part;
    firm_pkg_t download_header;
    int download_verify_rc;
    int step;
} g_system_t;
extern g_system_t g_system;

#endif
