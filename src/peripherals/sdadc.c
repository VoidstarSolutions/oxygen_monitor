/*
 * sdadc.c
 *
 * Created: 04/12/20
 * Author : Zachary Heylmun
 */
#include "sdadc.h"

#include "atmel_start.h"

#define UX_SDADC_CONVERSION_BUFFER_SIZE ((uint16_t) 64)

static uint8_t xConversionBuffer[UX_SDADC_CONVERSION_BUFFER_SIZE];

void vConfigureAndEnableSDADC(void)
{
	adc_async_register_callback(&ADC_0, 0, ADC_ASYNC_CONVERT_CB, vSDADCConversionCallback);
	adc_async_enable_channel(&ADC_0, 0);
	adc_async_start_conversion(&ADC_0);
}

void vSDADCConversionCallback(const struct adc_async_descriptor *const descr, const uint8_t channel)
{
	if (descr != &ADC_0)
	{
		return;
	}

	adc_async_read_channel(&ADC_0, 0, xConversionBuffer, UX_SDADC_CONVERSION_BUFFER_SIZE);
}