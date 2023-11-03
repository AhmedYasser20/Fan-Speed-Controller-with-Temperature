#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
typedef enum {
	ref_volt,AVCC_volt,Internal_volt_2_56=3
}ADC_ReferenceVolatge;

typedef enum {
	Prescaler_2=1,Prescaler_4,Prescaler_8,Prescaler_16,Prescaler_32,Prescaler_64,Prescaler_128
}ADC_Prescaler;

typedef struct{
  ADC_ReferenceVolatge ref_volt;
  ADC_Prescaler prescaler;
}ADC_ConfigType;
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
