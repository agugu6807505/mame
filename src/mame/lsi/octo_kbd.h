// license:BSD-3-Clause
// copyright-holders:Barry Rodewald
#ifndef MAME_LSI_OCTO_KBD_H
#define MAME_LSI_OCTO_KBD_H

#pragma once

#include "bus/rs232/rs232.h"
#include "machine/keyboard.h"

class octopus_keyboard_device : public buffered_rs232_device<16U>, protected device_matrix_keyboard_interface<16U>
{
public:
	octopus_keyboard_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);
	virtual ioport_constructor device_input_ports() const override;

protected:
	virtual void device_start() override ATTR_COLD;
	virtual void device_reset() override ATTR_COLD;
	virtual void key_make(uint8_t row, uint8_t column) override;
	virtual void key_repeat(uint8_t row, uint8_t column) override;
	virtual void key_break(uint8_t row, uint8_t column) override;

private:
	virtual void received_byte(uint8_t data) override;

	int m_delay = 0;  // keypress delay after initial press
	int m_repeat = 0; // keypress repeat rate
	uint8_t m_enabled = 0;  // keyboard enabled?
};

DECLARE_DEVICE_TYPE(OCTOPUS_KEYBOARD, octopus_keyboard_device)

#endif // MAME_LSI_OCTO_KBD_H
