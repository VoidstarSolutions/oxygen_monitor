/*
 * sdadc.c
 *
 * Created: 04/12/20
 * Author : Zachary Heylmun
 */

#include "sdadc_task.h"

#include "atmel_start.h"

static void prvConversionCallback(const struct adc_async_descriptor *const descr, const uint8_t channel);

void vSDADCTaskStart(void)
{
	adc_async_register_callback(&ADC_0, 0, ADC_ASYNC_CONVERT_CB, prvConversionCallback);
	adc_async_enable_channel(&ADC_0, 0);
	adc_async_start_conversion(&ADC_0);
}

static void prvConversionCallback(const struct adc_async_descriptor *const descr, const uint8_t channel) {}