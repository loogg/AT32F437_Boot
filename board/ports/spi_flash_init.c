/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-27     SummerGift   add spi flash port file
 */

#include <rtthread.h>
#include "spi_flash.h"
#include "spi_flash_sfud.h"
#include "drv_spi.h"

#if defined(BSP_USING_SPI_FLASH)

int rt_hw_spi_flash_init(void) {
    crm_periph_clock_enable(CRM_GPIOD_PERIPH_CLOCK, TRUE);
    rt_hw_spi_device_attach("spi2", "spi20", GPIOD, GPIO_PINS_0);

    if (RT_NULL == rt_sfud_flash_probe(FAL_USING_NOR_FLASH_DEV_NAME, "spi20")) {
        return -RT_ERROR;
    }

    return RT_EOK;
}

#endif
