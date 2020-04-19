

#include "BM_Unit_Test.h"

//#include "core_cm4.h"
#include "xmc4400.h"



uint32_t start, stop;

//double us  =0, ms=0;

double time_array_ms[400];
double time_array_us[400];

double max_time_us=0,min_time_us=0,max_time_ms=0,min_time_ms=0;

int y=0;

void Unit_Test_Start(BM_UNIT_TEST_t *ptr){

	// Core registerlarında Trace Enable işlemi.
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

	// Dwt reset ve enable ayarı
	DWT->CYCCNT = 0;

	DWT->CTRL = DWT_CTRL_CYCCNTENA_Msk;

if( ptr->FUNCTION1){  // function1 will be executed

	if(ptr->MAXVALUE_SIGNED){
	int32_t max_limit=ptr->MAXVALUE_UNSIGNED;
	int32_t result[(int32_t)(ptr->LOOPCOUNT)];
	}
	if(ptr->MAXVALUE_UNSIGNED){
		uint32_t max_limit=ptr->MAXVALUE_UNSIGNED;
		uint32_t result[(uint32_t)(ptr->LOOPCOUNT)];
		}
	if(ptr->MINVALUE_SIGNED){
	int32_t min_limit=ptr->MINVALUE_SIGNED;
	}
	if(ptr->MINVALUE_UNSIGNED){
		uint32_t min_limit=ptr->MINVALUE_SIGNED;
		}


	if(PERIODIC == (ptr->TYPE)){
		y=y+1;
	}

	if(LOOP == (ptr->TYPE)){
	uint32_t loopcounter;

	uint32_t result[(uint32_t)(ptr->LOOPCOUNT)];


	for(loopcounter = (uint32_t)0; loopcounter < (uint32_t)(ptr->LOOPCOUNT); loopcounter++){
		result[loopcounter]=(uint32_t)0;
	}

	for(loopcounter = (uint32_t)0; loopcounter < (uint32_t)(ptr->LOOPCOUNT); loopcounter++){

		 start = DWT->CYCCNT;

		 result[loopcounter]=(uint32_t)(ptr->FUNCTION1);

         stop = DWT->CYCCNT;

        time_array_us[loopcounter] = (double)(stop - start) / (double)(SystemCoreClock);
        time_array_ms[loopcounter] = (double)(stop - start) / (double)(SystemCoreClock/1000);


        // Max Time    //
        if((time_array_us[loopcounter])> (max_time_us)){
        	max_time_us=time_array_us[loopcounter];
        }

        if((time_array_ms[loopcounter])> (max_time_ms)){
        	max_time_ms=time_array_ms[loopcounter];
        	ptr->RESULT.Max_Time_Instance=loopcounter;

                }

        // Min Time     //
          // Initialise min to first result
             if(!loopcounter){
            	 min_time_us=time_array_us[loopcounter];
                 min_time_ms=time_array_ms[loopcounter];
             }

             if((time_array_us[loopcounter])< (min_time_us)){
            	 	 	 min_time_us=time_array_us[loopcounter];
                    }

             if((time_array_ms[loopcounter])< (min_time_ms)){
            	 min_time_ms=time_array_ms[loopcounter];
                 ptr->RESULT.Min_Time_Instance=loopcounter;

                            }

        // Check Faults //



	}
}

}

ptr->RESULT.Max_Execution_Time_ms=(double)(max_time_ms);
ptr->RESULT.Max_Execution_Time_us=(double)(max_time_us);
ptr->RESULT.Min_Execution_Time_us=(double)(min_time_us);
ptr->RESULT.Min_Execution_Time_ms=(double)(min_time_ms);
//ptr->RESULT->Max_Execution_Time_us = max_time_us;
//ptr->RESULT->Max_Execution_Time_ms = max_time_ms;

//ptr->RESULT->Min_Execution_Time_us =
//ptr->RESULT->Min_Execution_Time_ms =
}
