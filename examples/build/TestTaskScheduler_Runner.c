/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include "Types.h"
#include <setjmp.h>
#include <stdio.h>
#include "Types.h"
#include "TaskScheduler.h"

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void testShouldScheduleUsartTaskAfter1000ms(void);
extern void testShouldClearUsartDoFlagAfterReported(void);
extern void testShouldScheduleUsartTaskEvery1000ms(void);
extern void testShouldScheduleUsartTaskOnlyOncePerPeriod(void);
extern void testShouldScheduleAdcTaskAfter100ms(void);
extern void testShouldClearAdcDoFlagAfterReported(void);
extern void testShouldScheduleAdcTaskEvery100ms(void);
extern void testShouldScheduleAdcTaskOnlyOncePerPeriod(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test/TestTaskScheduler.c";
  UnityBegin();
  RUN_TEST(testShouldScheduleUsartTaskAfter1000ms, 14);
  RUN_TEST(testShouldClearUsartDoFlagAfterReported, 25);
  RUN_TEST(testShouldScheduleUsartTaskEvery1000ms, 33);
  RUN_TEST(testShouldScheduleUsartTaskOnlyOncePerPeriod, 47);
  RUN_TEST(testShouldScheduleAdcTaskAfter100ms, 60);
  RUN_TEST(testShouldClearAdcDoFlagAfterReported, 71);
  RUN_TEST(testShouldScheduleAdcTaskEvery100ms, 79);
  RUN_TEST(testShouldScheduleAdcTaskOnlyOncePerPeriod, 93);

  return (UnityEnd());
}
