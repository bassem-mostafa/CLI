// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "CLI.h"
#include "CLI_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

CLI_Status_t CLI_Initialize( CLI_t CLIx )
{
    CLI_Status_t Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( CLIx=%d )", __FUNCTION__, CLIx );

        if ( ( Status = CLI_Port_Initialize( CLIx ) ) != CLI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

CLI_Status_t CLI_Cycle( CLI_t CLIx )
{
    CLI_Status_t Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( CLIx=%d )", __FUNCTION__, CLIx );

        if ( ( Status = CLI_Port_Cycle( CLIx ) ) != CLI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

CLI_Status_t CLI_DeInitialize( CLI_t CLIx )
{
    CLI_Status_t Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( CLIx=%d )", __FUNCTION__, CLIx );

        if ( ( Status = CLI_Port_DeInitialize( CLIx ) ) != CLI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

CLI_Status_t CLI_Add( CLI_t CLIx, CLI_Command_t * Command, CLI_Command_t * Command_Sub )
{
    CLI_Status_t Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( CLIx=%d, Command=%p, SubCommand=%p )", __FUNCTION__, CLIx, Command, Command_Sub );

        if ( Command_Sub == NULL )
        {
            Status = CLI_Status_ArgumentInvalid;
            break;
        }

        if ( ( Status = CLI_Port_Add( CLIx, Command, Command_Sub ) ) != CLI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

CLI_Status_t CLI_Remove( CLI_t CLIx, CLI_Command_t * Command )
{
    CLI_Status_t Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( CLIx=%d, Command=%p )", __FUNCTION__, CLIx, Command );

        if ( Command == NULL )
        {
            Status = CLI_Status_ArgumentInvalid;
            break;
        }

        if ( ( Status = CLI_Port_Remove( CLIx, Command ) ) != CLI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

CLI_Status_t CLI_List( CLI_t CLIx, CLI_Command_t * Command )
{
    CLI_Status_t Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( CLIx=%d, Command=%p )", __FUNCTION__, CLIx, Command );

        if ( ( Status = CLI_Port_List( CLIx, Command ) ) != CLI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

CLI_Status_t CLI_Write( CLI_t CLIx, CLI_Data_t * Data, CLI_DataLength_t DataLength )
{
    CLI_Status_t Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( CLIx=%d, Data=%p, Length=%d )", __FUNCTION__, CLIx, Data, DataLength );

        if ( Data == NULL || DataLength < 1 )
        {
            Status = CLI_Status_ArgumentInvalid;
            break;
        }

        if ( ( Status = CLI_Port_Write( CLIx, Data, DataLength ) ) != CLI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char CLI_VERSION[] = "0.0.0.v20261012-0036";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
