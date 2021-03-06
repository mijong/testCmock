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
#include "TemperatureCalculator.h"
#include <math.h>

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void testTemperatureCalculatorShouldCalculateTemperatureFromMillivolts(void);
extern void testShouldReturnNegativeInfinityWhen_0_millivoltsInput(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test/TestTemperatureCalculator.c";
  UnityBegin();
  RUN_TEST(testTemperatureCalculatorShouldCalculateTemperatureFromMillivolts, 14);
  RUN_TEST(testShouldReturnNegativeInfinityWhen_0_millivoltsInput, 30);

  return (UnityEnd());
}
