//########################################################################
//  Project		:	driver_g140v2
//  Target		:
//------------------------------------------------------------------------
//  Filename	:	globals.h
//  Author 		:	lucag
//  Date		:	9 Dec 2022
//------------------------------------------------------------------------
//  History     :
//  9 Dec 2022		- Creation
//
//------------------------------------------------------------------------
//!  Description:    xxx
//!
//
//########################################################################

#ifndef INC_GLOBALS_H_
#define INC_GLOBALS_H_


/* ## COMMON Section ################################################## */
/* ## These defines are visibles in all files							*/
/* #################################################################### */

/* ## COMMON Includes ################################################# */


/* ## COMMON Defines ################################################## */

/* General */
#ifdef __MAIN__
    #define EXTERN
    #define DSPINIT(a) = a;
#else
    #define EXTERN extern
    #define DSPINIT(a) ;
#endif

/* Command Word 1 */
struct CMD_BIT {
    uint16_t SWITCH_ON : 1;         // bit0
    uint16_t b1 : 1;                // bit1
    uint16_t b2 : 1;                // bit2
    uint16_t b3 : 1;                // bit3
    uint16_t b4 : 1;                // bit4
    uint16_t b5 : 1;                // bit5
    uint16_t b6 : 1;                // bit6
    uint16_t FAULT_ACK : 1;         // bit7
    uint16_t RESERVED1 : 1;         // bit8
    uint16_t FORCE_FAULT : 1;       // bit9
    uint16_t REMOTE_CONTROL : 1;    // bit10
    uint16_t b11 : 1;               // bit11
    uint16_t b12 : 1;               // bit12
    uint16_t RESERVED2 : 1;         // bit13
    uint16_t b14 : 1;               // bit14
    uint16_t RESERVED3 : 1;         // bit15
};
typedef union CMD_WD1{
    uint16_t all;
    struct CMD_BIT bit;
} CMD_WD1;

/* Status Word 1 */
struct STS_BIT {
    uint16_t INITIALIZED : 1;       // bit0
    uint16_t FREQ_ESTIMATED : 1;    // bit1
    uint16_t READY_TO_OPERATE : 1;  // bit2
    uint16_t OP_ENABLED : 1;        // bit3
    uint16_t FAULT : 1;             // bit4
    uint16_t PULSE_ENABLED : 1;     // bit5
    uint16_t WARNING : 1;           // bit6
    uint16_t b7 : 1;                // bit7
    uint16_t b8 : 1;                // bit8
    uint16_t b9 : 1;                // bit9
    uint16_t b10 : 1;               // bit10
    uint16_t b11 : 1;               // bit11
    uint16_t b12 : 1;               // bit12
    uint16_t b13 : 1;               // bit13
    uint16_t b14 : 1;               // bit14
    uint16_t b15 : 1;               // bit15
};
typedef union STS_WD1{
    uint16_t all;
    struct STS_BIT bit;
} STS_WD1;

/* Alarm Word 1 */
struct ALM_BIT {
    uint16_t SYNCH_SCR_LOST : 1;    // bit0
    uint16_t FREQ_SCR_UNDEF : 1;    // bit1
    uint16_t DESAT : 1;             // bit2
    uint16_t OVER_CURRENT : 1;      // bit3
    uint16_t UNDER_CURRENT : 1;     // bit4
    uint16_t OVER_VOLTAGE : 1;      // bit5
    uint16_t UNDER_VOLTAGE : 1;     // bit6
    uint16_t PSUPLLY : 1;           // bit7
    uint16_t EXTERNAL_FLT : 1;      // bit8
    uint16_t OH1 : 1;               // bit9
    uint16_t OH2 : 1;               // bit10
    uint16_t b11 : 1;               // bit11
    uint16_t b12 : 1;               // bit12
    uint16_t b13 : 1;               // bit13
    uint16_t b14 : 1;               // bit14
    uint16_t b15 : 1;               // bit15
};
typedef union ALM_WD1{
    uint16_t all;
    struct ALM_BIT bit;
} ALM_WD1;

/* Adc Signals */
typedef struct {
    uint16_t v_inv;
    uint16_t i_inv;
    float v_inv_f;
    float i_inv_f;
} ADC_CTRL_FDB;
typedef struct {
    uint16_t v_inv_rect;
    uint16_t i_inv_rect;
    float v_inv_rect_gain;
    float v_inv_rect_offset;
    float i_inv_rect_gain;
    float i_inv_rect_offset;
    float v_inv_rect_f;
    float i_inv_rect_f;
} ADC_CTRL_FDB_RECT;
typedef struct {
    uint16_t ntc1;
    uint16_t ntc2;
    uint16_t pot;
    float ntc1_gain;
    float ntc1_offset;
    float ntc2_gain;
    float ntc2_offset;
    float pot_gain;
    float pot_offset;
    float ntc1_f;
    float ntc2_f;
    float pot_f;
} ADC_SYS;
typedef struct {
    ADC_CTRL_FDB adc_ctrl_fdb;
    ADC_CTRL_FDB_RECT adc_ctrl_fdb_rect;
    ADC_SYS adc_sys;
} ADC;
#define ADC_DEFAULT { \
    0U, 0U, 0.0f, 0.0f, \
    0U, 0U, 0U, 0U, 0U, 0U, 0.0f, 0.0f, \
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0f, 0.0f, 0.0f \
}


/* ## EXTERNAL Section ################################################ */
/* ## These Vars/Prototypes are visibles in all files             		*/
/* #################################################################### */

/* ## EXTERNAL Prototypes ############################################# */

/* ## EXTERNAL Vars ################################################### */

/* PDO and SDO */
extern uint16_t en_can_send;
extern uint16_t can_error_flag;
extern uint32_t pdo_tx_g170_msg_cnt;
/* general */
EXTERN uint16_t dummy_location          DSPINIT(0U)
EXTERN uint32_t main_fsm_loop_cnt       DSPINIT(0U)
/* variables for analog in */
EXTERN ADC adc                          DSPINIT(ADC_DEFAULT)
/* variables for digital in start_cmd */
EXTERN uint16_t start_cmd_counter       DSPINIT(0U)     // [ms]
EXTERN uint16_t start_cmd_filter        DSPINIT(20U)    // [ms]
EXTERN uint16_t start_cmd_qualified     DSPINIT(0U)
EXTERN uint16_t start_cmd_qualified_d   DSPINIT(0U)
/* variables for digital in oh1 */
EXTERN uint16_t oh1_counter             DSPINIT(0U)     // [ms]
EXTERN uint16_t oh1_filter              DSPINIT(20U)    // [ms]
EXTERN uint16_t oh1_qualified           DSPINIT(0U)
EXTERN uint16_t fault_ack               DSPINIT(0U)
EXTERN uint16_t fault_ack_d             DSPINIT(0U)
EXTERN uint16_t resetting_faults        DSPINIT(0U)
/* variables for digital in oh2 */
EXTERN uint16_t oh2_counter             DSPINIT(0U)     // [ms]
EXTERN uint16_t oh2_filter              DSPINIT(20U)    // [ms]
EXTERN uint16_t oh2_qualified           DSPINIT(0U)
/* variables for digital in flt_sup */
EXTERN uint16_t flt_sup_counter         DSPINIT(0U)     // [ms]
EXTERN uint16_t flt_sup_filter          DSPINIT(10U)    // [ms]
EXTERN uint16_t flt_sup_qualified       DSPINIT(0U)
/* variables for digital in flt_gd */
EXTERN uint16_t flt_gd_counter          DSPINIT(0U)     // [ms]
EXTERN uint16_t flt_gd_filter           DSPINIT(0U)     // [ms]
EXTERN uint16_t flt_gd_qualified        DSPINIT(0U)
/* fsm, sts_wd, alm_wd */
EXTERN STS_WD1 sts_wd_1                 DSPINIT({0U})
EXTERN ALM_WD1 alm_wd_1                 DSPINIT({0U})
EXTERN CMD_WD1 cmd_wd_1                 DSPINIT({0U})
EXTERN uint16_t init_cnt_ms             DSPINIT(0U)     // [ms]
EXTERN uint16_t init_cnt_end            DSPINIT(1000U)  // [ms]
/* variables for ecap input frequency measure */
EXTERN uint32_t ecap_scr_synch_freq_int_cnt     DSPINIT(0UL)
EXTERN float scr_synch_freq             DSPINIT(0.0f)   // [Hz]
EXTERN float scr_synch_freq_bound       DSPINIT(2.0f)   // [Hz]
EXTERN uint16_t scr_synch_estim_cnt_ms  DSPINIT(0U)     // [ms]
EXTERN uint16_t scr_synch_estim_cnt_end DSPINIT(1000U)  // [ms]
EXTERN uint16_t scr_synch_invalid_cnt   DSPINIT(0U)     // [#]
/* variables for scr drivers */
EXTERN uint16_t en_manual_alfa          DSPINIT(0U)     // [#]
EXTERN uint16_t scr_cmd_prd             DSPINIT(15000U) // [epwmclk]
EXTERN uint16_t scr_cmd_cmpa            DSPINIT(20000U) // [epwmclk]
EXTERN uint16_t scr_cmd_cmpb            DSPINIT(13000U) // [epwmclk]
EXTERN float scr_cmd_alfa_set           DSPINIT(0.0f)   // [pu]
EXTERN float scr_cmd_alfa               DSPINIT(0.0f)   // [pu]
EXTERN float scr_cmd_alfa_check_50hz    DSPINIT(0.1f)   // [pu]
EXTERN float scr_cmd_alfa_check_60hz    DSPINIT(0.1f)   // [pu]
EXTERN float scr_cmd_alfa_increment     DSPINIT(0.001f) // [pu/ms]
EXTERN uint16_t freeze_scr_ramp_cnt_ms  DSPINIT(0U)     // [ms]
EXTERN uint16_t freeze_scr_ramp_cnt_end DSPINIT(1000U)  // [ms]
/* variables for igbt drivers */
EXTERN uint16_t igbt_cmd_prd            DSPINIT(3000U)  // [epwmclk]
EXTERN uint16_t igbt_cmd_sweep          DSPINIT(0U)     // [epwmclk]
EXTERN uint16_t freeze_sweep_cnt_ms     DSPINIT(0U)     // [ms]
EXTERN uint16_t freeze_sweep_cnt_end    DSPINIT(0U)     // [ms]
EXTERN float igbt_main_freq             DSPINIT(0.5f)   // [Hz]
EXTERN float igbt_actual_freq           DSPINIT(0.5f)   // [Hz]
EXTERN float sweep_amplitude            DSPINIT(0.3f)   // [Hz]
EXTERN float sweep_freq                 DSPINIT(0.1f)   // [Hz]
/* variables for cmpss overcurrent */
EXTERN uint16_t overcurr_ac_detect      DSPINIT(0U)
EXTERN float i_inv_oc                   DSPINIT(2.0f)   // [A]

#endif /* INC_GLOBALS_H_ */

/* #################################################################### */
/* #################################################################### */
