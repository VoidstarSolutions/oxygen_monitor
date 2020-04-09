#include "unity.h"
#include "cmock.h"

#include "main.h"
#include "mock_system_samc21.h"
#include "mock_task.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_main_should_init_system(void)
{
    SystemInit_Expect();
    vTaskStartScheduler_Expect();
    TEST_ASSERT_EQUAL(0, testable_main());
}