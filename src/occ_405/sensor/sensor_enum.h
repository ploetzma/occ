/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/occ_405/sensor/sensor_enum.h $                            */
/*                                                                        */
/* OpenPOWER OnChipController Project                                     */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef _sensor_enum_h
#define _sensor_enum_h

/*****************************************************************************
 * This enum is the list of all the sensors that are used in the system.  The
 * value of the enum is the GSID of the sensor, and all tables are initialized
 * based on this.
 * If you add a sensor to this enum:
 *  - All GSIDs after it will automatically change
 *  - The number of sensors & size of arrays will automatially change
 *  - The name of the enum will be turned into a string, and that is the
 *    string that will be stored as that sensor's name.
 *    - This means the enum name must match the Sensor Name string
 *      and will need to follow the rules for that string (max 15 chars)
 *  - You will need to modify the following files:
 *     - sensor_table.c  - add sensor pointer to G_amec_sensor_list and
 *                         if needed to G_amec_mini_sensor_list
 *     - sensor_info.c    - add sensor information to G_sensor_info
 *     - amec/amec_sys.h - add sensor_t to system structure so you can
 */

enum e_gsid
{
    // ------------------------------------------------------
    // Code/Firmware Sensors
    // ------------------------------------------------------
    AMEintdur    = 0,  // Combined duration of the AMEC Master & Slave Tasks

    AMESSdur0,         // Combined duration of the AMEC Master & Slave 0
    AMESSdur1,         // Combined duration of the AMEC Master & Slave 1
    AMESSdur2,         // Combined duration of the AMEC Master & Slave 2
    AMESSdur3,         // Combined duration of the AMEC Master & Slave 3
    AMESSdur4,         // Combined duration of the AMEC Master & Slave 4
    AMESSdur5,         // Combined duration of the AMEC Master & Slave 5
    AMESSdur6,         // Combined duration of the AMEC Master & Slave 6
    AMESSdur7,         // Combined duration of the AMEC Master & Slave 7

    PROBE250US0,       // Internal Sensor for debug via AMESTER
    PROBE250US1,       // Internal Sensor for debug via AMESTER
    PROBE250US2,       // Internal Sensor for debug via AMESTER
    PROBE250US3,       // Internal Sensor for debug via AMESTER
    PROBE250US4,       // Internal Sensor for debug via AMESTER
    PROBE250US5,       // Internal Sensor for debug via AMESTER
    PROBE250US6,       // Internal Sensor for debug via AMESTER
    PROBE250US7,       // Internal Sensor for debug via AMESTER

    GPEtickdur0,       // Duration on the GPE0 Engine
    GPEtickdur1,       // Duration on the GPE1 Engine
    RTLtickdur,        // Duration on the RTL tick interrupt

    // ------------------------------------------------------
    // System Sensors
    // ------------------------------------------------------
    TEMPAMBIENT,       // Ambient Temp of System (from APSS)
    ALTITUDE,          // Altitude of System (from APSS)
    PWR250US,          // System DC Power (from APSS)
    PWR250USFAN,       // Fan Power (from APSS)
    PWR250USIO,        // IO Subsystem Power (from APSS)
    PWR250USSTORE,     // Storage Subsys Power (from APSS)
    PWR250USGPU,       // GPU Subsystem Power (from APSS) e.g. Nvidia GPU
    FANSPEEDAVG,       // Average Fan Speed (from DPSS)
    PWRAPSSCH0,        // These PWRAPSSCH sensors are used to report the power
    PWRAPSSCH1,        // provided by each of the 16 APSS channels.
    PWRAPSSCH2,
    PWRAPSSCH3,
    PWRAPSSCH4,
    PWRAPSSCH5,
    PWRAPSSCH6,
    PWRAPSSCH7,
    PWRAPSSCH8,
    PWRAPSSCH9,
    PWRAPSSCH10,
    PWRAPSSCH11,
    PWRAPSSCH12,
    PWRAPSSCH13,
    PWRAPSSCH14,
    PWRAPSSCH15,

    // ------------------------------------------------------
    // Chip Sensors
    // ------------------------------------------------------
    TODclock0,         // \       .
    TODclock1,         //  => 32 MHz TimeOfDay Clock split into 3 sensors
    TODclock2,         // /          (from Chip SCOM)

    // ------------------------------------------------------
    // Processor Sensors
    // ------------------------------------------------------
    FREQA4MSP0,
    IPS4MSP0,
    MEMSP2MSP0,
    PWR250USP0,
    PWR250USVDD0,
    CUR250USVDD0,
    PWR250USVCS0,
    PWR250USMEM0,
    SLEEPCNT4MSP0,
    WINKCNT4MSP0,
    SP250USP0,
    TEMP4MSP0,
    TEMP4MSP0PEAK,
    UTIL4MSP0,
    VRFAN250USPROC,
    VRHOT250USPROC,

    FREQ250USP0C0,
    FREQ250USP0C1,
    FREQ250USP0C2,
    FREQ250USP0C3,
    FREQ250USP0C4,
    FREQ250USP0C5,
    FREQ250USP0C6,
    FREQ250USP0C7,
    FREQ250USP0C8,
    FREQ250USP0C9,
    FREQ250USP0C10,
    FREQ250USP0C11,
    FREQ250USP0C12,
    FREQ250USP0C13,
    FREQ250USP0C14,
    FREQ250USP0C15,
    FREQ250USP0C16,
    FREQ250USP0C17,
    FREQ250USP0C18,
    FREQ250USP0C19,
    FREQ250USP0C20,
    FREQ250USP0C21,
    FREQ250USP0C22,
    FREQ250USP0C23,

    FREQA4MSP0C0,
    FREQA4MSP0C1,
    FREQA4MSP0C2,
    FREQA4MSP0C3,
    FREQA4MSP0C4,
    FREQA4MSP0C5,
    FREQA4MSP0C6,
    FREQA4MSP0C7,
    FREQA4MSP0C8,
    FREQA4MSP0C9,
    FREQA4MSP0C10,
    FREQA4MSP0C11,
    FREQA4MSP0C12,
    FREQA4MSP0C13,
    FREQA4MSP0C14,
    FREQA4MSP0C15,
    FREQA4MSP0C16,
    FREQA4MSP0C17,
    FREQA4MSP0C18,
    FREQA4MSP0C19,
    FREQA4MSP0C20,
    FREQA4MSP0C21,
    FREQA4MSP0C22,
    FREQA4MSP0C23,

    IPS4MSP0C0,
    IPS4MSP0C1,
    IPS4MSP0C2,
    IPS4MSP0C3,
    IPS4MSP0C4,
    IPS4MSP0C5,
    IPS4MSP0C6,
    IPS4MSP0C7,
    IPS4MSP0C8,
    IPS4MSP0C9,
    IPS4MSP0C10,
    IPS4MSP0C11,
    IPS4MSP0C12,
    IPS4MSP0C13,
    IPS4MSP0C14,
    IPS4MSP0C15,
    IPS4MSP0C16,
    IPS4MSP0C17,
    IPS4MSP0C18,
    IPS4MSP0C19,
    IPS4MSP0C20,
    IPS4MSP0C21,
    IPS4MSP0C22,
    IPS4MSP0C23,

    NOTBZE4MSP0C0,
    NOTBZE4MSP0C1,
    NOTBZE4MSP0C2,
    NOTBZE4MSP0C3,
    NOTBZE4MSP0C4,
    NOTBZE4MSP0C5,
    NOTBZE4MSP0C6,
    NOTBZE4MSP0C7,
    NOTBZE4MSP0C8,
    NOTBZE4MSP0C9,
    NOTBZE4MSP0C10,
    NOTBZE4MSP0C11,
    NOTBZE4MSP0C12,
    NOTBZE4MSP0C13,
    NOTBZE4MSP0C14,
    NOTBZE4MSP0C15,
    NOTBZE4MSP0C16,
    NOTBZE4MSP0C17,
    NOTBZE4MSP0C18,
    NOTBZE4MSP0C19,
    NOTBZE4MSP0C20,
    NOTBZE4MSP0C21,
    NOTBZE4MSP0C22,
    NOTBZE4MSP0C23,

    NOTFIN4MSP0C0,
    NOTFIN4MSP0C1,
    NOTFIN4MSP0C2,
    NOTFIN4MSP0C3,
    NOTFIN4MSP0C4,
    NOTFIN4MSP0C5,
    NOTFIN4MSP0C6,
    NOTFIN4MSP0C7,
    NOTFIN4MSP0C8,
    NOTFIN4MSP0C9,
    NOTFIN4MSP0C10,
    NOTFIN4MSP0C11,
    NOTFIN4MSP0C12,
    NOTFIN4MSP0C13,
    NOTFIN4MSP0C14,
    NOTFIN4MSP0C15,
    NOTFIN4MSP0C16,
    NOTFIN4MSP0C17,
    NOTFIN4MSP0C18,
    NOTFIN4MSP0C19,
    NOTFIN4MSP0C20,
    NOTFIN4MSP0C21,
    NOTFIN4MSP0C22,
    NOTFIN4MSP0C23,

    TEMP4MSP0C0,
    TEMP4MSP0C1,
    TEMP4MSP0C2,
    TEMP4MSP0C3,
    TEMP4MSP0C4,
    TEMP4MSP0C5,
    TEMP4MSP0C6,
    TEMP4MSP0C7,
    TEMP4MSP0C8,
    TEMP4MSP0C9,
    TEMP4MSP0C10,
    TEMP4MSP0C11,
    TEMP4MSP0C12,
    TEMP4MSP0C13,
    TEMP4MSP0C14,
    TEMP4MSP0C15,
    TEMP4MSP0C16,
    TEMP4MSP0C17,
    TEMP4MSP0C18,
    TEMP4MSP0C19,
    TEMP4MSP0C20,
    TEMP4MSP0C21,
    TEMP4MSP0C22,
    TEMP4MSP0C23,

    UTIL4MSP0C0,
    UTIL4MSP0C1,
    UTIL4MSP0C2,
    UTIL4MSP0C3,
    UTIL4MSP0C4,
    UTIL4MSP0C5,
    UTIL4MSP0C6,
    UTIL4MSP0C7,
    UTIL4MSP0C8,
    UTIL4MSP0C9,
    UTIL4MSP0C10,
    UTIL4MSP0C11,
    UTIL4MSP0C12,
    UTIL4MSP0C13,
    UTIL4MSP0C14,
    UTIL4MSP0C15,
    UTIL4MSP0C16,
    UTIL4MSP0C17,
    UTIL4MSP0C18,
    UTIL4MSP0C19,
    UTIL4MSP0C20,
    UTIL4MSP0C21,
    UTIL4MSP0C22,
    UTIL4MSP0C23,

    NUTIL3SP0C0,
    NUTIL3SP0C1,
    NUTIL3SP0C2,
    NUTIL3SP0C3,
    NUTIL3SP0C4,
    NUTIL3SP0C5,
    NUTIL3SP0C6,
    NUTIL3SP0C7,
    NUTIL3SP0C8,
    NUTIL3SP0C9,
    NUTIL3SP0C10,
    NUTIL3SP0C11,
    NUTIL3SP0C12,
    NUTIL3SP0C13,
    NUTIL3SP0C14,
    NUTIL3SP0C15,
    NUTIL3SP0C16,
    NUTIL3SP0C17,
    NUTIL3SP0C18,
    NUTIL3SP0C19,
    NUTIL3SP0C20,
    NUTIL3SP0C21,
    NUTIL3SP0C22,
    NUTIL3SP0C23,

    MSTL2MSP0C0,
    MSTL2MSP0C1,
    MSTL2MSP0C2,
    MSTL2MSP0C3,
    MSTL2MSP0C4,
    MSTL2MSP0C5,
    MSTL2MSP0C6,
    MSTL2MSP0C7,
    MSTL2MSP0C8,
    MSTL2MSP0C9,
    MSTL2MSP0C10,
    MSTL2MSP0C11,
    MSTL2MSP0C12,
    MSTL2MSP0C13,
    MSTL2MSP0C14,
    MSTL2MSP0C15,
    MSTL2MSP0C16,
    MSTL2MSP0C17,
    MSTL2MSP0C18,
    MSTL2MSP0C19,
    MSTL2MSP0C20,
    MSTL2MSP0C21,
    MSTL2MSP0C22,
    MSTL2MSP0C23,

    CMT2MSP0C0,
    CMT2MSP0C1,
    CMT2MSP0C2,
    CMT2MSP0C3,
    CMT2MSP0C4,
    CMT2MSP0C5,
    CMT2MSP0C6,
    CMT2MSP0C7,
    CMT2MSP0C8,
    CMT2MSP0C9,
    CMT2MSP0C10,
    CMT2MSP0C11,
    CMT2MSP0C12,
    CMT2MSP0C13,
    CMT2MSP0C14,
    CMT2MSP0C15,
    CMT2MSP0C16,
    CMT2MSP0C17,
    CMT2MSP0C18,
    CMT2MSP0C19,
    CMT2MSP0C20,
    CMT2MSP0C21,
    CMT2MSP0C22,
    CMT2MSP0C23,

    PPICP0C0,
    PPICP0C1,
    PPICP0C2,
    PPICP0C3,
    PPICP0C4,
    PPICP0C5,
    PPICP0C6,
    PPICP0C7,
    PPICP0C8,
    PPICP0C9,
    PPICP0C10,
    PPICP0C11,
    PPICP0C12,
    PPICP0C13,
    PPICP0C14,
    PPICP0C15,
    PPICP0C16,
    PPICP0C17,
    PPICP0C18,
    PPICP0C19,
    PPICP0C20,
    PPICP0C21,
    PPICP0C22,
    PPICP0C23,

    PWRPX250USP0C0,
    PWRPX250USP0C1,
    PWRPX250USP0C2,
    PWRPX250USP0C3,
    PWRPX250USP0C4,
    PWRPX250USP0C5,
    PWRPX250USP0C6,
    PWRPX250USP0C7,
    PWRPX250USP0C8,
    PWRPX250USP0C9,
    PWRPX250USP0C10,
    PWRPX250USP0C11,
    PWRPX250USP0C12,
    PWRPX250USP0C13,
    PWRPX250USP0C14,
    PWRPX250USP0C15,
    PWRPX250USP0C16,
    PWRPX250USP0C17,
    PWRPX250USP0C18,
    PWRPX250USP0C19,
    PWRPX250USP0C20,
    PWRPX250USP0C21,
    PWRPX250USP0C22,
    PWRPX250USP0C23,

    // ------------------------------------------------------
    // Regulator Sensors
    // ------------------------------------------------------
    UVOLT250USP0V0,
    UVOLT250USP0V1,
    VOLT250USP0V0,
    VOLT250USP0V1,

    // ------------------------------------------------------
    // Memory Sensors
    // ------------------------------------------------------
    VRFAN250USMEM,
    VRHOT250USMEM,

    MRD2MSP0M0,
    MRD2MSP0M1,
    MRD2MSP0M2,
    MRD2MSP0M3,
    MRD2MSP0M4,
    MRD2MSP0M5,
    MRD2MSP0M6,
    MRD2MSP0M7,

    MWR2MSP0M0,
    MWR2MSP0M1,
    MWR2MSP0M2,
    MWR2MSP0M3,
    MWR2MSP0M4,
    MWR2MSP0M5,
    MWR2MSP0M6,
    MWR2MSP0M7,

    TEMPDIMMAXP0M0,
    TEMPDIMMAXP0M1,
    TEMPDIMMAXP0M2,
    TEMPDIMMAXP0M3,
    TEMPDIMMAXP0M4,
    TEMPDIMMAXP0M5,
    TEMPDIMMAXP0M6,
    TEMPDIMMAXP0M7,

    LOCDIMMAXP0M0,
    LOCDIMMAXP0M1,
    LOCDIMMAXP0M2,
    LOCDIMMAXP0M3,
    LOCDIMMAXP0M4,
    LOCDIMMAXP0M5,
    LOCDIMMAXP0M6,
    LOCDIMMAXP0M7,

    // ------------------------------------------------------
    // Centaur Sensors - 8 MemC/Proc - 1 Cent/MemC - 2 PP/Cent
    // ------------------------------------------------------
    MAC2MSP0M0C0P0,
    MAC2MSP0M0C0P1,
    MAC2MSP0M1C0P0,
    MAC2MSP0M1C0P1,
    MAC2MSP0M2C0P0,
    MAC2MSP0M2C0P1,
    MAC2MSP0M3C0P0,
    MAC2MSP0M3C0P1,
    MAC2MSP0M4C0P0,
    MAC2MSP0M4C0P1,
    MAC2MSP0M5C0P0,
    MAC2MSP0M5C0P1,
    MAC2MSP0M6C0P0,
    MAC2MSP0M6C0P1,
    MAC2MSP0M7C0P0,
    MAC2MSP0M7C0P1,

    MPU2MSP0M0C0P0,
    MPU2MSP0M0C0P1,
    MPU2MSP0M1C0P0,
    MPU2MSP0M1C0P1,
    MPU2MSP0M2C0P0,
    MPU2MSP0M2C0P1,
    MPU2MSP0M3C0P0,
    MPU2MSP0M3C0P1,
    MPU2MSP0M4C0P0,
    MPU2MSP0M4C0P1,
    MPU2MSP0M5C0P0,
    MPU2MSP0M5C0P1,
    MPU2MSP0M6C0P0,
    MPU2MSP0M6C0P1,
    MPU2MSP0M7C0P0,
    MPU2MSP0M7C0P1,

    MIRB2MSP0M0C0P0,
    MIRB2MSP0M0C0P1,
    MIRB2MSP0M1C0P0,
    MIRB2MSP0M1C0P1,
    MIRB2MSP0M2C0P0,
    MIRB2MSP0M2C0P1,
    MIRB2MSP0M3C0P0,
    MIRB2MSP0M3C0P1,
    MIRB2MSP0M4C0P0,
    MIRB2MSP0M4C0P1,
    MIRB2MSP0M5C0P0,
    MIRB2MSP0M5C0P1,
    MIRB2MSP0M6C0P0,
    MIRB2MSP0M6C0P1,
    MIRB2MSP0M7C0P0,
    MIRB2MSP0M7C0P1,

    MIRL2MSP0M0C0P0,
    MIRL2MSP0M0C0P1,
    MIRL2MSP0M1C0P0,
    MIRL2MSP0M1C0P1,
    MIRL2MSP0M2C0P0,
    MIRL2MSP0M2C0P1,
    MIRL2MSP0M3C0P0,
    MIRL2MSP0M3C0P1,
    MIRL2MSP0M4C0P0,
    MIRL2MSP0M4C0P1,
    MIRL2MSP0M5C0P0,
    MIRL2MSP0M5C0P1,
    MIRL2MSP0M6C0P0,
    MIRL2MSP0M6C0P1,
    MIRL2MSP0M7C0P0,
    MIRL2MSP0M7C0P1,

    MIRM2MSP0M0C0P0,
    MIRM2MSP0M0C0P1,
    MIRM2MSP0M1C0P0,
    MIRM2MSP0M1C0P1,
    MIRM2MSP0M2C0P0,
    MIRM2MSP0M2C0P1,
    MIRM2MSP0M3C0P0,
    MIRM2MSP0M3C0P1,
    MIRM2MSP0M4C0P0,
    MIRM2MSP0M4C0P1,
    MIRM2MSP0M5C0P0,
    MIRM2MSP0M5C0P1,
    MIRM2MSP0M6C0P0,
    MIRM2MSP0M6C0P1,
    MIRM2MSP0M7C0P0,
    MIRM2MSP0M7C0P1,

    MIRH2MSP0M0C0P0,
    MIRH2MSP0M0C0P1,
    MIRH2MSP0M1C0P0,
    MIRH2MSP0M1C0P1,
    MIRH2MSP0M2C0P0,
    MIRH2MSP0M2C0P1,
    MIRH2MSP0M3C0P0,
    MIRH2MSP0M3C0P1,
    MIRH2MSP0M4C0P0,
    MIRH2MSP0M4C0P1,
    MIRH2MSP0M5C0P0,
    MIRH2MSP0M5C0P1,
    MIRH2MSP0M6C0P0,
    MIRH2MSP0M6C0P1,
    MIRH2MSP0M7C0P0,
    MIRH2MSP0M7C0P1,

    MTS2MSP0M0C0P0,
    MTS2MSP0M0C0P1,
    MTS2MSP0M1C0P0,
    MTS2MSP0M1C0P1,
    MTS2MSP0M2C0P0,
    MTS2MSP0M2C0P1,
    MTS2MSP0M3C0P0,
    MTS2MSP0M3C0P1,
    MTS2MSP0M4C0P0,
    MTS2MSP0M4C0P1,
    MTS2MSP0M5C0P0,
    MTS2MSP0M5C0P1,
    MTS2MSP0M6C0P0,
    MTS2MSP0M6C0P1,
    MTS2MSP0M7C0P0,
    MTS2MSP0M7C0P1,

    MEMSP2MSPM0C0P0,
    MEMSP2MSPM0C0P1,
    MEMSP2MSPM1C0P0,
    MEMSP2MSPM1C0P1,
    MEMSP2MSPM2C0P0,
    MEMSP2MSPM2C0P1,
    MEMSP2MSPM3C0P0,
    MEMSP2MSPM3C0P1,
    MEMSP2MSPM4C0P0,
    MEMSP2MSPM4C0P1,
    MEMSP2MSPM5C0P0,
    MEMSP2MSPM5C0P1,
    MEMSP2MSPM6C0P0,
    MEMSP2MSPM6C0P1,
    MEMSP2MSPM7C0P0,
    MEMSP2MSPM7C0P1,

    M4RD2MSP0M0C0P0,
    M4RD2MSP0M0C0P1,
    M4RD2MSP0M1C0P0,
    M4RD2MSP0M1C0P1,
    M4RD2MSP0M2C0P0,
    M4RD2MSP0M2C0P1,
    M4RD2MSP0M3C0P0,
    M4RD2MSP0M3C0P1,
    M4RD2MSP0M4C0P0,
    M4RD2MSP0M4C0P1,
    M4RD2MSP0M5C0P0,
    M4RD2MSP0M5C0P1,
    M4RD2MSP0M6C0P0,
    M4RD2MSP0M6C0P1,
    M4RD2MSP0M7C0P0,
    M4RD2MSP0M7C0P1,

    M4WR2MSP0M0C0P0,
    M4WR2MSP0M0C0P1,
    M4WR2MSP0M1C0P0,
    M4WR2MSP0M1C0P1,
    M4WR2MSP0M2C0P0,
    M4WR2MSP0M2C0P1,
    M4WR2MSP0M3C0P0,
    M4WR2MSP0M3C0P1,
    M4WR2MSP0M4C0P0,
    M4WR2MSP0M4C0P1,
    M4WR2MSP0M5C0P0,
    M4WR2MSP0M5C0P1,
    M4WR2MSP0M6C0P0,
    M4WR2MSP0M6C0P1,
    M4WR2MSP0M7C0P0,
    M4WR2MSP0M7C0P1,

    MIRC2MSP0M0,
    MIRC2MSP0M1,
    MIRC2MSP0M2,
    MIRC2MSP0M3,
    MIRC2MSP0M4,
    MIRC2MSP0M5,
    MIRC2MSP0M6,
    MIRC2MSP0M7,

    MLP2P0M0,
    MLP2P0M1,
    MLP2P0M2,
    MLP2P0M3,
    MLP2P0M4,
    MLP2P0M5,
    MLP2P0M6,
    MLP2P0M7,

    TEMP2MSCENT,
    TEMP2MSDIMM,
    MEMSP2MS,

    // ------------------------------------------------------
    // Partition Sensors
    // ------------------------------------------------------
    UTIL2MSSLCG000,
    UTIL2MSSLCG001,
    UTIL2MSSLCG002,
    UTIL2MSSLCG003,
    UTIL2MSSLCG004,
    UTIL2MSSLCG005,
    UTIL2MSSLCG006,
    UTIL2MSSLCG007,
    UTIL2MSSLCG008,
    UTIL2MSSLCG009,
    UTIL2MSSLCG010,
    UTIL2MSSLCG011,

    // ------------------------------------------------------
    // END of Sensor List (this must be last entry)
    // ------------------------------------------------------
    NUMBER_OF_SENSORS_IN_LIST,
};

#endif

