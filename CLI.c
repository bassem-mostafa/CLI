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

static CLI_Status_t CLI_Context_Initialize( void );
static CLI_Status_t CLI_Context_DeInitialize( void );
static CLI_Status_t CLI_Context_Cycle( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static CLI_Status_t CLI_Context_Initialize( void )
{
    CLI_Status_t CLI_Status = CLI_Status_Error;
    do
    {
        CLI_Trace( "%s( void )", __FUNCTION__ );
        for ( CLI_t CLI = CLI_1; CLI < CLI_NUMBER_OF_INSTANCES; ++CLI )
        {
            CLI_Context.Instance[ CLI ].CLI = CLI;
            if ( ( CLI_Status = CLI_Instance_Initialize( &CLI_Context.Instance[ CLI ] ) ) != CLI_Status_Success )
            {
                CLI_Warning( "CLI_%d Initialize Failed: Status %d", CLI, CLI_Status );
            }
        }
        CLI_Status = CLI_Status_Success;
    }
    while ( 0 );
    return CLI_Status;
}

static CLI_Status_t CLI_Context_DeInitialize( void )
{
    CLI_Status_t CLI_Status = CLI_Status_Error;
    do
    {
        CLI_Trace( "%s( void )", __FUNCTION__ );
        for ( CLI_t CLI = CLI_1; CLI < CLI_NUMBER_OF_INSTANCES; ++CLI )
        {
            if ( ( CLI_Status = CLI_Instance_DeInitialize( &CLI_Context.Instance[ CLI ] ) ) != CLI_Status_Success )
            {
                CLI_Warning( "CLI_%d DeInitialize Failed: Status %d", CLI, CLI_Status );
            }
        }
        CLI_Status = CLI_Status_Success;
    }
    while ( 0 );
    return CLI_Status;
}

static CLI_Status_t CLI_Context_Cycle( void )
{
    CLI_Status_t CLI_Status = CLI_Status_Error;
    do
    {
        CLI_Trace( "%s( void )", __FUNCTION__ );
        for ( CLI_t CLI = CLI_1; CLI < CLI_NUMBER_OF_INSTANCES; ++CLI )
        {
            if ( ( CLI_Status = CLI_Instance_Cycle( &CLI_Context.Instance[ CLI ] ) ) != CLI_Status_Success )
            {
                CLI_Warning( "CLI_%d Cycle Failed: Status %d", CLI, CLI_Status );
            }
        }
        CLI_Status = CLI_Status_Success;
    }
    while ( 0 );
    return CLI_Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

CLI_Status_t CLI_Initialize( void )
{
    CLI_Status_t CLI_Status = CLI_Status_Error;
    do
    {
        CLI_Trace( "%s( void )", __FUNCTION__ );
        CLI_Status = CLI_Context_Initialize( );
    }
    while ( 0 );
    return CLI_Status;
}

CLI_Status_t CLI_Cycle( void )
{
    CLI_Status_t CLI_Status = CLI_Status_Error;
    do
    {
        CLI_Trace( "%s( void )", __FUNCTION__ );
        CLI_Status = CLI_Context_Cycle( );
    }
    while ( 0 );
    return CLI_Status;
}

CLI_Status_t CLI_DeInitialize( void )
{
    CLI_Status_t CLI_Status = CLI_Status_Error;
    do
    {
        CLI_Trace( "%s( void )", __FUNCTION__ );
        CLI_Status = CLI_Context_DeInitialize( );
    }
    while ( 0 );
    return CLI_Status;
}

CLI_Status_t CLI_Add( CLI_t CLI, CLI_Command_t * CLI_Command_Root, CLI_Command_t * CLI_Command_Child )
{
    CLI_Status_t CLI_Status = CLI_Status_Error;
    do
    {
        CLI_Trace( "%s( CLI=CLI_%d, Root=%p, Child=%p )", __FUNCTION__, CLI, CLI_Command_Root, CLI_Command_Child );
        if ( CLI_Command_Child == NULL )
        {
            CLI_Status = CLI_Status_ArgumentInvalid;
            break;
        }
        if ( ( CLI_Status = CLI_IsValid( CLI ) ) != CLI_Status_Success )
        {
            break;
        }
        CLI_Instance_t * CLI_Instance = &CLI_Context.Instance[ CLI ];
        CLI_Status = CLI_Instance_Add( CLI_Instance, CLI_Command_Root, CLI_Command_Child );
    }
    while ( 0 );
    return CLI_Status;
}

CLI_Status_t CLI_Remove( CLI_t CLI, CLI_Command_t * CLI_Command )
{
    CLI_Status_t CLI_Status = CLI_Status_Error;
    do
    {
        CLI_Trace( "%s( CLI=CLI_%d, Command=%p )", __FUNCTION__, CLI, CLI_Command );
        if ( CLI_Command == NULL )
        {
            CLI_Status = CLI_Status_ArgumentInvalid;
            break;
        }
        if ( ( CLI_Status = CLI_IsValid( CLI ) ) != CLI_Status_Success )
        {
            break;
        }
        CLI_Instance_t * CLI_Instance = &CLI_Context.Instance[ CLI ];
        CLI_Status = CLI_Instance_Remove( CLI_Instance, CLI_Command );
    }
    while ( 0 );
    return CLI_Status;
}

CLI_Status_t CLI_List( CLI_t CLI, CLI_Command_t * CLI_Command )
{
    CLI_Status_t CLI_Status = CLI_Status_Error;
    do
    {
        CLI_Trace( "%s( CLI=CLI_%d, Command=%p )", __FUNCTION__, CLI, CLI_Command );
        if ( ( CLI_Status = CLI_IsValid( CLI ) ) != CLI_Status_Success )
        {
            break;
        }
        CLI_Instance_t * CLI_Instance = &CLI_Context.Instance[ CLI ];
        CLI_Status = CLI_Instance_List( CLI_Instance, CLI_Command );
    }
    while ( 0 );
    return CLI_Status;
}

CLI_Status_t CLI_Write( CLI_t CLI, CLI_Data_t * CLI_Data, CLI_DataLength_t CLI_DataLength )
{
    CLI_Status_t CLI_Status = CLI_Status_Error;
    do
    {
        CLI_Trace( "%s( CLI=CLI_%d, Data=%p, Length=%d )", __FUNCTION__, CLI, CLI_Data, CLI_DataLength );
        if ( CLI_Data == NULL
             || CLI_DataLength < 1 )
        {
            CLI_Status = CLI_Status_ArgumentInvalid;
            break;
        }
        if ( ( CLI_Status = CLI_IsValid( CLI ) ) != CLI_Status_Success )
        {
            break;
        }
        CLI_Instance_t * CLI_Instance = &CLI_Context.Instance[ CLI ];
        CLI_Status = CLI_Instance_Write( CLI_Instance, CLI_Data, CLI_DataLength );
    }
    while ( 0 );
    return CLI_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char CLI_VERSION[] = "0.0.0.v20260117-1036";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
