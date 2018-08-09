/*
   alienflightf3v1_board.h 

   Copyright (c) 2018 Simon D. Levy

   This file is part of Hackflight.

   Hackflight is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Hackflight is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with Hackflight.  If not, see <http://www.gnu.org/licenses/>.
 */

extern "C" {

#include "platform.h"
#include "dma.h"
#include "gpio.h"
#include "serial.h"
#include "system.h"
#include "serial_uart.h"
#include "system.h"
#include "serial_usb_vcp.h"

    serialPort_t * serial0_open(void)
    {
        return usbVcpOpen();
    }

} // extern "C"

#include <f3board.h>
#include <hackflight.hpp>
#include <mixers/quadx.hpp>
#include <MPU6050.h>
#include "alienflightf3v1_board.h"

bool AlienflightF3V1::getGyrometer(float gyroRates[3])
{
    (void)gyroRates; // XXX

    static uint32_t _time;
    uint32_t time = micros();
    if (time-_time > 5000) {
        _time = time;
        return true;
    }
    return false;
}

bool AlienflightF3V1::getQuaternion(float quat[4])
{
    (void)quat; // XXX

    static uint32_t _time;
    uint32_t time = micros();
    if (time-_time > 10000) {
        _time = time;
        return true;
    }
    return false;
}

void AlienflightF3V1::writeMotor(uint8_t index, float value)
{
    (void)index; // XXX
    (void)value;
}


