
/*
 * bm_unit_test.h
 *
 *  Created on: 09/04/2020
 *      Author: OEC & HD
 */
#ifndef BM_UNIT_TEST_H_
#define BM_UNIT_TEST_H_

/*********************************
 *         Includes
 ***********************************/

#include "stdint.h"

typedef enum{
	LOOP,
	PERIODIC
}Type_t;

typedef struct {
	uint32_t Test_Done;
	uint32_t Max_Result_Value_UNSIGNED;
	int32_t  Max_Result_Value_SIGNED;
	uint32_t Min_Result_Value_UNSIGNED;
	int32_t  Min_Result_Value_SIGNED;
	double   Max_Execution_Time_us;
	double   Min_Execution_Time_us;
	double   Max_Execution_Time_ms;
	double   Min_Execution_Time_ms;
	uint32_t Max_Time_Instance;
	uint32_t Min_Time_Instance;

}BM_UNIT_TEST_RESULT_t;


typedef struct {
	uint32_t boundarray[65534];
	uint32_t Max_VALUE_UNSIGNED;
	int32_t  Max_VALUE_SIGNED;
	uint32_t Min_VALUE_UNSIGNED;
	int32_t  Min_VALUE_SIGNED;
	double   Max_Execution_Time;
	double   Min_Execution_Time;
}BM_UNIT_TEST_OUTOFBOUNDRY_t;


typedef struct {

}BM_UNIT_TEST_FAULT_t;

typedef struct {
void *FUNCTION1;
void *FUNCTION2;
void *FUNCTION3;
void *FUNCTION4;
void *FUNCTION5;
Type_t  TYPE;
uint32_t LOOPCOUNT;
int32_t     MAXVALUE_SIGNED;
uint32_t    MAXVALUE_UNSIGNED;
int32_t     MINVALUE_SIGNED;
uint32_t    MINVALUE_UNSIGNED;
BM_UNIT_TEST_RESULT_t RESULT;
BM_UNIT_TEST_FAULT_t  FAULT;
}BM_UNIT_TEST_t;



extern void Unit_Test_Start(BM_UNIT_TEST_t *ptr);


#endif
























