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

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef CLI_H_
    #define CLI_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "CLI_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum CLI_Status
    {
        CLI_Status_Success = 0,
        CLI_Status_ArgumentInvalid,
        CLI_Status_Not_Supported,
        CLI_Status_Error,
        CLI_Status_Busy,
        CLI_Status_Timeout,
    } CLI_Status_t;

    typedef struct CLI_Command_Context CLI_Command_Context_t;

    typedef struct CLI_Command
    {
        const char * Name;
        const char * Help;
        CLI_Status_t ( *Execute )( int argc, char ** argv );

        // Managed Internally
        CLI_Command_Context_t * Context;
    } CLI_Command_t;

    typedef uint8_t CLI_Data_t;

    typedef uint32_t CLI_DataLength_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    CLI_Status_t CLI_Initialize( CLI_t CLIx );
    CLI_Status_t CLI_Cycle( CLI_t CLIx );
    CLI_Status_t CLI_DeInitialize( CLI_t CLIx );

    CLI_Status_t CLI_Add( CLI_t CLIx, CLI_Command_t * Command_Root, CLI_Command_t * Command_Child );
    CLI_Status_t CLI_Remove( CLI_t CLIx, CLI_Command_t * Command );
    CLI_Status_t CLI_List( CLI_t CLIx, CLI_Command_t * Command );

    CLI_Status_t CLI_Write( CLI_t CLIx, CLI_Data_t * Data, CLI_DataLength_t DataLength );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    extern const char CLI_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* CLI_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
