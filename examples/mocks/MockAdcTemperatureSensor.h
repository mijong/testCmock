/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCKADCTEMPERATURESENSOR_H
#define _MOCKADCTEMPERATURESENSOR_H

#include "Types.h"
#include "AdcTemperatureSensor.h"

void MockAdcTemperatureSensor_Init(void);
void MockAdcTemperatureSensor_Destroy(void);
void MockAdcTemperatureSensor_Verify(void);




#define Adc_StartTemperatureSensorConversion_Expect() Adc_StartTemperatureSensorConversion_CMockExpect(__LINE__)
void Adc_StartTemperatureSensorConversion_CMockExpect(UNITY_LINE_TYPE cmock_line);
#define Adc_TemperatureSensorSampleReady_ExpectAndReturn(cmock_retval) Adc_TemperatureSensorSampleReady_CMockExpectAndReturn(__LINE__, cmock_retval)
void Adc_TemperatureSensorSampleReady_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, bool cmock_to_return);
#define Adc_ReadTemperatureSensor_ExpectAndReturn(cmock_retval) Adc_ReadTemperatureSensor_CMockExpectAndReturn(__LINE__, cmock_retval)
void Adc_ReadTemperatureSensor_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint16 cmock_to_return);

#endif