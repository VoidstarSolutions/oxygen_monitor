/*
 * sdadc.h
 *
 * Created: 04/12/20
 * Author : Zachary Heylmun
 */
#ifndef SDADC_H
#define SDADC_H
#include <stdint.h>
#include "hal_adc_async.h"
void vConfigureAndEnableSDADC( void );
void vSDADCConversionCallback( const struct adc_async_descriptor *const descr, const uint8_t channel );
#endif //SDADC_H