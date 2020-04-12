#include "cmock.h"
#include "unity.h"

#include "task_startup.h"

void setUp(void)
{
}

void tearDown(void)
{
}
/*
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
                                   StackType_t **ppxIdleTaskStackBuffer,
                                   uint32_t *pulIdleTaskStackSize);
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer,
                                    StackType_t **ppxTimerTaskStackBuffer,
                                    uint32_t *pulTimerTaskStackSize);*/
void test_vApplicationGetIdleTaskMemory_ShouldReturnValidMemory(void)
{
    StaticTask_t *pTask = NULL;
    StackType_t *pStack = NULL;
    uint32_t stackSize = 0;
    vApplicationGetIdleTaskMemory(&pTask,
                                  &pStack,
                                  &stackSize);
    TEST_ASSERT_NOT_NULL(pTask);
    TEST_ASSERT_NOT_NULL(pStack);
    TEST_ASSERT_EQUAL(configMINIMAL_STACK_SIZE, stackSize);
}