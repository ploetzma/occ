/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/occ_405/dcom/dcom.h $                                     */
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

#ifndef _DCOM_H
#define _DCOM_H

#include <occ_common.h>
#include <common_types.h>
#include <occ_service_codes.h>
#include <occ_sys_config.h>
#include <rtls.h>
#include <apss.h>
#include <proc_pstate.h>

// Max Centaur Throttles
#define MAX_CENTAUR_THROTTLES 8

// Max Interleave Group Throttles
#define MAX_MEM_INTERLEAVE_GROUP_THROTTLES 8

// OCC roles
#define OCC_SLAVE         0
#define OCC_MASTER        1
#define OCC_BACKUP_MASTER 2

// Memory address space where DCOM, sensor data, OPAL communications,
// etc take place. Uses BAR2, with pba_region = 0b10
#define COMMON_BASE_ADDRESS 0xA0000000
#define COMMON_SPACE_SIZE   0x00800000     // 8 MB

// Occ Master to Slave Messages (inbox ping/pong)
#define SLAVE_INBOX_PING_COMMON_OFFSET     0x00000000
#define SLAVE_INBOX_PING_COMMON_ADDRESS    (COMMON_BASE_ADDRESS+SLAVE_INBOX_PING_COMMON_OFFSET)

#define SLAVE_INBOX_PONG_COMMON_OFFSET     0x00000800
#define SLAVE_INBOX_PONG_COMMON_ADDRESS    (COMMON_BASE_ADDRESS+SLAVE_INBOX_PONG_COMMON_OFFSET)

#define NUM_BYTES_IN_SLAVE_INBOX              256

// Magic Number used to denote the end of Master->Slave Broadcast packets
#define PBAX_MAGIC_NUMBER_32B            0x00123181
// Magic Number used to denote the start of Master->Slave Broadcast packets
#define PBAX_MAGIC_NUMBER2_32B           0x00474A53

#define MAX_PBAX_CHIP_ID (MAX_NUM_OCC - 1)

// PBAX Broadcast Masks, use PBAX_GROUP_MASK_MAX
#define PBAX_CONFIGURE_RCV_GROUP_MASK PBAX_GROUP_MASK_MAX
#define PBAX_BROADCAST_GROUP          PBAX_GROUP_MASK_MAX


// OCC Slave to Master Messages (inbox ping/pong)
#define SLAVE_OUTBOX_PING_COMMON_OFFSET     0x00001000
#define SLAVE_OUTBOX_PING_COMMON_ADDRESS    (COMMON_BASE_ADDRESS+SLAVE_OUTBOX_PING_COMMON_OFFSET)

#define SLAVE_OUTBOX_PONG_COMMON_OFFSET     0x00003000
#define SLAVE_OUTBOX_PONG_COMMON_ADDRESS    (COMMON_BASE_ADDRESS+SLAVE_OUTBOX_PONG_COMMON_OFFSET)

#define NUM_BYTES_IN_SLAVE_OUTBOX             1024

// GP REG0
#define TP_BRIDGE_GP_REG0       0x01000000

// GP0 Read Chip Id Mask & Offset
#define GP0_READ_CHIP_ID_MASK   0x00000000001C0000
#define CHIP_ID_MASK_OFFSET     18

// GP0 Read Node Id Mask & Offset
#define GP0_READ_NODE_ID_MASK   0x0000000000E00000
#define NODE_ID_MASK_OFFSET     21

// What should these sizes be?
#define NUM_ENTRIES_PBAX_QUEUE0 32
#define NUM_ENTRIES_PBAX_QUEUE1 16

// Wait for defines number of retries for task
#define MAX_WAIT_FOR_SLAVES 400
#define MAX_WAIT_FOR_MASTER 400

// general defines
#define TOD_SIZE 6
#define NUM_TOD_SENSORS 3
#define SLV_INBOX_RSV_SIZE 68
#define SLV_MAILBOX_SIZE 32
#define SLV_OUTBOX_RSV_SIZE 618
#define DOORBELL_RSV_SIZE 1

#define DCOM_250us_GAP 1
#define DCOM_4MS_GAP 8
#define DCOM_1S_GAP 4000

// POB Id structure
typedef struct
{
    uint8_t module_id  :2;
    uint8_t valid      :1;  // Valid chip/node id?
    uint8_t node_id    :2;
    uint8_t reserved   :1;
    uint8_t chip_id    :2;
} pob_id_t;

// TODO may change in the future
// For now pbax structure is same as pob id structure
typedef pob_id_t pbax_id_t;

// SLAVE INBOX structure
typedef struct
{
    // Packet Type & Sequence Information
    uint8_t  seq;                                                   // [0]
    uint8_t  version;                                               // [1]

    // From APSS Power Measurement
    uint16_t adc[MAX_APSS_ADC_CHANNELS];                            // [2]   - 32 bytes
    uint16_t gpio[MAX_APSS_GPIO_PORTS];                             // [34]  -  4 bytes
    uint16_t ambient_temp;                                          // [38]  -  2 bytes
    uint16_t altitude;                                              // [40]  -  2 bytes
    uint8_t  tod[ TOD_SIZE ];                                       // [42]  -  6 bytes

    // AMEC Actuators
    uint16_t freq250usp0cy[MAX_CORES];                              // [48]  - 48 bytes
    uint16_t memsp2msP0MxCyPz[MAX_CENTAUR_THROTTLES];               // [96]  - 16 bytes
    uint16_t memsp2msP0IGx[MAX_MEM_INTERLEAVE_GROUP_THROTTLES];     // [112] - 16 bytes

    // Manufacturing parameters
    uint16_t foverride;                                             // [128] -  2 bytes
    uint8_t  foverride_enable;                                      // [130] -  1 byte
    uint8_t  emulate_oversub;                                       // [131] -  1 byte

    // Idle Power Saver parameters
    uint16_t ips_freq_request;                                      // [132] -  2 bytes

    // DPS Tunable Parameters
    uint16_t alpha_up;                                              // [134] -  2 bytes
    uint16_t alpha_down;                                            // [136] -  2 bytes
    uint16_t sample_count_util;                                     // [138] -  2 bytes
    uint16_t step_up;                                               // [140] -  2 bytes
    uint16_t step_down;                                             // [142] -  2 bytes
    uint16_t epsilon_perc;                                          // [144] -  2 bytes
    uint16_t tlutil;                                                // [146] -  2 bytes
    uint8_t  tunable_param_overwrite;                               // [148] -  1 byte

    // Soft frequency boundaries
    uint16_t soft_fmin;                                             // [149] -  2 bytes
    uint8_t  pad;                                                   // [151] -  1 bytes
    uint16_t soft_fmax;                                             // [152] -  2 bytes

    // Reserved Bytes
    union
    {
      struct
      {
          uint32_t     counter;
          freqConfig_t sys_mode_freq;
          uint8_t      tb_record;
      };
      uint8_t  reserved[ SLV_INBOX_RSV_SIZE ];                      // [154] - 68 bytes
    };

    // General Firmware Message Passing
    uint8_t  occ_fw_mailbox[ SLV_MAILBOX_SIZE ];                    // [224] - 32 bytes

} dcom_slv_inbox_t __attribute ((aligned (128)));



// SLAVE OUTBOX structure
typedef struct __attribute__ ((packed))
{
    // Packet Type & Sequence Information
    uint8_t  seq;                                                //   [0]
    uint8_t  version;                                            //   [1]

    // Mini-sensors
    uint16_t freqa4msp0;                                         //   [2]
    uint16_t ips4msp0cy[MAX_CORES];                              //   [4]
    uint16_t mcpifd4msp0cy[MAX_CORES];                           //  [52]
    uint16_t mcpifi4msp0cy[MAX_CORES];                           // [100]
    uint16_t memsp2msp0mx[MAX_NUM_MEM_CONTROLLERS];              // [148]
    uint16_t pwr250usp0;                                         // [164]
    uint16_t pwr250usmemp0;                                      // [166]
    uint16_t sleepcnt4msp0;                                      // [168]
    uint16_t winkcnt4msp0;                                       // [170]
    uint16_t temp4msp0;                                          // [172]
    uint16_t temp4msp0peak;                                      // [174]
    uint16_t util4msp0cy[MAX_CORES];                             // [176]
    uint16_t vrfan250usmem;                                      // [224]
    uint16_t vrfan250usproc;                                     // [226]
    uint16_t mrd2msp0mx[MAX_NUM_MEM_CONTROLLERS];                // [228]
    uint16_t mwr2msp0mx[MAX_NUM_MEM_CONTROLLERS];                // [244]
    uint16_t pwrpx250usp0cy[MAX_CORES];                          // [260]
    uint16_t todclock[NUM_TOD_SENSORS];                          // [308]
    uint16_t temp2mscent;                                        // [314]
    uint16_t temp2msdimm;                                        // [316]
    uint16_t util4msp0;                                          // [318]
    uint16_t ips4msp0;                                           // [320]
    uint16_t nutil3sp0cy[MAX_CORES];                             // [322]

    // Fwish (i.e., desired frequency that this OCC slave wants based on DPS
    // algorithms)
    uint16_t fwish;                                              // [370]
    // Factual (i.e., actual frequency requested by this OCC slave)
    uint16_t factual;                                            // [372]

    // Reserved Bytes
    union
    {
        uint8_t  reserved[SLV_OUTBOX_RSV_SIZE];                  // [374] - 618 bytes
        struct __attribute__ ((packed))
        {
            uint8_t _reserved_1;
            uint8_t _reserved_2;
            uint32_t counter;
        };
    };

    // General Firmware Message Passing
    uint8_t  occ_fw_mailbox[SLV_MAILBOX_SIZE];                   // [992] - 32 bytes
} dcom_slv_outbox_t __attribute__ ((aligned (128)));

// Slave Inbox Doorbell
//   This must be aligned to 8 bytes since that is the unit
//   that the PBAX unit uses to send
typedef struct
{
    union
    {
        struct
        {
            // PowerBus ID (= pbax_id) so that the slave knows who the master is
            pob_id_t pob_id;                        //  1 byte
            // Magic Number denoting the start of the packet
            uint32_t magic1                :24;     //  3 bytes
            // OCI Address where the Slave Inbox Buffer was placed
            uint32_t addr_slv_inbox_buffer0;        //  4 bytes
            // PowerCap data sent from master to slaves
            pcap_config_data_t pcap;                // 14 bytes
            // PowerPreservingBoundry Fmax to throttle all OCCs the same
            uint16_t ppb_fmax;                      //  2 bytes
            // GPIO pins from APSS
            uint16_t gpio[2];                       //  4 bytes
            // Raw ADC Channels from APSS
            uint16_t adc[MAX_APSS_ADC_CHANNELS];    // 32 bytes
            // Reserved
            uint8_t  _reserved_0[4];                //  4 bytes
            // Time of Day Clock from the last APSS reading
            uint64_t tod;                           //  8 bytes
            // Reserved
            uint8_t  _reserved_1[52];               // 52 bytes
            // Counter in case we want to determine sequence errors
            uint8_t  magic_counter;                 //  1 byte
            // Magic Number for denoting the end of the packet
            uint32_t magic2                :24;     //  3 bytes
        };                                          // --------
        uint64_t words[16];                // Total = 128 bytes
    };
} __attribute__ ((packed)) dcom_slv_inbox_doorbell_t;

// Slave Outbox Doorbell
typedef struct
{
    pob_id_t  pob_id;
    uint8_t   pcap_valid;
    uint16_t  active_node_pcap;
    uint32_t  addr_slv_outbox_buffer;
} __attribute__ ((packed)) dcom_slv_outbox_doorbell_t;

typedef enum
{
    SLAVE_INBOX     = 0,
    SLAVE_OUTBOX

} dcom_error_type_t;

typedef struct
{
    uint32_t totalTicks;
    uint32_t totalSuccessful;
    uint16_t currentFailCount;
} dcom_fail_count_t;

typedef struct
{
    /// Mask denoting if OCC is currently responding
    uint8_t alive;
    /// Mask denoting if OCC has responded in the past, but stopped
    uint8_t zombie;
    /// Mask denoting if OCC has never responded
    uint8_t dead;
} dcom_present_mask_t;

// DCOM Timing / Statistics
//   This is a DEBUG ONLY structure that is only used to measure certain
//   characteristics of the distributed communication mechanism.
//   It may be removed at any time without warning.
//
//   For Reference:
//      Phase(degrees) = (((SsxTimebase % 250us) / 250us) * 360 degrees)
typedef struct
{
    // Master Only Statistics
    struct
    {
        // Start Time of the Most Recent Master Doorbell Broadcast
        SsxTimebase doorbellStartTx;
        // Stop Time of the Most Recent Master Doorbell Broadcast
        SsxTimebase doorbellStopTx;
        // The longest it has even taken to send the Master Doorbell Broadcast
        SsxTimebase doorbellMaxDeltaTx;
        // How many Master Doorbell Broadcasts have been sent
        uint32_t    doorbellNumSent;
        // What is our "send" phase in relation to our SsxTimebase
        uint16_t    doorbellPhase;
        // The Most Recent Master Doorbell Broadcast sequence number
        uint8_t     doorbellSeq;
        // Masks of the current status of the slaves
        dcom_present_mask_t allOccStatusMask;
    } master;
    // Slave Statistics
    struct
    {
        // Start Time of the Most Recent Wait for Master Doorbell
        SsxTimebase doorbellStartWaitRx;
        // Successful Stop Time of the Most Recent Wait for Master Doorbell
        SsxTimebase doorbellStopWaitRx;
        // Timeout Stop Time of the Most Recent Wait for Master Doorbell
        SsxTimebase doorbellTimeoutWaitRx;
        // The longest it has ever taken us to receive Master Doorbell
        SsxTimebase doorbellMaxDeltaWaitRx;
        // Start Time of the Most Recent Slave Doorbell sent to Master
        SsxTimebase doorbellStartRx;
        // Stop Time of the Most Recent Slave Doorbell sent to Master
        SsxTimebase doorbellStopRx;
        // The longest it has ever taken us to send Slave Doorbell
        SsxTimebase doorbellMaxDeltaRx;
        // How many Master Doorbell Broadcasts have we received
        uint32_t    doorbellNumRx;
        // How many Master Doorbell Broadcasts have we received via wait4master
        uint32_t    doorbellNumWaitRx;
        // "Receive Phase" of Master Doorbell in relation to our SsxTimebase
        uint16_t    doorbellPhase;
        // Most Recent Sequence number received from Master Doorbell
        uint8_t     doorbellSeq;
        // Error Flags for receiving Master Doorbell (never cleared)
        struct
        {
            uint8_t timeout     :1;
            uint8_t incomplete  :1;
            uint8_t badSequence :1;
            uint8_t badMagicNumEnd  :1;
            uint8_t dropPacket  :1;
            uint8_t hwError     :1;
            uint8_t timeoutRx   :1;
        } doorbellErrorFlags;
    } slave;

    // General Timing
    // Used to calculate the difference between the SsxTimebase and the TOD,
    // to correlate between multiple OCCs.
    SsxTimebase base;
    uint64_t    tod;

} dcom_timing_t;
extern dcom_timing_t G_dcomTime;

// Used to tell AMEC code that the slave inbox has been received.
// This could just be a flag, doesn't have to be semaphore, since
// the RTL Loop task can't block on Semaphore, it would just have
// to loop until it got a good return code.
extern bool G_slv_inbox_received;

// Used to tell AMEC code that the slave outbox has been received.
// This could just be a flag, doesn't have to be semaphore, since
// the RTL Loop task can't block on Semaphore, it would just have
// to loop until it got a good return code.
extern uint8_t G_slv_outbox_complete;

// Specifies if the OCC is a MASTER or SLAVE
extern uint8_t G_occ_role;

// Holds PowerBus ID of this OCC (Chip & node). For P9, this is the same
// for pob_id and PBAX ID.
extern pob_id_t G_pbax_id;

// PBAX 'Target' Structure (Register Abstraction) that has the data needed for
// a multicast operation.
extern PbaxTarget  G_pbax_multicast_target;

// PBAX 'Target' Structure (Register Abstraction) that has the data needed for
// a unicast operation from the OCC Slave to the OCC Master.
extern PbaxTarget  G_pbax_unicast_target;

// Number of occ's that *should* be present
extern uint8_t G_occ_num_present;

// Master/slave event flags
extern uint32_t G_master_event_flags;
extern uint32_t G_slave_event_flags;
extern uint32_t G_master_event_flags_ack;
extern uint32_t G_slave_event_flags_ack[MAX_OCCS];

extern dcom_fail_count_t G_dcomSlvInboxCounter;

extern SsxSemaphore G_dcomThreadWakeupSem;

// =========================================================
// Master Only
// =========================================================

// Used to house the actuation & power measurement data from the master
// before it is DMA'd to Main Memory from SRAM.
extern dcom_slv_inbox_t  G_dcom_slv_inbox_tx[MAX_OCCS];

// Used to house the Slave Outboxes with the mini-sensor data in in the master
// after it is DMA'd from main memory.
extern dcom_slv_outbox_t G_dcom_slv_outbox_rx[MAX_OCCS];

// =========================================================
// Master & Slave
// =========================================================

// Used to house the actuation & power measurement data coming from the master
// after it is DMA'd from Main Memory to SRAM.
extern dcom_slv_inbox_t G_dcom_slv_inbox_rx;

// Used to house the Slave Outboxes with the mini-sensor data in the slave
// before it is DMA'd to main memory.
//DMA_BUFFER(extern dcom_slv_outbox_t G_dcom_slv_outbox_tx);  // Slave
extern dcom_slv_outbox_t G_dcom_slv_outbox_tx;  // Slave

// Used to house the pcap & power measurement data coming from the master
// in a more reliable way than Main Memory
extern dcom_slv_inbox_doorbell_t G_dcom_slv_inbox_doorbell_rx;

// Check if slave inbox is valid, or if we are having errors
bool isDcomSlvInboxValid(void);

// Copy data into slave inbox for use by master
uint32_t dcom_build_slv_inbox(void);

// Fill out sensor data from slave to master
uint32_t dcom_build_slv_outbox(void);

// Switch between ping pong buffers
uint32_t dcom_which_buffer(void);

// Switch between ping pong buffers
uint32_t dcom_which_buffer_slv_outbox(void);

// Get address of slave inbox in main memory
uint32_t dcom_calc_slv_inbox_addr(void);

// Get address of slave outbox in main memory
uint32_t dcom_calc_slv_outbox_addr( const dcom_slv_outbox_doorbell_t * i_doorbell, uint8_t * o_occ_id);

// Determine if we are master or slave
void dcom_initialize_roles(void) INIT_SECTION;

// Copy slave inbox from main memory to sram
void task_dcom_rx_slv_inbox(task_t *i_self);

// Copy slave outboxes from main memory to sram
void task_dcom_rx_slv_outboxes(task_t *i_self);

// Copy slave inboxes from sram to main memory
void task_dcom_tx_slv_inbox(task_t *i_self);

// Copy slave outboxes from sram to main memory
void task_dcom_tx_slv_outbox(task_t *i_self);

// Initialize the pbax queues
void dcom_initialize_pbax_queues(void);

// Receive multicast doorbell
uint32_t dcom_rx_slv_inbox_doorbell( void );

// Receive unicast doorbell
uint32_t dcom_rx_slv_outbox_doorbell( void );

// Send multicast doorbells to slaves
void dcom_tx_slv_inbox_doorbell( void );

// Send unicast doorbells to master
void dcom_tx_slv_outbox_doorbell( void );

// Task to wait for the master multicast doorbell
void task_dcom_wait_for_master( task_t *i_self);

// Keep track of failure counts
#define dcom_error_check_reset(_e_) dcom_error_check( _e_, TRUE, OCC_SUCCESS_REASON_CODE, OCC_NO_EXTENDED_RC)
void dcom_error_check( dcom_error_type_t i_error_type, bool i_clear_error, uint32_t i_orc , const uint32_t i_orc_ext);

// Task to parse occ firmware messages
void task_dcom_parse_occfwmsg(task_t *i_self);

// Copy occ fw msg
void dcom_build_occfw_msg( dcom_error_type_t i_which_msg );

#endif //_DCOM_H
