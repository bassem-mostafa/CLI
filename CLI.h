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

/**
 *  @file
 *
 *  @brief Platform CLI Service
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Service
 *
 *  @{
 */

/**
 *  @defgroup Platform_CLI CLI
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

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

    #include <stdint.h>

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief CLI Operation Status
     *
     *  @enum CLI_Status_t
     */
    typedef enum CLI_Status
    {
        CLI_Status_Success = 0,     ///< Success
        CLI_Status_ArgumentInvalid, ///< Argument Invalid
        CLI_Status_NotSupported,    ///< Not Supported
        CLI_Status_Error,           ///< General Error
        CLI_Status_Busy,            ///< Busy
        CLI_Status_Timeout,         ///< Timeout
    } CLI_Status_t;

    /**
     * @brief CLI Command (Forward declaration)
     *
     * @struct CLI_Command_t
     */
    typedef struct CLI_Command CLI_Command_t;

    /**
     *  @brief CLI Command
     *
     *  @struct CLI_Command_t
     */
    typedef struct CLI_Command
    {
        /**
         * @brief Name of executable
         */
        const char * Name;

        /**
         * @brief Help description
         */
        const char * Help;

        /**
         * @brief Execute callback
         *
         * @param[in] argc Number of provided arguments
         * @param[in] argv Values of provided arguments
         *
         * @return CLI_Status_t
         */
        CLI_Status_t ( *Execute )( int argc, char ** argv );

        // Managed Internally
        CLI_Command_t * Parent;
        LIST_Node_t Node;
        LIST_t SubCommands;
    } CLI_Command_t;

    /**
     *  @brief CLI Data
     */
    typedef uint8_t CLI_Data_t;

    /**
     *  @brief CLI Data Length
     */
    typedef uint32_t CLI_DataLength_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize command line interface
     *
     *  @note MUST BE called before using any CLI API
     *
     *  @param[in] CLIx Interface
     *
     *  @return CLI_Status_t
     */
    CLI_Status_t CLI_Initialize( CLI_t CLIx );

    /**
     *  @brief Cycle command line interface
     *
     *  @param[in] CLIx Interface
     *
     *  @return CLI_Status_t
     */
    CLI_Status_t CLI_Cycle( CLI_t CLIx );

    /**
     *  @brief DeInitialize command line interface
     *
     *  @param[in] CLIx Interface
     *
     *  @return CLI_Status_t
     */
    CLI_Status_t CLI_DeInitialize( CLI_t CLIx );

    /**
     *  @brief Add command to command line interface
     *
     *  @warning Adding SAME command more than ONCE or to multiple CLIs IS NOT supported
     *
     *  @param[in] CLIx        Interface
     *  @param[in] Command     Command, NULL for root
     *  @param[in] Command_Sub Sub-Command to be added to Command
     *
     *  @return CLI_Status_t
     */
    CLI_Status_t CLI_Add( CLI_t CLIx, CLI_Command_t * Command, CLI_Command_t * Command_Sub );

    /**
     *  @brief Remove command from command line interface
     *
     *  @param[in] CLIx     Interface
     *  @param[in] Command  Command instance
     *
     *  @return CLI_Status_t
     */
    CLI_Status_t CLI_Remove( CLI_t CLIx, CLI_Command_t * Command );

    /**
     *  @brief List commands exists in command line interface
     *
     *  @param[in] CLIx     Interface
     *  @param[in] Command  Start from Command, NULL for root
     *
     *  @return CLI_Status_t
     */
    CLI_Status_t CLI_List( CLI_t CLIx, CLI_Command_t * Command );

    /**
     *  @brief Write data to command line interface
     *
     *  @param[in] CLIx       Interface
     *  @param[in] Data       Data
     *  @param[in] DataLength Length
     *
     *  @return CLI_Status_t
     */
    CLI_Status_t CLI_Write( CLI_t CLIx, CLI_Data_t * Data, CLI_DataLength_t DataLength );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char CLI_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* CLI_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
