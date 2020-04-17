/*
 * task_startup.c
 *
 * Created: 04/12/20
 * Author : Zachary Heylmun
 */
#include "sdadc.h"

#include "mock_hal_adc_async.h"

struct adc_async_descriptor         ADC_0;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_vConfigureAndEnableSDADC_ShouldConfigureAndStartSDADCConversion(void) {
    adc_async_register_callback_ExpectAndReturn(&ADC_0, 0, ADC_ASYNC_CONVERT_CB, vSDADCConversionCallback,  0);
    adc_async_enable_channel_ExpectAndReturn(&ADC_0, 0,0);
}