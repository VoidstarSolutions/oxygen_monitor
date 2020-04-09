#include "unity.h"
#include "cmock.h"

#include "main.h"
#include "mock_system_samc21.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_LED_Init_should_set_pin_dir(void)
{
    SystemInit_Expect();

    TEST_ASSERT_EQUAL(0, testable_main());
}