#include "cmock.h"
#include "unity.h"

#include "sdadc_task.h"

#include "mock_osapi.h"
#include "mock_atmel_start.h"
#include "mock_driver_init.h"
#include "mock_hal_adc_async.h"

struct adc_async_descriptor ADC_0;

void setUp(void) {}

void tearDown(void) {}

void test_vSDADCTaskStart_ShouldConfigureSDADC(void) {
    
}