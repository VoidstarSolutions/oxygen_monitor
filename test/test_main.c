#include "unity.h"
#include "cmock.h"

#include "main.h"
#include "mock_atmel_start.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_main_should_init_system(void)
{
    atmel_start_init_Expect();
    TEST_ASSERT_EQUAL(0, testable_main());
}