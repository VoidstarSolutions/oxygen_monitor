#include "cmock.h"
#include "unity.h"

#include "task_startup.h"
#include "mock_can_task.h"
#include "mock_sdadc_task.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_vApplicationGetIdleTaskMemory_ShouldReturnValidMemory(void)
{
    StaticTask_t *pTask = NULL;
    StackType_t *pStack = NULL;
    uint32_t stackSize = 0;
    vApplicationGetIdleTaskMemory(&pTask,
                                  &pStack,
                                  &stackSize);
    // Expect the task memory pointer has been initialized
    TEST_ASSERT_NOT_NULL(pTask);
    // Expect the stack memory pointer to be initialized
    TEST_ASSERT_NOT_NULL(pStack);
    // The stack should be set to the minimum stack size configured
    TEST_ASSERT_EQUAL(configMINIMAL_STACK_SIZE, stackSize);
}

void test_vApplicationGetTimerTaskMemory_ShouldReturnValidMemory(void)
{
    StaticTask_t *pTask = NULL;
    StackType_t *pStack = NULL;
    uint32_t stackSize = 0;
    vApplicationGetTimerTaskMemory(&pTask,
                                   &pStack,
                                   &stackSize);
    // Expect the task memory pointer has been initialized
    TEST_ASSERT_NOT_NULL(pTask);
    // Expect the stack memory pointer to be initialized
    TEST_ASSERT_NOT_NULL(pStack);
    // The stack should be set to the minimum stack size configured
    TEST_ASSERT_EQUAL(configMINIMAL_STACK_SIZE, stackSize);
}

void test_vStartAllTheTasks(void)
{
    vCANTaskStart_Expect();
    TEST_ASSERT_EQUAL(0, vStartAllTheTasks());
}