# SDADC Usage Summary

## Initialization:
* Enable Generic Clock
* Select VREF
* Set Sampling Frequency (GCLK / Prescaler = CLK_SDADC)
* Configure input MUX
* Configure Interrupts
* Trigger to start conversion(s)
## Reading Results:
* Skip at least the first three conversions
* Start conversion(s)
* Wait for RESRDY flag
* Read Result and right shift in application or in hardware via SHIFTCORR