/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

#include <hpl_sdadc_base.h>

/* The channel amount for ADC */
#define ADC_0_CH_AMOUNT 1

/* The buffer size for ADC */
#define ADC_0_BUFFER_SIZE 16

/* The maximal channel number of enabled channels */
#define ADC_0_CH_MAX 0

struct crc_sync_descriptor          CRC_0;
struct can_async_descriptor         CAN_0;
struct adc_async_descriptor         ADC_0;
struct adc_async_channel_descriptor ADC_0_ch[ADC_0_CH_AMOUNT];

static uint8_t ADC_0_buffer[ADC_0_BUFFER_SIZE];
static uint8_t ADC_0_map[ADC_0_CH_MAX + 1];

struct wdt_descriptor WDT_0;

/**
 * \brief CRC initialization function
 *
 * Enables CRC peripheral, clocks and initializes CRC driver
 */
void CRC_0_init(void)
{
	hri_mclk_set_APBBMASK_DSU_bit(MCLK);
	crc_sync_init(&CRC_0, DSU);
}

void delay_driver_init(void)
{
	delay_init(SysTick);
}

void WDT_0_CLOCK_init(void)
{
	hri_mclk_set_APBAMASK_WDT_bit(MCLK);
}

void WDT_0_init(void)
{
	WDT_0_CLOCK_init();
	wdt_init(&WDT_0, WDT);
}

void CAN_0_PORT_init(void)
{

	gpio_set_pin_function(CAN_RX, PINMUX_PA25G_CAN0_RX);

	gpio_set_pin_function(CAN_TX, PINMUX_PA24G_CAN0_TX);
}
/**
 * \brief CAN initialization function
 *
 * Enables CAN peripheral, clocks and initializes CAN driver
 */
void CAN_0_init(void)
{
	hri_mclk_set_AHBMASK_CAN0_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, CAN0_GCLK_ID, CONF_GCLK_CAN0_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	can_async_init(&CAN_0, CAN0);
	CAN_0_PORT_init();
}

/**
 * \brief ADC initialization function
 *
 * Enables ADC peripheral, clocks and initializes ADC driver
 */
static void ADC_0_init(void)
{
	hri_mclk_set_APBCMASK_SDADC_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, SDADC_GCLK_ID, CONF_GCLK_SDADC_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));

	adc_async_init(&ADC_0, SDADC, ADC_0_map, ADC_0_CH_MAX, ADC_0_CH_AMOUNT, &ADC_0_ch[0], _sdadc_get_adc_async());
	adc_async_register_channel_buffer(&ADC_0, 0, ADC_0_buffer, ADC_0_BUFFER_SIZE);
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA06

	// Disable digital pin circuitry
	gpio_set_pin_direction(SENSOR_N, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(SENSOR_N, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA07

	// Disable digital pin circuitry
	gpio_set_pin_direction(SENSOR_P, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(SENSOR_P, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA08

	gpio_set_pin_level(CAN_EN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(CAN_EN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(CAN_EN, GPIO_PIN_FUNCTION_OFF);

	// GPIO on RESET_N

	gpio_set_pin_direction(SAM_RESET_N,
	                       // <y> Pin direction
	                       // <id> pad_direction
	                       // <GPIO_DIRECTION_OFF"> Off
	                       // <GPIO_DIRECTION_IN"> In
	                       // <GPIO_DIRECTION_OUT"> Out
	                       GPIO_DIRECTION_OUT);

	gpio_set_pin_level(SAM_RESET_N,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_pull_mode(SAM_RESET_N,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(SAM_RESET_N,
	                      // <y> Pin function
	                      // <id> pad_function
	                      // <i> Auto : use driver pinmux if signal is imported by driver, else turn off function
	                      // <GPIO_PIN_FUNCTION_OFF"> Auto
	                      // <GPIO_PIN_FUNCTION_OFF"> Off
	                      // <GPIO_PIN_FUNCTION_A"> A
	                      // <GPIO_PIN_FUNCTION_B"> B
	                      // <GPIO_PIN_FUNCTION_C"> C
	                      // <GPIO_PIN_FUNCTION_D"> D
	                      // <GPIO_PIN_FUNCTION_E"> E
	                      // <GPIO_PIN_FUNCTION_F"> F
	                      // <GPIO_PIN_FUNCTION_G"> G
	                      // <GPIO_PIN_FUNCTION_H"> H
	                      // <GPIO_PIN_FUNCTION_I"> I
	                      GPIO_PIN_FUNCTION_OFF);

	CRC_0_init();

	delay_driver_init();

	WDT_0_init();
	CAN_0_init();
	ADC_0_init();
}
