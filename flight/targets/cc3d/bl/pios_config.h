/**
 ******************************************************************************
 * @addtogroup TauLabsBootloader Tau Labs Bootloaders
 * @{
 * @addtogroup CC3DBL CopterControl 3D bootloader
 * @{
 *
 * @file       pios_config.h 
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2012-2013
 * @brief      Board specific bootloader configuration file for PiOS
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/* 
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 3 of the License, or 
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
 * for more details.
 * 
 * You should have received a copy of the GNU General Public License along 
 * with this program; if not, see <http://www.gnu.org/licenses/>
 */

#ifndef PIOS_CONFIG_H
#define PIOS_CONFIG_H

#define PIOS_INCLUDE_BL_HELPER
#define PIOS_INCLUDE_BL_HELPER_WRITE_SUPPORT
/* Enable/Disable PiOS Modules */
#define PIOS_INCLUDE_ANNUNC
#define PIOS_INCLUDE_SYS
#define PIOS_INCLUDE_USB
#define PIOS_INCLUDE_USB_HID
#define PIOS_INCLUDE_COM_MSG
#define PIOS_INCLUDE_GPIO
#define PIOS_INCLUDE_IAP
#define PIOS_NO_GPS

#endif /* PIOS_CONFIG_H */
/**
 * @}
 * @}
 */
