/**
 ******************************************************************************
 *
 * @file       hitlnoisegeneration.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2012.
 * @brief
 * @see        The GNU Public License (GPL) Version 3
 *
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup HITLPlugin HITL Plugin
 * @{
 * @brief The Hardware In The Loop plugin
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

#include "hitlnoisegeneration.h"


HitlNoiseGeneration::HitlNoiseGeneration()
{
    memset(&noise, 0, sizeof(Noise));
}


HitlNoiseGeneration::~HitlNoiseGeneration()
{
}

Noise HitlNoiseGeneration::getNoise(){
    return noise;
}

Noise HitlNoiseGeneration::generateNoise(){

    noise.accelData.x=0;
    noise.accelData.y=0;
    noise.accelData.z=0;

    noise.gpsPosData.Latitude=0;
    noise.gpsPosData.Longitude=0;
    noise.gpsPosData.Groundspeed=0;
    noise.gpsPosData.Heading=0;
    noise.gpsPosData.Altitude=0;

    noise.gpsVelData.North=0;
    noise.gpsVelData.East=0;
    noise.gpsVelData.Down=0;

    noise.baroAltData.Altitude=0;

    noise.attActualData.Roll=0;
    noise.attActualData.Pitch=0;
    noise.attActualData.Yaw=0;

    noise.gyroData.x=0;
    noise.gyroData.y=0;
    noise.gyroData.z=0;

    noise.accelData.x=0;
    noise.accelData.y=0;
    noise.accelData.z=0;

    noise.airspeedActual.CalibratedAirspeed=0;
    noise.airspeedActual.TrueAirspeed=0;

    return noise;
}
