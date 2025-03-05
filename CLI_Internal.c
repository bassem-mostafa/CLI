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

#include <stddef.h>
#include <stdio.h>

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

LOG_Status_t CLI_LOG_Raw( LOG_Level_t LOG_Level, LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_RawWithArgs( CLI_LOG, LOG_Level, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t CLI_LOG_Trace( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_TraceWithArgs( CLI_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t CLI_LOG_Debug( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_DebugWithArgs( CLI_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t CLI_LOG_Info( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_InfoWithArgs( CLI_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t CLI_LOG_Warning( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_WarningWithArgs( CLI_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t CLI_LOG_Error( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_ErrorWithArgs( CLI_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t CLI_LOG_Fatal( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_FatalWithArgs( CLI_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

CLI_Status_t CLI_Instance_IsValid( CLI_Instance_t * CLI_Instance )
{
    CLI_Status_t CLI_Status = CLI_Status_Error;
    do
    {
        CLI_Trace( "%s( Instance=%p )", __FUNCTION__, CLI_Instance );
        if ( CLI_Instance == NULL )
        {
            CLI_Error( "Invalid Argument" );
            CLI_Status = CLI_Status_ArgumentInvalid;
            break;
        }
        CLI_Status = CLI_Status_Error;
        for ( CLI_t CLI = CLI_Null; CLI < CLI_NUMBER_OF_INSTANCES; ++CLI )
        {
            if ( CLI_Instance == &CLI_Context.Instance[ CLI ] )
            {
                CLI_Status = CLI_Status_Success;
                break;
            }
        }
        if ( CLI_Status != CLI_Status_Success )
        {
            CLI_Error( "Invalid Reference" );
            CLI_Status = CLI_Status_Error;
            break;
        }
        CLI_Status = CLI_Status_Success;
    }
    while ( 0 );
    return CLI_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

CLI_Context_t CLI_Context;

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
