/**
 * \file
 *
 * \brief SAM Sigma-Delta Analog Digital Converter
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#include <hpl_adc_async.h>
#include <hpl_adc_sync.h>
#include <hpl_sdadc_config.h>
#include <utils_assert.h>
#include <utils_repeat_macro.h>

/**
 * \brief SDADC configuration
 */
struct sdadc_configuration {
	hri_sdadc_ctrla_reg_t      ctrl_a;
	hri_sdadc_refctrl_reg_t    ref_ctrl;
	hri_sdadc_ctrlb_reg_t      ctrl_b;
	hri_sdadc_evctrl_reg_t     ev_ctrl;
	hri_sdadc_inputctrl_reg_t  input_ctrl;
	hri_sdadc_ctrlc_reg_t      ctrl_c;
	hri_sdadc_winctrl_reg_t    win_ctrl;
	hri_sdadc_winlt_reg_t      win_lt;
	hri_sdadc_winut_reg_t      win_ut;
	hri_sdadc_offsetcorr_reg_t offset_corr;
	hri_sdadc_gaincorr_reg_t   gain_corr;
	hri_sdadc_shiftcorr_reg_t  shift_corr;
	hri_sdadc_seqctrl_reg_t    seq_ctrl;
	hri_sdadc_anactrl_reg_t    ana_ctrl;
	hri_sdadc_dbgctrl_reg_t    dbg_ctrl;
};

/**
 * \brief SDADC configurations
 */
static struct sdadc_configuration _sdadcs
    = {(CONF_SDADC_RUNSTDBY << SDADC_CTRLA_RUNSTDBY_Pos) | (CONF_SDADC_ONDEMAND << SDADC_CTRLA_ONDEMAND_Pos),
       SDADC_REFCTRL_REFSEL(CONF_SDADC_REFSEL) | SDADC_REFCTRL_REFRANGE(CONF_SDADC_REFRANGE)
           | (CONF_SDADC_ONREFBUF << SDADC_REFCTRL_ONREFBUF_Pos),
       SDADC_CTRLB_OSR(CONF_SDADC_OSR) | SDADC_CTRLB_SKPCNT(CONF_SDADC_SKPCNT)
           | SDADC_CTRLB_PRESCALER(CONF_SDADC_PRESCALER),
       (CONF_SDADC_FLUSHEI << SDADC_EVCTRL_FLUSHEI_Pos) | (CONF_SDADC_STARTEI << SDADC_EVCTRL_STARTEI_Pos)
           | (CONF_SDADC_FLUSHINV << SDADC_EVCTRL_FLUSHINV_Pos) | (CONF_SDADC_STARTINV << SDADC_EVCTRL_STARTINV_Pos)
           | (CONF_SDADC_RESRDYEO << SDADC_EVCTRL_RESRDYEO_Pos) | (CONF_SDADC_WINMONEO << SDADC_EVCTRL_WINMONEO_Pos),
       SDADC_INPUTCTRL_MUXSEL(CONF_SDADC_MUXSEL),
       (CONF_SDADC_FREERUN << SDADC_CTRLC_FREERUN_Pos),
       SDADC_WINCTRL_WINMODE(CONF_SDADC_WINMODE),
       SDADC_WINLT_WINLT(CONF_SDADC_WINLT),
       SDADC_WINUT_WINUT(CONF_SDADC_WINUT),
       SDADC_OFFSETCORR_OFFSETCORR(CONF_SDADC_OFFSETCORR),
       SDADC_GAINCORR_GAINCORR(CONF_SDADC_GAINCORR),
       SDADC_SHIFTCORR_SHIFTCORR(CONF_SDADC_SHIFTCORR),
       SDADC_SEQCTRL_SEQEN(CONF_SDADC_SEQEN),
       (CONF_SDADC_ONCHOP << SDADC_ANACTRL_ONCHOP_Pos),
       (CONF_SDADC_DBGRUN << SDADC_DBGCTRL_DBGRUN_Pos)};

/*!< Pointer to hpl device */
static struct _adc_async_device *_sdadcs_dev = NULL;

static void _adc_set_reference_source(void *const hw, const adc_reference_t reference);

/**
 * \brief Initialize SDADC
 *
 * \param[in] hw The pointer to hardware instance
 * \param[in] i The number of hardware instance
 */
static int32_t _adc_init(void *const hw)
{
	ASSERT(hw == SDADC);

	if (!hri_sdadc_is_syncing(hw, SDADC_SYNCBUSY_SWRST)) {
		if (hri_sdadc_get_CTRLA_reg(hw, SDADC_CTRLA_ENABLE)) {
			hri_sdadc_clear_CTRLA_ENABLE_bit(hw);
			hri_sdadc_wait_for_sync(hw, SDADC_SYNCBUSY_ENABLE);
		}
		hri_sdadc_write_CTRLA_reg(hw, SDADC_CTRLA_SWRST);
	}
	hri_sdadc_wait_for_sync(hw, SDADC_SYNCBUSY_SWRST);

	hri_sdadc_write_REFCTRL_reg(hw, _sdadcs.ref_ctrl);
	hri_sdadc_write_CTRLB_reg(hw, _sdadcs.ctrl_b);
	hri_sdadc_write_EVCTRL_reg(hw, _sdadcs.ev_ctrl);
	hri_sdadc_write_INPUTCTRL_reg(hw, _sdadcs.input_ctrl);
	hri_sdadc_write_CTRLC_reg(hw, _sdadcs.ctrl_c);
	hri_sdadc_write_WINCTRL_reg(hw, _sdadcs.win_ctrl);
	hri_sdadc_write_WINLT_reg(hw, _sdadcs.win_lt);
	hri_sdadc_write_WINUT_reg(hw, _sdadcs.win_ut);
	hri_sdadc_write_GAINCORR_reg(hw, _sdadcs.gain_corr);
	hri_sdadc_write_OFFSETCORR_reg(hw, _sdadcs.offset_corr);
	hri_sdadc_write_SHIFTCORR_reg(hw, _sdadcs.shift_corr);
	hri_sdadc_write_SEQCTRL_reg(hw, _sdadcs.seq_ctrl);
	hri_sdadc_write_ANACTRL_reg(hw, _sdadcs.ana_ctrl);
	hri_sdadc_write_DBGCTRL_reg(hw, _sdadcs.dbg_ctrl);
	hri_sdadc_write_CTRLA_reg(hw, _sdadcs.ctrl_a);

	return ERR_NONE;
}

/**
 * \brief De-initialize SDADC
 *
 * \param[in] hw The pointer to hardware instance
 */
static inline void _adc_deinit(void *hw)
{
	hri_sdadc_clear_CTRLA_ENABLE_bit(hw);
	hri_sdadc_set_CTRLA_SWRST_bit(hw);
}
/**
 * \brief Initialize SDADC
 */
int32_t _adc_async_init(struct _adc_async_device *const device, void *const hw)
{
	int32_t init_status;

	ASSERT(device);

	init_status = _adc_init(hw);
	if (init_status) {
		return init_status;
	}
	device->hw  = hw;
	_sdadcs_dev = device;

	NVIC_DisableIRQ(SDADC_IRQn);
	NVIC_ClearPendingIRQ(SDADC_IRQn);
	NVIC_EnableIRQ(SDADC_IRQn);

	return ERR_NONE;
}
/**
 * \brief De-initialize SDADC
 */
void _adc_async_deinit(struct _adc_async_device *const device)
{
	NVIC_DisableIRQ(SDADC_IRQn);
	NVIC_ClearPendingIRQ(SDADC_IRQn);

	_adc_deinit(device->hw);
}
/**
 * \brief Enable SDADC channel
 */
void _adc_async_enable_channel(struct _adc_async_device *const device, const uint8_t channel)
{
	(void)channel;

	hri_sdadc_set_CTRLA_ENABLE_bit(device->hw);
}
/**
 * \brief Disable SDADC channel
 */
void _adc_async_disable_channel(struct _adc_async_device *const device, const uint8_t channel)
{
	(void)channel;

	hri_sdadc_clear_CTRLA_ENABLE_bit(device->hw);
}
/**
 * \brief Retrieve SDADC conversion data size
 */
uint8_t _adc_async_get_data_size(const struct _adc_async_device *const device)
{
	return ADC_CTRLC_RESSEL_16BIT_Val;
}
/**
 * \brief Check if conversion is done
 */
bool _adc_async_is_channel_conversion_done(const struct _adc_async_device *const device, const uint8_t channel)
{
	(void)channel;

	return hri_sdadc_get_interrupt_RESRDY_bit(device->hw);
}
/**
 * \brief Make conversion
 */
void _adc_async_convert(struct _adc_async_device *const device)
{
	hri_sdadc_set_SWTRIG_START_bit(device->hw);
}
/**
 * \brief Retrieve the conversion result
 */
uint16_t _adc_async_read_channel_data(const struct _adc_async_device *const device, const uint8_t channel)
{
	(void)channel;

	return hri_sdadc_read_RESULT_reg(device->hw);
}
/**
 * \brief Set reference source
 */
void _adc_async_set_reference_source(struct _adc_async_device *const device, const adc_reference_t reference)
{
	_adc_set_reference_source(device->hw, reference);
}
/**
 * \brief Set resolution
 */
void _adc_async_set_resolution(struct _adc_async_device *const device, const adc_resolution_t resolution)
{
	(void)device;
	(void)resolution;
}
/**
 * \brief Set channels input sources
 */
void _adc_async_set_inputs(struct _adc_async_device *const device, const adc_pos_input_t pos_input,
                           const adc_neg_input_t neg_input, const uint8_t channel)
{
	(void)channel;

	hri_sdadc_write_INPUTCTRL_MUXSEL_bf(device->hw, pos_input);
}
/**
 * \brief Set thresholds
 */
void _adc_async_set_thresholds(struct _adc_async_device *const device, const adc_threshold_t low_threshold,
                               const adc_threshold_t up_threshold)
{
	hri_sdadc_write_WINLT_reg(device->hw, low_threshold);
	hri_sdadc_write_WINUT_reg(device->hw, up_threshold);
}
/**
 * \brief Set gain
 */
void _adc_async_set_channel_gain(struct _adc_async_device *const device, const uint8_t channel, const adc_gain_t gain)
{
	(void)device, (void)channel, (void)gain;
}
/**
 * \brief Set conversion mode
 */
void _adc_async_set_conversion_mode(struct _adc_async_device *const device, const enum adc_conversion_mode mode)
{
	if (ADC_CONVERSION_MODE_FREERUN == mode) {
		hri_sdadc_set_CTRLC_FREERUN_bit(device->hw);
	} else {
		hri_sdadc_clear_CTRLC_FREERUN_bit(device->hw);
	}
}
/**
 * \brief Set differential mode
 */
void _adc_async_set_channel_differential_mode(struct _adc_async_device *const device, const uint8_t channel,
                                              const enum adc_differential_mode mode)
{
	(void)device;
	(void)channel;
}
/**
 * \brief Set window mode
 */
void _adc_async_set_window_mode(struct _adc_async_device *const device, const adc_window_mode_t mode)
{
	hri_sdadc_write_WINCTRL_WINMODE_bf(device->hw, mode);
}
/**
 * \brief Retrieve threshold state
 */
void _adc_async_get_threshold_state(const struct _adc_async_device *const device, adc_threshold_status_t *const state)
{
	*state = hri_sdadc_get_interrupt_WINMON_bit(device->hw);
}

/**
 * \brief Enable/disable ADC channel interrupt
 */
void _adc_async_set_irq_state(struct _adc_async_device *const device, const uint8_t channel,
                              const enum _adc_async_callback_type type, const bool state)
{
	(void)channel;

	void *const hw = device->hw;

	if (ADC_ASYNC_DEVICE_MONITOR_CB == type) {
		hri_sdadc_write_INTEN_WINMON_bit(hw, state);
	} else if (ADC_ASYNC_DEVICE_ERROR_CB == type) {
		hri_sdadc_write_INTEN_OVERRUN_bit(hw, state);
	} else if (ADC_ASYNC_DEVICE_CONVERT_CB == type) {
		hri_sdadc_write_INTEN_RESRDY_bit(hw, state);
	}
}
/**
 * \brief Retrieve SDADC async helper functions
 */
void *_sdadc_get_adc_async(void)
{
	return (void *)NULL;
}

/**
 * \internal SDADC interrupt handler
 */
void SDADC_Handler(void)
{
	void *const hw = _sdadcs_dev->hw;

	if (hri_sdadc_get_interrupt_RESRDY_bit(hw)) {
		hri_sdadc_clear_interrupt_RESRDY_bit(hw);
		_sdadcs_dev->adc_async_ch_cb.convert_done(_sdadcs_dev, 0, hri_sdadc_read_RESULT_reg(hw));
	} else if (hri_sdadc_get_interrupt_OVERRUN_bit(hw)) {
		hri_sdadc_clear_interrupt_OVERRUN_bit(hw);
		_sdadcs_dev->adc_async_cb.error_cb(_sdadcs_dev, 0);
	} else if (hri_sdadc_get_interrupt_WINMON_bit(hw)) {
		hri_sdadc_clear_interrupt_WINMON_bit(hw);
		_sdadcs_dev->adc_async_cb.window_cb(_sdadcs_dev, 0);
	}
}

/**
 * \brief Set ADC reference source
 *
 * \param[in] hw The pointer to hardware instance
 * \param[in] reference The reference to set
 */
static void _adc_set_reference_source(void *const hw, const adc_reference_t reference)
{
	bool enabled = hri_sdadc_get_CTRLA_ENABLE_bit(hw);

	hri_sdadc_clear_CTRLA_ENABLE_bit(hw);
	hri_sdadc_write_REFCTRL_REFSEL_bf(hw, reference);

	if (enabled) {
		hri_sdadc_set_CTRLA_ENABLE_bit(hw);
	}
}
