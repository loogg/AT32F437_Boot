/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-03-28     shelton      first version
 */

#include <rtthread.h>
#include "at32f435_437.h"
#include "at32_msp.h"

#ifdef BSP_USING_UART
void at32_msp_usart_init(void *instance)
{
    gpio_init_type gpio_init_struct;
    usart_type *usart_x = (usart_type *)instance;

    gpio_default_para_init(&gpio_init_struct);
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
#ifdef BSP_USING_UART1
    if(usart_x == USART1)
    {
        crm_periph_clock_enable(CRM_USART1_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);

        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_9 | GPIO_PINS_10;
        gpio_init(GPIOA, &gpio_init_struct);

        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE9, GPIO_MUX_7);
        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE10, GPIO_MUX_7);
    }
#endif
#ifdef BSP_USING_UART2
    if(usart_x == USART2)
    {
        crm_periph_clock_enable(CRM_USART2_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);

        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_2 | GPIO_PINS_3;
        gpio_init(GPIOA, &gpio_init_struct);

        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE2, GPIO_MUX_7);
        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE3, GPIO_MUX_7);
    }
#endif
#ifdef BSP_USING_UART3
    if(usart_x == USART3)
    {
        crm_periph_clock_enable(CRM_USART3_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);

        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_10 | GPIO_PINS_11;
        gpio_init(GPIOB, &gpio_init_struct);

        gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE10, GPIO_MUX_7);
        gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE11, GPIO_MUX_7);
    }
#endif
#ifdef BSP_USING_UART6
    if(usart_x == USART6)
    {
        crm_periph_clock_enable(CRM_USART6_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);

        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_4 | GPIO_PINS_5;
        gpio_init(GPIOA, &gpio_init_struct);

        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE4, GPIO_MUX_8);
        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE5, GPIO_MUX_8);
    }
#endif
    /* add others */
}
#endif /* BSP_USING_SERIAL */

#ifdef BSP_USING_SPI
void at32_msp_spi_init(void *instance)
{
    gpio_init_type gpio_init_struct;
    spi_type *spi_x = (spi_type *)instance;

    gpio_default_para_init(&gpio_init_struct);
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
#ifdef BSP_USING_SPI1
    if(spi_x == SPI1)
    {
        crm_periph_clock_enable(CRM_SPI1_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);

        gpio_init_struct.gpio_mode = GPIO_MODE_OUTPUT;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_4;
        gpio_init(GPIOA, &gpio_init_struct);

        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_pins = GPIO_PINS_5 | GPIO_PINS_6 | GPIO_PINS_7;
        gpio_init(GPIOA, &gpio_init_struct);

        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE5, GPIO_MUX_5);
        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE6, GPIO_MUX_5);
        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE7, GPIO_MUX_5);
    }
#endif
#ifdef BSP_USING_SPI2
    if(spi_x == SPI2)
    {
        crm_periph_clock_enable(CRM_SPI2_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOD_PERIPH_CLOCK, TRUE);

        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_1 | GPIO_PINS_3 | GPIO_PINS_4;
        gpio_init(GPIOD, &gpio_init_struct);

        gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE1, GPIO_MUX_6);
        gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE3, GPIO_MUX_6);
        gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE4, GPIO_MUX_6);
    }
#endif
    /* add others */
}
#endif /* BSP_USING_SPI */

#ifdef BSP_USING_SDIO
void at32_msp_sdio_init(void *instance)
{
    gpio_init_type gpio_init_struct;
    sdio_type *sdio_x = (sdio_type *)instance;

    gpio_default_para_init(&gpio_init_struct);
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    if(sdio_x == SDIO1)
    {
        /* if used dma ... */
        crm_periph_clock_enable(CRM_DMA2_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_SDIO1_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOC_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOD_PERIPH_CLOCK, TRUE);

        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_8 | GPIO_PINS_9 | GPIO_PINS_10 | GPIO_PINS_11 | GPIO_PINS_12;
        gpio_init(GPIOC, &gpio_init_struct);

        gpio_pin_mux_config(GPIOC, GPIO_PINS_SOURCE8, GPIO_MUX_12);
        gpio_pin_mux_config(GPIOC, GPIO_PINS_SOURCE9, GPIO_MUX_12);
        gpio_pin_mux_config(GPIOC, GPIO_PINS_SOURCE10, GPIO_MUX_12);
        gpio_pin_mux_config(GPIOC, GPIO_PINS_SOURCE11, GPIO_MUX_12);
        gpio_pin_mux_config(GPIOC, GPIO_PINS_SOURCE12, GPIO_MUX_12);

        gpio_init_struct.gpio_pins = GPIO_PINS_2;
        gpio_init(GPIOD, &gpio_init_struct);

        gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE2, GPIO_MUX_12);
    }
}
#endif /* BSP_USING_SDIO */

#ifdef BSP_USING_PWM
void at32_msp_tmr_init(void *instance)
{
    gpio_init_type gpio_init_struct;
    tmr_type *tmr_x = (tmr_type *)instance;

    gpio_default_para_init(&gpio_init_struct);
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    if(tmr_x == TMR1)
    {
        /* tmr1 clock enable */
        crm_periph_clock_enable(CRM_TMR1_PERIPH_CLOCK, TRUE);
        /* gpioa clock enable */
        crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);

        /* gpioa configuration: tmr1 channel1 and channel4 as alternate function push-pull */
        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_8 | GPIO_PINS_11;
        gpio_init(GPIOA, &gpio_init_struct);

        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE8, GPIO_MUX_1);
        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE11, GPIO_MUX_1);
    }

    if(tmr_x == TMR2)
    {
        /* tmr2 clock enable */
        crm_periph_clock_enable(CRM_TMR2_PERIPH_CLOCK, TRUE);
        /* gpioa clock enable */
        crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);

        /* gpioa configuration: tmr1 channel1 and channel2 as alternate function push-pull */
        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_0 | GPIO_PINS_1;
        gpio_init(GPIOA, &gpio_init_struct);

        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE0, GPIO_MUX_1);
        gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE1, GPIO_MUX_1);
    }
    /* add others */
}
#endif /* BSP_USING_PWM */

#ifdef BSP_USING_ADC
void at32_msp_adc_init(void *instance)
{
    gpio_init_type gpio_init_struct;
    adc_type *adc_x = (adc_type *)instance;

    gpio_default_para_init(&gpio_init_struct);
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
#ifdef BSP_USING_ADC1
    if(adc_x == ADC1)
    {
        /* adc1 & gpio clock enable */
        crm_periph_clock_enable(CRM_ADC1_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOC_PERIPH_CLOCK, TRUE);

        /* configure adc channel as analog input */
        gpio_init_struct.gpio_pins = GPIO_PINS_0 | GPIO_PINS_1 | GPIO_PINS_2 | GPIO_PINS_3 | GPIO_PINS_4 | GPIO_PINS_5;
        gpio_init_struct.gpio_mode = GPIO_MODE_ANALOG;
        gpio_init(GPIOC, &gpio_init_struct);
    }
#endif

#ifdef BSP_USING_ADC2
    if(adc_x == ADC2)
    {
        /* adc2 & gpio clock enable */
        crm_periph_clock_enable(CRM_ADC2_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOC_PERIPH_CLOCK, TRUE);

        /* configure adc channel as analog input */
        gpio_init_struct.gpio_pins = GPIO_PINS_0 | GPIO_PINS_1 | GPIO_PINS_2 | GPIO_PINS_3 | GPIO_PINS_4 | GPIO_PINS_5;
        gpio_init_struct.gpio_mode = GPIO_MODE_ANALOG;
        gpio_init(GPIOC, &gpio_init_struct);
    }
#endif
}
#endif /* BSP_USING_ADC */

#ifdef BSP_USING_HWTIMER
void at32_msp_hwtmr_init(void *instance)
{
    tmr_type *tmr_x = (tmr_type *)instance;

#ifdef BSP_USING_HWTMR3
    if(tmr_x == TMR3)
    {
        /* tmr3 clock enable */
        crm_periph_clock_enable(CRM_TMR3_PERIPH_CLOCK, TRUE);
    }
#endif

#ifdef BSP_USING_HWTMR4
    if(tmr_x == TMR4)
    {
        /* tmr4 clock enable */
        crm_periph_clock_enable(CRM_TMR4_PERIPH_CLOCK, TRUE);
    }
#endif

#ifdef BSP_USING_HWTMR5
    if(tmr_x == TMR5)
    {
        /* tmr5 clock enable */
        crm_periph_clock_enable(CRM_TMR5_PERIPH_CLOCK, TRUE);
    }
#endif
}
#endif

#ifdef BSP_USING_CAN
void at32_msp_can_init(void *instance)
{
    gpio_init_type gpio_init_struct;
    can_type *can_x = (can_type *)instance;

    gpio_default_para_init(&gpio_init_struct);
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
#ifdef BSP_USING_CAN1
    if(can_x == CAN1)
    {
        crm_periph_clock_enable(CRM_CAN1_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);

        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_8 | GPIO_PINS_9;
        gpio_init(GPIOB, &gpio_init_struct);

        gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE8, GPIO_MUX_9);
        gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE9, GPIO_MUX_9);
    }
#endif
#ifdef BSP_USING_CAN2
    if(can_x == CAN2)
    {
        crm_periph_clock_enable(CRM_CAN2_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);

        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_5 | GPIO_PINS_6;
        gpio_init(GPIOB, &gpio_init_struct);

        gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE5, GPIO_MUX_9);
        gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE6, GPIO_MUX_9);
    }
#endif
}
#endif /* BSP_USING_CAN */

#ifdef BSP_USING_EMAC
void at32_msp_emac_init(void *instance)
{
    gpio_init_type gpio_init_struct;

    crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOC_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOD_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOG_PERIPH_CLOCK, TRUE);

    gpio_default_para_init(&gpio_init_struct);
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
    gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
    gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
    gpio_init_struct.gpio_pins = GPIO_PINS_1 | GPIO_PINS_2;
    gpio_init(GPIOA, &gpio_init_struct);

    gpio_init_struct.gpio_pins = GPIO_PINS_1;
    gpio_init(GPIOC, &gpio_init_struct);

    gpio_init_struct.gpio_pins = GPIO_PINS_8 | GPIO_PINS_9 | GPIO_PINS_10;
    gpio_init(GPIOD, &gpio_init_struct);

    gpio_init_struct.gpio_pins = GPIO_PINS_11 | GPIO_PINS_13 | GPIO_PINS_14;
    gpio_init(GPIOG, &gpio_init_struct);

    gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE1, GPIO_MUX_11);
    gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE2, GPIO_MUX_11);
    gpio_pin_mux_config(GPIOC, GPIO_PINS_SOURCE1, GPIO_MUX_11);
    gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE8, GPIO_MUX_11);
    gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE9, GPIO_MUX_11);
    gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE10, GPIO_MUX_11);
    gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE11, GPIO_MUX_11);
    gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE13, GPIO_MUX_11);
    gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE14, GPIO_MUX_11);
}
#endif /* BSP_USING_EMAC */

#ifdef BSP_USING_QSPI
void at32_msp_qspi_init(void *instance)
{
    gpio_init_type gpio_init_struct;
    qspi_type *qspi_x = (qspi_type *)instance;

    gpio_default_para_init(&gpio_init_struct);
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
#ifdef BSP_USING_QSPI1
    if(qspi_x == QSPI1)
    {
        crm_periph_clock_enable(CRM_QSPI1_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOF_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOG_PERIPH_CLOCK, TRUE);

        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_6 | GPIO_PINS_7 | GPIO_PINS_8 | GPIO_PINS_9 | GPIO_PINS_10;
        gpio_init(GPIOF, &gpio_init_struct);

        gpio_init_struct.gpio_pins = GPIO_PINS_6;
        gpio_init(GPIOG, &gpio_init_struct);

        gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE6, GPIO_MUX_9);
        gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE7, GPIO_MUX_9);
        gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE8, GPIO_MUX_10);
        gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE9, GPIO_MUX_10);
        gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE10, GPIO_MUX_9);
        gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE6, GPIO_MUX_10);
    }
#endif
#ifdef BSP_USING_QSPI2
    if(qspi_x == QSPI2)
    {
        crm_periph_clock_enable(CRM_QSPI2_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOE_PERIPH_CLOCK, TRUE);
        crm_periph_clock_enable(CRM_GPIOG_PERIPH_CLOCK, TRUE);

        gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
        gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
        gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
        gpio_init_struct.gpio_pins = GPIO_PINS_7 | GPIO_PINS_8 | GPIO_PINS_9 | GPIO_PINS_10;
        gpio_init(GPIOE, &gpio_init_struct);

        gpio_init_struct.gpio_pins = GPIO_PINS_8 | GPIO_PINS_13;
        gpio_init(GPIOG, &gpio_init_struct);

        gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE7, GPIO_MUX_10);
        gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE8, GPIO_MUX_10);
        gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE9, GPIO_MUX_10);
        gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE10, GPIO_MUX_10);
        gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE8, GPIO_MUX_5);
        gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE13, GPIO_MUX_5);
    }
#endif
}
#endif /* BSP_USING_QSPI */

#ifdef BSP_USING_SDRAM
void at32_msp_sdram_init(void *instance)
{
    gpio_init_type gpio_init_struct;

    gpio_default_para_init(&gpio_init_struct);

    /* enable the gpio clock */
    crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOC_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOD_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOE_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOF_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOG_PERIPH_CLOCK, TRUE);

    /* enable the xmc clock */
    crm_periph_clock_enable(CRM_XMC_PERIPH_CLOCK, TRUE);

    /* address lines configuration */
    gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
    gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
    gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;

    gpio_init_struct.gpio_pins = GPIO_PINS_5 | GPIO_PINS_6;
    gpio_init(GPIOB, &gpio_init_struct);

    gpio_init_struct.gpio_pins = GPIO_PINS_0 | GPIO_PINS_2 | GPIO_PINS_3;
    gpio_init(GPIOC, &gpio_init_struct);

    gpio_init_struct.gpio_pins = GPIO_PINS_0 | GPIO_PINS_1 | GPIO_PINS_8 | GPIO_PINS_9 | GPIO_PINS_10 | GPIO_PINS_14 | GPIO_PINS_15;
    gpio_init(GPIOD, &gpio_init_struct);

    gpio_init_struct.gpio_pins = GPIO_PINS_0 | GPIO_PINS_1 | GPIO_PINS_7 | GPIO_PINS_8 | GPIO_PINS_10 |
                                 GPIO_PINS_9 | GPIO_PINS_11 | GPIO_PINS_11 | GPIO_PINS_12 |
                                 GPIO_PINS_13 | GPIO_PINS_14 | GPIO_PINS_15;
    gpio_init(GPIOE, &gpio_init_struct);

    gpio_init_struct.gpio_pins = GPIO_PINS_0 | GPIO_PINS_1 | GPIO_PINS_2 | GPIO_PINS_3 |
                                 GPIO_PINS_4 | GPIO_PINS_5 | GPIO_PINS_11 | GPIO_PINS_12 |
                                 GPIO_PINS_13 | GPIO_PINS_14 | GPIO_PINS_15;
    gpio_init(GPIOF, &gpio_init_struct);

    gpio_init_struct.gpio_pins = GPIO_PINS_0 | GPIO_PINS_1 | GPIO_PINS_2 | GPIO_PINS_4 |
                                 GPIO_PINS_5 | GPIO_PINS_8 | GPIO_PINS_15;
    gpio_init(GPIOG, &gpio_init_struct);

    /* gpio mux configuration */
    gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE5, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE6, GPIO_MUX_12);

    gpio_pin_mux_config(GPIOC, GPIO_PINS_SOURCE0, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOC, GPIO_PINS_SOURCE2, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOC, GPIO_PINS_SOURCE3, GPIO_MUX_12);

    gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE0, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE1, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE8, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE9, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE10, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE14, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOD, GPIO_PINS_SOURCE15, GPIO_MUX_12);

    gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE0, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE1, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE7, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE8, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE9, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE10, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE11, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE12, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE13, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE14, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOE, GPIO_PINS_SOURCE15, GPIO_MUX_12);

    gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE0, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE1, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE2, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE3, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE4, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE5, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE11, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE12, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE13, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE14, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOF, GPIO_PINS_SOURCE15, GPIO_MUX_12);

    gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE0, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE1, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE2, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE4, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE5, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE8, GPIO_MUX_12);
    gpio_pin_mux_config(GPIOG, GPIO_PINS_SOURCE15, GPIO_MUX_12);
}

#endif /* BSP_USING_SDRAM */
