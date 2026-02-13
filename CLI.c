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

typedef struct CLI_Context
{
    CLI_Instance_t Instance[ CLI_Count ];
} CLI_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static CLI_Status_t CLI_Context_Initialize( void );
static CLI_Status_t CLI_Context_Cycle( void );
static CLI_Status_t CLI_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static CLI_Context_t CLI_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static CLI_Status_t CLI_Context_Initialize( void )
{
    CLI_Status_t Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( void )", __FUNCTION__ );

        for ( CLI_t CLI_x = CLI_1; CLI_x < CLI_Count; ++CLI_x )
        {
            CLI_Context.Instance[ CLI_x ].CLIx = CLI_x;
        }
    }
    while ( 0 );

    return Status;
}

static CLI_Status_t CLI_Context_Cycle( void )
{
    CLI_Status_t Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( void )", __FUNCTION__ );
    }
    while ( 0 );

    return Status;
}

static CLI_Status_t CLI_Context_DeInitialize( void )
{
    CLI_Status_t Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( void )", __FUNCTION__ );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

CLI_Status_t CLI_Initialize( CLI_t CLIx )
{
    CLI_Status_t Status = CLI_Status_Success;
    CLI_Status_t CLI_Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( CLIx=%d )", __FUNCTION__, CLIx );

        if ( ( Status = CLI_IsValid( CLIx ) ) != CLI_Status_Success )
        {
            break;
        }

        if ( ( Status = CLI_Context_Initialize( ) ) != CLI_Status_Success )
        {
            break;
        }

        for ( CLI_t CLI_x = CLI_Null; CLI_x < CLI_Count; ++CLI_x )
        {
            if ( CLIx != CLI_All && CLIx != CLI_x )
            {
                continue;
            }

            if ( ( CLI_Status = CLI_Instance_Initialize( &CLI_Context.Instance[ CLI_x ] ) ) != CLI_Status_Success )
            {
                Status = CLI_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

CLI_Status_t CLI_Cycle( CLI_t CLIx )
{
    CLI_Status_t Status = CLI_Status_Success;
    CLI_Status_t CLI_Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( CLIx=%d )", __FUNCTION__, CLIx );

        if ( ( Status = CLI_IsValid( CLIx ) ) != CLI_Status_Success )
        {
            break;
        }

        if ( ( Status = CLI_Context_Cycle( ) ) != CLI_Status_Success )
        {
            break;
        }

        for ( CLI_t CLI_x = CLI_Null; CLI_x < CLI_Count; ++CLI_x )
        {
            if ( CLIx != CLI_All && CLIx != CLI_x )
            {
                continue;
            }

            if ( ( CLI_Status = CLI_Instance_Cycle( &CLI_Context.Instance[ CLI_x ] ) ) != CLI_Status_Success )
            {
                Status = CLI_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

CLI_Status_t CLI_DeInitialize( CLI_t CLIx )
{
    CLI_Status_t Status = CLI_Status_Success;
    CLI_Status_t CLI_Status = CLI_Status_Success;

    do
    {
        CLI_Trace( "%s( CLIx=%d )", __FUNCTION__, CLIx );

        if ( ( Status = CLI_IsValid( CLIx ) ) != CLI_Status_Success )
        {
            break;
        }

        for ( CLI_t CLI_x = CLI_Null; CLI_x < CLI_Count; ++CLI_x )
        {
            if ( CLIx != CLI_All && CLIx != CLI_x )
            {
                continue;
            }

            if ( ( CLI_Status = CLI_Instance_DeInitialize( &CLI_Context.Instance[ CLI_x ] ) ) != CLI_Status_Success )
            {
                Status = CLI_Status;
            }
        }

        if ( ( Status = CLI_Context_DeInitialize( ) ) != CLI_Status_Success )
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
        CLI_Trace( "%s( CLIx=%d, Root=%p, Child=%p )", __FUNCTION__, CLIx, Command, Command_Sub );

        if ( Command_Sub == NULL )
        {
            Status = CLI_Status_ArgumentInvalid;
            break;
        }

        if ( ( Status = CLI_IsValid( CLIx ) ) != CLI_Status_Success )
        {
            break;
        }

        Status = CLI_Instance_Add( &CLI_Context.Instance[ CLIx ], Command, Command_Sub );
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

        if ( ( Status = CLI_IsValid( CLIx ) ) != CLI_Status_Success )
        {
            break;
        }

        Status = CLI_Instance_Remove( &CLI_Context.Instance[ CLIx ], Command );
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

        if ( ( Status = CLI_IsValid( CLIx ) ) != CLI_Status_Success )
        {
            break;
        }

        Status = CLI_Instance_List( &CLI_Context.Instance[ CLIx ], Command );
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

        if ( ( Status = CLI_IsValid( CLIx ) ) != CLI_Status_Success )
        {
            break;
        }

        Status = CLI_Instance_Write( &CLI_Context.Instance[ CLIx ], Data, DataLength );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char CLI_VERSION[] = "0.0.0.v20260213-1224";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
