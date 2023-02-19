//########################################################################
//  Project     :   driver_g140v2
//  Target      :
//------------------------------------------------------------------------
//  Filename    :   globals.h
//  Author      :   lucag
//  Date        :   9 Dec 2022
//------------------------------------------------------------------------
//  History     :
//  9 Dec 2022      - Creation
//
//------------------------------------------------------------------------
//!  Description:    xxx
//!
//
//########################################################################

#ifndef INC_PARAM_PROCESS_DATA_H_
#define INC_PARAM_PROCESS_DATA_H_

#include "stdint.h"


/* ## COMMON Section ################################################## */
/* ## These defines are visibles in all files                           */
/* #################################################################### */

/* ## COMMON Defines ################################################## */

/* Data */
struct DATA {
    uint32_t id;
    uint16_t group;
    uint16_t num_byte;
    void *val;
    //void *lim_max;
    //void *lim_min;
};

/**
 * USART Msg Structure:
 *
 * idx: [0]   [1]   [2]     [3]     [4]     [5]     [6]   [7]        [8]     [9]
 *      ---------------------------------------------------------------------------
 *      | ID1 | ID0 | DATA3 | DATA2 | DATA1 | DATA0 | STS | ARTIFACT | CHKSM | LF |
 *      ---------------------------------------------------------------------------
 */
#define CAN_ADDRESS_LENGTH              2
#define CAN_DATA_LENGTH                 4
#define USART_ARTIFACT                  1
#define USART_STS                       1
#define USART_CHECKSUM                  1
#define USART_LF                        1
#define USART_MSG_LENGTH                10/*CAN_ADDRESS_LENGTH + \
                                        CAN_DATA_LENGTH + \
                                        USART_ARTIFACT + \
                                        USART_STS + \
                                        USART_CHECKSUM + \
                                        USART_LF*/

/* ========================================================= *
 * SERVICE DEVICE OBJECT (SDO)
 * ========================================================= */

#define SDO_LENGTH 24

#define ID_SDO_00 0x0200
#define ID_SDO_01 0x0201
#define ID_SDO_02 0x0202
#define ID_SDO_03 0x0203
#define ID_SDO_04 0x0204
#define ID_SDO_05 0x0205
#define ID_SDO_06 0x0206
#define ID_SDO_07 0x0207
#define ID_SDO_08 0x0208
#define ID_SDO_09 0x0209
#define ID_SDO_10 0x020A
#define ID_SDO_11 0x020B
#define ID_SDO_12 0x020C
#define ID_SDO_13 0x020D
#define ID_SDO_14 0x020E
#define ID_SDO_15 0x020F
#define ID_SDO_16 0x0210
#define ID_SDO_17 0x0211
#define ID_SDO_18 0x0212
#define ID_SDO_19 0x0213
#define ID_SDO_20 0x0214
#define ID_SDO_21 0x0215
#define ID_SDO_22 0x0216
#define ID_SDO_23 0x0217

#define ID_SDO_00_BYTE 2
#define ID_SDO_01_BYTE 2
#define ID_SDO_02_BYTE 2
#define ID_SDO_03_BYTE 2
#define ID_SDO_04_BYTE 4
#define ID_SDO_05_BYTE 4
#define ID_SDO_06_BYTE 4
#define ID_SDO_07_BYTE 2
#define ID_SDO_08_BYTE 4
#define ID_SDO_09_BYTE 4
#define ID_SDO_10_BYTE 4
#define ID_SDO_11_BYTE 4
#define ID_SDO_12_BYTE 4
#define ID_SDO_13_BYTE 4
#define ID_SDO_14_BYTE 4
#define ID_SDO_15_BYTE 4
#define ID_SDO_16_BYTE 4
#define ID_SDO_17_BYTE 4
#define ID_SDO_18_BYTE 4
#define ID_SDO_19_BYTE 4
#define ID_SDO_20_BYTE 4
#define ID_SDO_21_BYTE 4
#define ID_SDO_22_BYTE 4
#define ID_SDO_23_BYTE 2

typedef enum {
    CTRL_INPUT = 0,
    SCR_SETTINGS = 2,
    IGBT_SETTINGS = 3,
    ADC_SETTINGS = 1,
    PROTECTION = 4
} SDO_GROUP;

/* ========================================================= *
 * PROCESS DATA OBJECT (PDO)
 * ========================================================= */

#define PDO_LENGTH 14

#define ID_PDO_00 0x0100
#define ID_PDO_01 0x0101
#define ID_PDO_02 0x0102
#define ID_PDO_03 0x0103
#define ID_PDO_04 0x0104
#define ID_PDO_05 0x0105
#define ID_PDO_06 0x0106
#define ID_PDO_07 0x0107
#define ID_PDO_08 0x0108
#define ID_PDO_09 0x0109
#define ID_PDO_10 0x010A
#define ID_PDO_11 0x010B
#define ID_PDO_12 0x010C
#define ID_PDO_13 0x010D

#define ID_PDO_00_BYTE 2
#define ID_PDO_01_BYTE 2
#define ID_PDO_02_BYTE 4
#define ID_PDO_03_BYTE 4
#define ID_PDO_04_BYTE 4
#define ID_PDO_05_BYTE 4
#define ID_PDO_06_BYTE 4
#define ID_PDO_07_BYTE 4
#define ID_PDO_08_BYTE 4
#define ID_PDO_09_BYTE 4
#define ID_PDO_10_BYTE 4
#define ID_PDO_11_BYTE 4
#define ID_PDO_12_BYTE 2
#define ID_PDO_13_BYTE 4

typedef enum {
    CTRL_OUTPUT = 0,
    ADC_OUTPUT = 1,
    SCR_OUTPUT = 2,
    IGBT_OUTPUT = 3,
    DGN_OUTPUT = 4
} PDO_GROUP;


/* ## EXTERNAL Vars ################################################### */

/* PDO and SDO */
extern struct DATA process_data[PDO_LENGTH];
extern struct DATA param_data[SDO_LENGTH];


#endif /* INC_PARAM_PROCESS_DATA_H_ */

/* #################################################################### */
/* #################################################################### */
