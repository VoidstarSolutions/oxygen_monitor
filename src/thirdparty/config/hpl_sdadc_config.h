/* Auto-generated config file hpl_sdadc_config.h */
#ifndef HPL_SDADC_CONFIG_H
#define HPL_SDADC_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#ifndef CONF_SDADC_ENABLE
#define CONF_SDADC_ENABLE 1
#endif

// <h> Basic Configuration

// <o> Reference Range
// <0x0=>Vref < 1.4V
// <0x1=>1.4V < Vref < 2.4V
// <0x2=>2.4V < Vref < 3.6V
// <0x3=>Vref > 3.6V
// <i> Select the reference range for the ADC (REFRANGE)
// <id> sdadc_refrange
#ifndef CONF_SDADC_REFRANGE
#define CONF_SDADC_REFRANGE 0x0
#endif

// <o> Reference Selection
// <0x0=>Internal bandgap reference
// <0x1=>VREFB pin (External 1-5.5V)
// <0x2=>DAC output (Internal 1-5.5V)
// <0x3=>VDDANA (Supply 2.7-5.5V)
// <i> Select the reference for the ADC (REFSEL)
// <id> sdadc_reference
#ifndef CONF_SDADC_REFSEL
#define CONF_SDADC_REFSEL 0x0
#endif

// <q> Reference Buffer
// <i> When enabled, the impedance seen on the external reference increases, so that the current load reduces from 5uA to 0.10uA (ONREFBUF)
// <id> sdadc_onrefbuf
#ifndef CONF_SDADC_ONREFBUF
#define CONF_SDADC_ONREFBUF 0x0
#endif

// <o> Prescaler configuration <0-255>
// <i> These bits define the ADC clock relative to the peripheral clock (PRESCALER)
// <id> sdadc_prescaler
#ifndef CONF_SDADC_PRESCALER
#define CONF_SDADC_PRESCALER 0x0
#endif

// <o> Skip Count <0-15>
// <i> These bits define how many skip samples before retrieve the first valid sample, the first valid sample starts from the third sample onward (SKPCNT)
// <id> sdadc_skpcnt
#ifndef CONF_SDADC_SKPCNT
#define CONF_SDADC_SKPCNT 0x2
#endif

// <o> Over Sampling Ratio
// <0x0=>Over Sampling Ratio is 64
// <0x1=>Over Sampling Ratio is 128
// <0x2=>Over Sampling Ratio is 256
// <0x3=>Over Sampling Ratio is 512
// <0x4=>Over Sampling Ratio is 1024
// <i> The sampling rate of the SDADC is 1.5Msps/OSR (OSR)
// <id> sdadc_osr
#ifndef CONF_SDADC_OSR
#define CONF_SDADC_OSR 0x4
#endif

// <q> Free Running Mode
// <i> When enabled, the ADC is in free running mode and a new conversion will be initiated when a previous conversion completes. (FREERUN)
// <id> sdadc_freerunning_mode
#ifndef CONF_SDADC_FREERUN
#define CONF_SDADC_FREERUN 1
#endif

// <q> Chopper at input
// <i> When enabled, chopper at SDADC input. (ONCHOP)
// <id> sdadc_onchop
#ifndef CONF_SDADC_ONCHOP
#define CONF_SDADC_ONCHOP 0
#endif

// <o> Mux Input Selection
// <0x00=>Select AINN0 and AINP0 pins
// <0x01=>Select AINN1 and AINP1 pins
// <0x02=>Select AINN2 and AINP2 pins
// <i> These bits define the Mux selection for the ADC input (MUXSEL)
// <id> sdadc_muxsel
#ifndef CONF_SDADC_MUXSEL
#define CONF_SDADC_MUXSEL 0x2
#endif

// </h>

// <e> Advanced Configuration
// <id> sdadc_advanced_settings
#ifndef CONF_SDADC_ADVANCED
#define CONF_SDADC_ADVANCED 0
#endif

// <q> Run in standby
// <i> Indicates whether the ADC will continue running in standby sleep mode or not (RUNSTDBY)
// <id> sdadc_arch_runstdby
#ifndef CONF_SDADC_RUNSTDBY
#define CONF_SDADC_RUNSTDBY 0
#endif

// <q> Debug Run
// <i> If enabled, the ADC is running if the CPU is halted by an external debugger. (DBGRUN)
// <id> sdadc_arch_dbgrun
#ifndef CONF_SDADC_DBGRUN
#define CONF_SDADC_DBGRUN 0
#endif

// <q> On Demand Control
// <i> Will keep the ADC peripheral running if requested by other peripherals (ONDEMAND)
// <id> sdadc_arch_ondemand
#ifndef CONF_SDADC_ONDEMAND
#define CONF_SDADC_ONDEMAND 0
#endif

// <o> Offset Correction Value <0-16777215>
// <i> These bits define how the ADC conversion result is compensated for offset error before being written to the Result register. (OFFSETCORR)
// <id> sdadc_arch_offsetcorr
#ifndef CONF_SDADC_OFFSETCORR
#define CONF_SDADC_OFFSETCORR 0
#endif

// <o> Gain Correction Value <0-16383>
// <i> These bits define how the ADC conversion result is compensated for gain error before being written to the result register. (GAINCORR)
// <id> sdadc_arch_gaincorr
#ifndef CONF_SDADC_GAINCORR
#define CONF_SDADC_GAINCORR 1
#endif

// <o> Shift Correction Value <0-15>
// <i> These bits define how the ADC conversion result is compensated for shift error before being written to the result register. (SHIFTCORR)
// <id> sdadc_arch_shiftcorr
#ifndef CONF_SDADC_SHIFTCORR
#define CONF_SDADC_SHIFTCORR 0
#endif

// <o> Window Monitor Mode
// <0x0=>No window mode
// <0x1=>Mode 1: RESULT above lower threshold
// <0x2=>Mode 2: RESULT beneath upper threshold
// <0x3=>Mode 3: RESULT inside lower and upper threshold
// <0x4=>Mode 4: RESULT outside lower and upper threshold
// <i> These bits enable and define the window monitor mode. (WINMODE)
// <id> sdadc_arch_winmode
#ifndef CONF_SDADC_WINMODE
#define CONF_SDADC_WINMODE 0x0
#endif

// <o> Window Monitor Lower Threshold <0-16777215>
// <i> If the window monitor is enabled, these bits define the lower threshold value. (WINLT)
// <id> sdadc_arch_winlt
#ifndef CONF_SDADC_WINLT
#define CONF_SDADC_WINLT 0
#endif

// <o> Window Monitor Upper Threshold <0-16777215>
// <i> If the window monitor is enabled, these bits define the lower threshold value. (WINUT)
// <id> sdadc_arch_winut
#ifndef CONF_SDADC_WINUT
#define CONF_SDADC_WINUT 0
#endif

// <o> Bitmask for positive input sequence <0-7>
// <i> Use this parameter to input the bitmask for positive input sequence control (refer to datasheet for the device).
// <id> sdadc_arch_seqen
#ifndef CONF_SDADC_SEQEN
#define CONF_SDADC_SEQEN 0x0
#endif

// </e>

// <e> Event Control
// <id> sdadc_arch_event_settings
#ifndef CONF_SDADC_EVENT_CONTROL
#define CONF_SDADC_EVENT_CONTROL 0
#endif

// <q> Window Monitor Event Out
// <i> Enables event output on window event (WINMONEO)
// <id> sdadc_arch_winmoneo
#ifndef CONF_SDADC_WINMONEO
#define CONF_SDADC_WINMONEO 0
#endif

// <q> Result Ready Event Out
// <i> Enables event output on result ready event (RESRDEO)
// <id> sdadc_arch_resrdyeo
#ifndef CONF_SDADC_RESRDYEO
#define CONF_SDADC_RESRDYEO 0
#endif

// <q> Invert flush Event Signal
// <i> Invert the flush event input signal (FLUSHINV)
// <id> sdadc_arch_flushinv
#ifndef CONF_SDADC_FLUSHINV
#define CONF_SDADC_FLUSHINV 0
#endif

// <q> Trigger Flush On Event
// <i> Trigger an ADC pipeline flush on event (FLUSHEI)
// <id> sdadc_arch_flushei
#ifndef CONF_SDADC_FLUSHEI
#define CONF_SDADC_FLUSHEI 0
#endif

// <q> Invert Start Conversion Event Signal
// <i> Invert the start conversion event input signal (STARTINV)
// <id> sdadc_arch_startinv
#ifndef CONF_SDADC_STARTINV
#define CONF_SDADC_STARTINV 0
#endif

// <q> Trigger Conversion On Event
// <i> Trigger a conversion on event. (STARTEI)
// <id> sdadc_arch_startei
#ifndef CONF_SDADC_STARTEI
#define CONF_SDADC_STARTEI 0
#endif

// </e>

// <<< end of configuration section >>>

#endif // HPL_SDADC_CONFIG_H