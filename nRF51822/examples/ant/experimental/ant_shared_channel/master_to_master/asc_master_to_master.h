/*
This software is subject to the license described in the License.txt file
included with this software distribution. You may not use this file except in compliance
with this license.

Copyright (c) Dynastream Innovations Inc. 2014
All rights reserved.
*/

/**@file
 * @defgroup asc_multimaster module
 * @{
 * @ingroup ant_auto_shared_channel
 *
 * @brief ANT Auto Shared Channel (ASC)Multi-master implementation.
 */

#ifndef ASC_MASTER_TO_MASTER_H__
#define ASC_MASTER_TO_MASTER_H__

#include <stdint.h>
#include "asc_parameters.h"

#ifdef __cplusplus
extern "C" {
#endif

/**@brief Enumeration defining the possible states of an ASC Multi-master.
 */
typedef enum
{
    ASCMM_OFF = 0,      /**< ASC Multi-master State: OFF. The ASC Multi-master is neither connected to, nor searching for, other ASC Masters.*/
    DISCOVERY,          /**< ASC Multi-master State: DISCOVERY. The ASC Multi-master is searching for other ASC Masters.*/
    CONNECTED,          /**< ASC Multi-master State: CONNECTED. The ASC Multi-master is connected to another ASC Master.*/
} ascmm_states_t;


/**@brief Function for initializing the ASC Multi-master.
 *
 * @param[in] p_ant_discovery_parameters    Pointer to the ANT channel parameters used to assign and configure the discovery channel.
 *                                          The device number and channel type contained in this struct are ignored by the module.
 *
 * @param[in] p_ant_connection_parameters   Pointer to the ANT channel parameters used to create the master to master channel.
 *                                          The device number and channel type contained in this struct are ignored by the module.
 *
 * @param[in] device_number                 The device number to use when determining whether this device should be an ASCMM Master or Slave.
 */
void ascmm_init(const asc_ant_params_t * const p_ant_discovery_parameters,
                const asc_ant_params_t * const p_ant_connection_parameters,
                uint16_t device_number);


/**@brief Function to turn on the ASC Multi-master and begin the discovery process.
 */
void ascmm_turn_on(void);


/**@brief Function to handle received ANT messages on the ASC Multi-master channel.
 *
 * @param[in] event The ANT event type that was received.
 *
 * @param[in] p_event_message_buffer The received message buffer.
 */
void ascmm_handle_ant_event(uint8_t event, uint8_t * p_event_message_buffer);


/**@brief Function to pass an ant message over the master to master channel.
 *
 * @param[in] p_tx_buffer       The raw ANT data to send over the air.
 *
 * @param[in] retries           The number of times that the message will be relayed.
 *
 * @param[in] maximum_retries   The number of times that the message will be sent over the air.
 */
void ascmm_relay_message(uint8_t * p_tx_buffer, uint8_t retries);


/**@brief Function to get the current ASC Multi-master state.
 *
 * @return A copy of the current ASC Multi-master state.
 */
ascmm_states_t ascmm_state_get(void);


/**@brief Function to get the ASC Multi-master event bitfield.
 *
 * @note After using this function and checking for an event, be sure to clear that event immediately.
 *
 * @return A copy of the current event bitfield.
 */
uint32_t ascmm_events_get(void);


/**@brief Clears the specified event from the event bitfield.
 *
 * @param[in] event The ASC event to clear from the bitfield.
 */
void ascmm_event_clear(uint32_t event);


/**@brief Gets the device number of the connected master device
 *
 * @return The device number of the connected master device
 */
uint16_t ascmm_get_neighbor_id(void);


/**@brief Gets the last command received on the master to master channel.
 *
 * @return A copy of the last command received on the master to master channel.
 */
asc_command_data_t ascmm_get_last_command(void);


/**@brief Gets the last update received on the master to master channel.
 *
 * @return A copy of the last update received on the master to master channel.
 */
asc_update_data_t ascmm_get_last_update(void);

#ifdef __cplusplus
}
#endif

#endif /* ASC_MASTER_TO_MASTER_H__ */

/** @} */
