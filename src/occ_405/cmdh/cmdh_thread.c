/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/occ_405/cmdh/cmdh_thread.c $                              */
/*                                                                        */
/* OpenPOWER OnChipController Project                                     */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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

#include "ssx.h"
#include "ssx_io.h"
#include "simics_stdio.h"
#include "errl.h"
#include "trac.h"
#include <thread.h>
#include <threadSch.h>
#include "state.h"
#include <cmdh_fsp.h>

extern uint8_t G_occ_interrupt_type;

eCmdhWakeupThreadMask G_cmdh_thread_wakeup_mask;

// Function Specification
//
// Name: Cmd_Hndl_thread_routine
//
// Description: This needs to be moved to separate file after we add cmd handler
//              thread support
//
// End Function Specification
void Cmd_Hndl_thread_routine(void *arg)
{
#define OCC_RESP_READY_ALERT_TIMEOUT_ATTEMPTS 5
    int l_rc = 0;
    errlHndl_t l_errlHndl = NULL;

    CHECKPOINT(CMDH_THREAD_STARTED);
    CMDH_TRAC_INFO("Command Handler Thread Started ... " );

    // ------------------------------------------------
    // Initialize HW for FSP Comm
    // ------------------------------------------------
    l_errlHndl = cmdh_fsp_init();
    if(l_errlHndl)
    {
        // Mark Errl as committed, so FSP knows right away we are having
        // problems with Attention, if that is the cause of the error.

        commitErrl(&l_errlHndl);
    }
    else    // Mark the Checkpoint only if no error was logged
    {
        CHECKPOINT(FSP_COMM_INITIALIZED);
    }

    // ------------------------------------------------
    // Loop forever, handling FSP commands
    // ------------------------------------------------
    while(1)
    {
        // ------------------------------------------------
        // Block, Waiting on sem for a doorbell from FSP
        // ------------------------------------------------
        l_rc = cmdh_thread_wait_for_wakeup(); // Blocking Call

        // ------------------------------------------------
        // Handle the command
        // ------------------------------------------------
        if(SSX_OK == l_rc)
        {
            // Handle the command that TMGT just sent to OCC
            if( CMDH_WAKEUP_FSP_COMMAND & G_cmdh_thread_wakeup_mask )
            {
                clearCmdhWakeupCondition(CMDH_WAKEUP_FSP_COMMAND);


                l_errlHndl = cmdh_fsp_cmd_hndler();

                // Commit an error if we get one passed back, do it before
                // we tell the FSP we have a response ready
                if(NULL != l_errlHndl)
                {
                    commitErrl(&l_errlHndl);
                }
            }
        }
    }

}
