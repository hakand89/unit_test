/*
 * main.c
 *
 *  Created on: 2020 Apr 08 13:26:01
 *  Author: hakan
 */



#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)


uint32_t start, stop;

double us=0, ms=0;

uint32_t multiply(uint32_t res);

uint32_t arr1[]= {15200, 21100,32200};

uint32_t arr2[]= {1, 2,3};

#include "BM_Unit_Test.h"

BM_UNIT_TEST_t TEST;
int main(void)
{

	   TEST.FUNCTION1= &multiply;
	   TEST.TYPE=LOOP;  //LOOP
	   TEST.LOOPCOUNT=400;  // 400'den sonrası taşıyor, birden fazla sonuç array i ayarlamak lazım
	   TEST.MAXVALUE_UNSIGNED=65535;
	   TEST.MINVALUE_UNSIGNED=10000;

	   Unit_Test_Start(&TEST);


  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */


  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  while(1U)
  {

  }
}

 uint32_t multiply(uint32_t res){
 uint32_t result;

 result=arr1[1]*2;

 return result;
 }
