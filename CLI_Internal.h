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

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef CLI_INTERNAL_H_
    #define CLI_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "CLI_Port.h"

    #include <stdint.h>

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef CLI_TIM
        #define CLI_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef CLI_LOG
        #define CLI_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define CLI_NAME       "CLI"
    #define CLI_LOG_PREFIX UTIL_StringConcatenateConstant( CLI_NAME, "> " )

    #ifdef DEBUG
        #define CLI_Raw( Level, Format, ... ) LOG_Raw( CLI_LOG, Level, Format, ##__VA_ARGS__ )
        #define CLI_Trace( Format, ... )      LOG_Trace( CLI_LOG, UTIL_StringConcatenateConstant( CLI_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define CLI_Debug( Format, ... )      LOG_Debug( CLI_LOG, UTIL_StringConcatenateConstant( CLI_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define CLI_Info( Format, ... )       LOG_Info( CLI_LOG, UTIL_StringConcatenateConstant( CLI_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define CLI_Warning( Format, ... )    LOG_Warning( CLI_LOG, UTIL_StringConcatenateConstant( CLI_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define CLI_Error( Format, ... )      LOG_Error( CLI_LOG, UTIL_StringConcatenateConstant( CLI_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define CLI_Fatal( Format, ... )      LOG_Fatal( CLI_LOG, UTIL_StringConcatenateConstant( CLI_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define CLI_Raw( Level, Format, ... )
        #define CLI_Trace( Format, ... )
        #define CLI_Debug( Format, ... )
        #define CLI_Info( Format, ... )
        #define CLI_Warning( Format, ... )
        #define CLI_Error( Format, ... )
        #define CLI_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef struct CLI_Instance_Context CLI_Instance_Context_t;

    typedef struct CLI_Instance
    {
        CLI_t CLIx;

        union
        {
            CLI_Instance_Context_t * Context;
        };
    } CLI_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    CLI_Status_t CLI_IsValid( CLI_t CLI );

    CLI_Status_t CLI_Instance_Initialize( CLI_Instance_t * Instance );
    CLI_Status_t CLI_Instance_Cycle( CLI_Instance_t * Instance );
    CLI_Status_t CLI_Instance_DeInitialize( CLI_Instance_t * Instance );

    CLI_Status_t CLI_Instance_Add( CLI_Instance_t * Instance, CLI_Command_t * Command_Root, CLI_Command_t * Command_Child );
    CLI_Status_t CLI_Instance_Remove( CLI_Instance_t * Instance, CLI_Command_t * Command );
    CLI_Status_t CLI_Instance_List( CLI_Instance_t * Instance, CLI_Command_t * Command );

    CLI_Status_t CLI_Instance_Read( CLI_Instance_t * Instance );
    CLI_Status_t CLI_Instance_Write( CLI_Instance_t * Instance, CLI_Data_t * Data, CLI_DataLength_t DataLength );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* CLI_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
