/*
 * CAN.H
 *
 *  Created on: Jan 16, 2024
 *      Author: Mr.Robot
 */

#ifndef CAN_H_
#define CAN_H_

#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f407xx.h"

#define __RE  const  //For reserved bits
#define assert_param(expr) ((void)0U)
#define NULL ((void *)0)

//#define SET_BIT						0x01UL
//#define CLEAR_BIT 					0x00UL
#define ENABLE						0x01UL
#define DISABLE						0x00UL

//Peripheral memory mop
#define APB1PERI_BASE 						(PERIPH_BASE)
#define AHB1PERI_BASE						(PERIPH_BASE + 0x00020000UL)
#define RCC_BASE_REG 						(AHB1PERIPH_BASE + 0x3800UL)
#define RCC_REG 							((RCC_TypeDef *)RCC_BASE)
#define CAN1_BASE_REG 						(APB1PERI_BASE + 0x6400UL)
#define CAN2_BASE_REG   				    (APB1PERIPH_BASE + 0x6800UL)
#define RCC_AHB1ENR_GPIODEN                RCC_AHB1ENR_GPIODEN_Msk
#define RCC_APB1ENR_CAN1EN                 RCC_APB1ENR_CAN1EN_Msk
#define RCC_APB1ENR_CAN2EN                 RCC_APB1ENR_CAN2EN_Msk

//define CAN Init Status
#define CAN_INITSTATUS_FAILED       (0x00000000U)  /*!< CAN initialization failed */
#define CAN_INITSTATUS_SUCCESS      (0x00000001U)  /*!< CAN initialization OK     */

//define CAN mode
#define CAN_MODE_NORMAL             (0x00000000U)                              /*!< Normal mode   */
#define CAN_MODE_LOOPBACK           ((uint32_t)CAN_BTR_LBKM)                   /*!< Loopback mode */
#define CAN_MODE_SILENT             ((uint32_t)CAN_BTR_SILM)                   /*!< Silent mode   */
#define CAN_MODE_SILENT_LOOPBACK    ((uint32_t)(CAN_BTR_LBKM | CAN_BTR_SILM))  /*!< Loopback combined with*/

//define CAN_SJW_Width
#define CAN_SJW_1TQ					(0x00000000U)
#define CAN_SJW_2TQ                 ((uint32_t)CAN_BTR_SJW_0)  /*!< 2 time quantum */
#define CAN_SJW_3TQ                 ((uint32_t)CAN_BTR_SJW_1)  /*!< 3 time quantum */
#define CAN_SJW_4TQ                 ((uint32_t)CAN_BTR_SJW)    /*!< 4 time quantum */

//CAN_TIME_QUANTUM_SEGMENT1
#define CAN_BS1_1TQ                 (0x00000000U)                                                /*!< 1 time quantum  */
#define CAN_BS1_2TQ                 ((uint32_t)CAN_BTR_TS1_0)                                    /*!< 2 time quantum  */
#define CAN_BS1_3TQ                 ((uint32_t)CAN_BTR_TS1_1)                                    /*!< 3 time quantum  */
#define CAN_BS1_4TQ                 ((uint32_t)(CAN_BTR_TS1_1 | CAN_BTR_TS1_0))                  /*!< 4 time quantum  */
#define CAN_BS1_5TQ                 ((uint32_t)CAN_BTR_TS1_2)                                    /*!< 5 time quantum  */
#define CAN_BS1_6TQ                 ((uint32_t)(CAN_BTR_TS1_2 | CAN_BTR_TS1_0))                  /*!< 6 time quantum  */
#define CAN_BS1_7TQ                 ((uint32_t)(CAN_BTR_TS1_2 | CAN_BTR_TS1_1))                  /*!< 7 time quantum  */
#define CAN_BS1_8TQ                 ((uint32_t)(CAN_BTR_TS1_2 | CAN_BTR_TS1_1 | CAN_BTR_TS1_0))  /*!< 8 time quantum  */
#define CAN_BS1_9TQ                 ((uint32_t)CAN_BTR_TS1_3)                                    /*!< 9 time quantum  */
#define CAN_BS1_10TQ                ((uint32_t)(CAN_BTR_TS1_3 | CAN_BTR_TS1_0))                  /*!< 10 time quantum */
#define CAN_BS1_11TQ                ((uint32_t)(CAN_BTR_TS1_3 | CAN_BTR_TS1_1))                  /*!< 11 time quantum */
#define CAN_BS1_12TQ                ((uint32_t)(CAN_BTR_TS1_3 | CAN_BTR_TS1_1 | CAN_BTR_TS1_0))  /*!< 12 time quantum */
#define CAN_BS1_13TQ                ((uint32_t)(CAN_BTR_TS1_3 | CAN_BTR_TS1_2))                  /*!< 13 time quantum */
#define CAN_BS1_14TQ                ((uint32_t)(CAN_BTR_TS1_3 | CAN_BTR_TS1_2 | CAN_BTR_TS1_0))  /*!< 14 time quantum */
#define CAN_BS1_15TQ                ((uint32_t)(CAN_BTR_TS1_3 | CAN_BTR_TS1_2 | CAN_BTR_TS1_1))  /*!< 15 time quantum */
#define CAN_BS1_16TQ                ((uint32_t)CAN_BTR_TS1) /*!< 16 time quantum */

//CAN_TIME_QUANTUM_SEGMENT2
#define CAN_BS2_1TQ                 (0x00000000U)                                /*!< 1 time quantum */
#define CAN_BS2_2TQ                 ((uint32_t)CAN_BTR_TS2_0)                    /*!< 2 time quantum */
#define CAN_BS2_3TQ                 ((uint32_t)CAN_BTR_TS2_1)                    /*!< 3 time quantum */
#define CAN_BS2_4TQ                 ((uint32_t)(CAN_BTR_TS2_1 | CAN_BTR_TS2_0))  /*!< 4 time quantum */
#define CAN_BS2_5TQ                 ((uint32_t)CAN_BTR_TS2_2)                    /*!< 5 time quantum */
#define CAN_BS2_6TQ                 ((uint32_t)(CAN_BTR_TS2_2 | CAN_BTR_TS2_0))  /*!< 6 time quantum */
#define CAN_BS2_7TQ                 ((uint32_t)(CAN_BTR_TS2_2 | CAN_BTR_TS2_1))  /*!< 7 time quantum */
#define CAN_BS2_8TQ                 ((uint32_t)CAN_BTR_TS2)                      /*!< 8 time quantum */

//Define filter mode
#define CAN_FILTERMODE_IDMASK       (0x00000000U)  /*!< Identifier mask mode */
#define CAN_FILTERMODE_IDLIST       (0x00000001U)  /*!< Identifier list mode */

//CAN_filter_scale CAN Filter Scale
#define CAN_FILTERSCALE_16BIT       (0x00000000U)  /*!< Two 16-bit filters */
#define CAN_FILTERSCALE_32BIT       (0x00000001U)  /*!< One 32-bit filter  */

//CAN_filter_activation CAN Filter Activation
#define CAN_FILTER_DISABLE          (0x00000000U)  /*!< Disable filter */
#define CAN_FILTER_ENABLE           (0x00000001U)  /*!< Enable filter  */

//CAN_filter_FIFO CAN Filter FIFO
#define CAN_FILTER_FIFO0            (0x00000000U)  /*!< Filter FIFO 0 assignment for filter x */
#define CAN_FILTER_FIFO1            (0x00000001U)  /*!< Filter FIFO 1 assignment for filter x */

//CAN_identifier_type CAN Identifier Type
#define CAN_ID_STD                  (0x00000000U)  /*!< Standard Id */
#define CAN_ID_EXT                  (0x00000004U)  /*!< Extended Id */

//CAN_remote_transmission_request CAN Remote Transmission Request
#define CAN_RTR_DATA                (0x00000000U)  /*!< Data frame   */
#define CAN_RTR_REMOTE              (0x00000002U)  /*!< Remote frame */

//CAN_Tx_Mailboxes
#define CAN_TX_MAILBOX0             (0x00000001U)  /*!< Tx Mailbox 0  */
#define CAN_TX_MAILBOX1             (0x00000002U)  /*!< Tx Mailbox 1  */
#define CAN_TX_MAILBOX2             (0x00000004U)  /*!< Tx Mailbox 2  */

/* Operating Mode Flags */
#define CAN_FLAG_INAK               (0x00000100U)  /*!< Initialization acknowledge flag   */
#define CAN_FLAG_SLAK               (0x00000101U)  /*!< Sleep acknowledge flag            */
#define CAN_FLAG_ERRI               (0x00000102U)  /*!< Error flag                        */
#define CAN_FLAG_WKU                (0x00000103U)  /*!< Wake up interrupt flag            */
#define CAN_FLAG_SLAKI              (0x00000104U)  /*!< Sleep acknowledge interrupt flag  */

#define CAN1_MCR 					CAN1_BASE_REG
#define CAN1_MSR_OFFSET				0X04UL
#define CAN1_MSR_REG 				(CAN1_BASE_REG + CAN1_MSR_OFFSET)

#define CAN1_TSR_REG (CAN1_BASE_REG + CAN1_TSR_OFFSET)

#define CAN1_RF0R_REG (CAN1_BASE_REG + CAN1_RF0R_OFFSET)

#define CAN1_RF1R_REG (CAN1_BASE_REG + CAN1_RF1R_OFFSET)

#define CAN1_IER_REG (CAN1_BASE_REG + CAN1_IER_OFFSET)

#define CAN1_ESR_REG (CAN1_BASE_REG + CAN1_ESR_OFFSET)

#define CAN1_BTR_REG (CAN1_BASE_REG + CAN1_BTR_OFFSET)

#define CAN1_TI0R_REG (CAN1_BASE_REG + CAN1_TI0R_OFFSET)

#define CAN1_TDT0R_OFFSET 0x184
#define CAN1_TDT0R_REG (CAN1_BASE_REG + CAN1_TDT0R_OFFSET)

#define CAN1_TDL0R_REG (CAN1_BASE_REG + CAN1_TDL0R_OFFSET)

#define CAN1_TDH0R_REG (CAN1_BASE_REG + CAN1_TDH0R_OFFSET)

#define CAN1_TI1R_REG (CAN1_BASE_REG + CAN1_TI1R_OFFSET)

#define CAN1_TDT1R_REG (CAN1_BASE_REG + CAN1_TDT1R_OFFSET)

#define CAN1_TDL1R_REG (CAN1_BASE_REG + CAN1_TDL1R_OFFSET)

#define CAN1_TDH1R_REG (CAN1_BASE_REG + CAN1_TDL1R_OFFSET)

#define CAN1_TI2R_REG (CAN1_BASE_REG + CAN1_TI2R_OFFSET)

#define CAN1_TDT2R_REG (CAN1_BASE_REG + CAN1_TDT2R_OFFSET)

#define CAN1_TDL2R_REG (CAN1_BASE_REG + CAN1_TDL2R_OFFSET)

#define CAN1_TDH2R_REG (CAN1_BASE_REG + CAN1_TDH2R_OFFSET)

#define CAN1_RI0R_REG (CAN1_BASE_REG + CAN1_RI0R_OFFSET)

#define CAN1_RDT0R_REG (CAN1_BASE_REG + CAN1_RDT0R_OFFSET)

#define CAN1_RDL0R_REG (CAN1_BASE_REG + CAN1_RDL0R_OFFSET)

#define CAN1_RDH0R_REG (CAN1_BASE_REG + CAN1_RDH0R_OFFSET)

#define CAN1_RI1R_REG (CAN1_BASE_REG + CAN1_RI1R_OFFSET)

#define CAN1_RDT1R_REG (CAN1_BASE_REG + CAN1_RDT1R_OFFSET)

#define CAN1_RDL1R_REG (CAN1_BASE_REG + CAN1_RDL1R_OFFSET)

#define CAN1_RDH1R_REG (CAN1_BASE_REG + CAN1_RDH1R_OFFSET)

#define CAN1_FS1R_REG (CAN1_BASE_REG + CAN1_FS1R_OFFSET)

#define CAN1_FFA1R_REG (CAN1_BASE_REG + CAN1_FFA1R_OFFSET)

#define CAN1_FA1R_REG (CAN1_BASE_REG + CAN1_FA1R_OFFSET)

#define CAN2_MCR CAN2_BASE_REG

#define IS_CAN_MODE(MODE) (((MODE) == CAN_MODE_NORMAL) || \
                           ((MODE) == CAN_MODE_LOOPBACK)|| \
                           ((MODE) == CAN_MODE_SILENT) || \
                           ((MODE) == CAN_MODE_SILENT_LOOPBACK))
#define IS_CAN_SJW(SJW) (((SJW) == CAN_SJW_1TQ) || ((SJW) == CAN_SJW_2TQ) || \
                         ((SJW) == CAN_SJW_3TQ) || ((SJW) == CAN_SJW_4TQ))
#define IS_CAN_BS1(BS1) (((BS1) == CAN_BS1_1TQ) || ((BS1) == CAN_BS1_2TQ) || \
                         ((BS1) == CAN_BS1_3TQ) || ((BS1) == CAN_BS1_4TQ) || \
                         ((BS1) == CAN_BS1_5TQ) || ((BS1) == CAN_BS1_6TQ) || \
                         ((BS1) == CAN_BS1_7TQ) || ((BS1) == CAN_BS1_8TQ) || \
                         ((BS1) == CAN_BS1_9TQ) || ((BS1) == CAN_BS1_10TQ)|| \
                         ((BS1) == CAN_BS1_11TQ)|| ((BS1) == CAN_BS1_12TQ)|| \
                         ((BS1) == CAN_BS1_13TQ)|| ((BS1) == CAN_BS1_14TQ)|| \
                         ((BS1) == CAN_BS1_15TQ)|| ((BS1) == CAN_BS1_16TQ))
#define IS_CAN_BS2(BS2) (((BS2) == CAN_BS2_1TQ) || ((BS2) == CAN_BS2_2TQ) || \
                         ((BS2) == CAN_BS2_3TQ) || ((BS2) == CAN_BS2_4TQ) || \
                         ((BS2) == CAN_BS2_5TQ) || ((BS2) == CAN_BS2_6TQ) || \
                         ((BS2) == CAN_BS2_7TQ) || ((BS2) == CAN_BS2_8TQ))
#define IS_CAN_PRESCALER(PRESCALER) (((PRESCALER) >= 1U) && ((PRESCALER) <= 1024U))

#define IS_CAN_TX_MAILBOX(TRANSMITMAILBOX) (((TRANSMITMAILBOX) == CAN_TX_MAILBOX0 ) || \
                                            ((TRANSMITMAILBOX) == CAN_TX_MAILBOX1 ) || \
                                            ((TRANSMITMAILBOX) == CAN_TX_MAILBOX2 ))
#define IS_CAN_TX_MAILBOX_LIST(TRANSMITMAILBOX) ((TRANSMITMAILBOX) <= (CAN_TX_MAILBOX0 | CAN_TX_MAILBOX1 | \
                                                                       CAN_TX_MAILBOX2))
#define IS_CAN_STDID(STDID)   ((STDID) <= 0x7FFU)
#define IS_CAN_EXTID(EXTID)   ((EXTID) <= 0x1FFFFFFFU)
#define IS_CAN_DLC(DLC)       ((DLC) <= 8U)
#define IS_CAN_IDTYPE(IDTYPE)  (((IDTYPE) == CAN_ID_STD) || \
                                ((IDTYPE) == CAN_ID_EXT))
#define IS_CAN_RTR(RTR) (((RTR) == CAN_RTR_DATA) || ((RTR) == CAN_RTR_REMOTE))
#define IS_CAN_RX_FIFO(FIFO) (((FIFO) == CAN_RX_FIFO0) || ((FIFO) == CAN_RX_FIFO1))
#define IS_CAN_IT(IT) ((IT) <= (CAN_IT_TX_MAILBOX_EMPTY     | CAN_IT_RX_FIFO0_MSG_PENDING      | \
                                CAN_IT_RX_FIFO0_FULL        | CAN_IT_RX_FIFO0_OVERRUN          | \
                                CAN_IT_RX_FIFO1_MSG_PENDING | CAN_IT_RX_FIFO1_FULL             | \
                                CAN_IT_RX_FIFO1_OVERRUN     | CAN_IT_WAKEUP                    | \
                                CAN_IT_SLEEP_ACK            | CAN_IT_ERROR_WARNING             | \
                                CAN_IT_ERROR_PASSIVE        | CAN_IT_BUSOFF                    | \
                                CAN_IT_LAST_ERROR_CODE      | CAN_IT_ERROR))

//#define pMSRReg ((CAN_MSR_t volatile *const)CAN1_MSR_REG)
//#define pTSRReg ((CAN_TSR_t volatile *const)CAN1_TSR_REG)
//#define pMCRReg ((CAN_MCR_t volatile *const)CAN1_BASE_REG)
//#define pBTRReg ((CAN_BTR_t volatile *const)CAN1_BTR_REG)
//#define pTSRReg ((CAN_TSR_t volatile *const)CAN1_TSR_REG)
//
//// IDENTIFIER REGISTERS
//#define pTI0RReg ((CAN_TI0R_t volatile *const)CAN1_TI0R_REG)
//#define pTI1RReg ((CAN_TI1R_t volatile *const)CAN1_TI1R_REG)
//#define pTI2RReg ((CAN_TI2R_t volatile *const)CAN1_TI2R_REG)
//
//// DATA LENGHT / TIME STAMP
//#define pTDT0RReg ((CAN_TDT0R_t volatile *const)CAN1_TDT0R_REG)
//#define pTDT1RReg ((CAN_TDT1R_t volatile *const)CAN1_TDT1R_REG)
//#define pTDT2RReg ((CAN_TDT2R_t volatile *const)CAN1_TDT2R_REG)
//
//// DATA REGISTERS HIGH
//#define pTDH0RReg ((CAN_TDH0R_t volatile *const)CAN1_TDH0R_REG)
//#define pTDH1RReg ((CAN_TDH1R_t volatile *const)CAN1_TDH1R_REG)
//#define pTDH2RReg ((CAN_TDH2R_t volatile *const)CAN1_TDH2R_REG)
//
////DATA REGISTERS LOW
//#define pTDL0RReg ((CAN_TDL0R_t volatile *const)CAN1_TDL0R_REG)
//#define pTDL1RReg ((CAN_TDL1R_t volatile *const)CAN1_TDL1R_REG)
//#define pTDL2RReg ((CAN_TDL2R_t volatile *const)CAN1_TDL2R_REG)
//
//#define pRCCAHB1Reg  ((RCC_REG_AHB1ENR_t volatile *const)RCC_AHB1ENR_REG)
//#define pRCCAPB1Reg  ((RCC_REG_APB1ENR_t volatile *const)RCC_APB1ENR_REG)
//
//#define pGPIODModReg 		((GPIOx_MODDER_t volatile *const)GPIOD_MODDER_REG)
////#define pGPIODODRReg 		((GPIOX_ORD_t volatile *const)GPIOD_ORD_REG)
//#define pGPIODTYPER 		((GPIOx_OTYPER_t volatile *const)GPIOD_OTYPER_REG)
//#define pOSPEEDR 			((GPIOx_OSPEED_t volatile *const)GPIOD_OSPEED_REG)
//#define pPUPDR 				((GPIOx_PUPDR_t volatile *const)GPIOD_PUPDR_REG)
//#define pAFRH 				((GPIOx_AFRH_t volatile *const)GPIOD_AFRH_REG)
//#define pAFRL 				((GPIOx_AFRL_t volatile *const)GPIOD_AFRL_REG)


typedef enum{
	_OK			= 0x00U,
	_ERROR		= 0x01U,
	_BUSY		= 0x02U,
	_TIMEOUT	= 0x03U,
}StatusTypeDef_t;

typedef enum
{
  _CAN_STATE_RESET             = 0x00U,  /*!< CAN not yet initialized or disabled */
  _CAN_STATE_READY             = 0x01U,  /*!< CAN initialized and ready for use   */
  _CAN_STATE_LISTENING         = 0x02U,  /*!< CAN receive process is ongoing      */
  _CAN_STATE_SLEEP_PENDING     = 0x03U,  /*!< CAN sleep request is pending        */
  _CAN_STATE_SLEEP_ACTIVE      = 0x04U,  /*!< CAN sleep mode is active            */
  _CAN_STATE_ERROR             = 0x05U   /*!< CAN error state                     */

} CAN_StateTypeDef_t;

typedef struct
{
  uint32_t Prescaler;                  /*!< Specifies the length of a time quantum.
                                            This parameter must be a number between Min_Data = 1 and Max_Data = 1024. */

  uint32_t Mode;                       /*!< Specifies the CAN operating mode.
                                            This parameter can be a value of @ref CAN_operating_mode */

  uint32_t SyncJumpWidth;              /*!< Specifies the maximum number of time quanta the CAN hardware
                                            is allowed to lengthen or shorten a bit to perform resynchronization.
                                            This parameter can be a value of @ref CAN_synchronisation_jump_width */

  uint32_t TimeSeg1;                   /*!< Specifies the number of time quanta in Bit Segment 1.
                                            This parameter can be a value of @ref CAN_time_quantum_in_bit_segment_1 */

  uint32_t TimeSeg2;                   /*!< Specifies the number of time quanta in Bit Segment 2.
                                            This parameter can be a value of @ref CAN_time_quantum_in_bit_segment_2 */

  uint32_t TimeTriggeredMode;   /*!< Enable or disable the time triggered communication mode.
                                            This parameter can be set to ENABLE or DISABLE. */

  FunctionalState AutoBusOff;          /*!< Enable or disable the automatic bus-off management.
                                            This parameter can be set to ENABLE or DISABLE. */

  FunctionalState AutoWakeUp;          /*!< Enable or disable the automatic wake-up mode.
                                            This parameter can be set to ENABLE or DISABLE. */

  FunctionalState AutoRetransmission;  /*!< Enable or disable the non-automatic retransmission mode.
                                            This parameter can be set to ENABLE or DISABLE. */

  FunctionalState ReceiveFifoLocked;   /*!< Enable or disable the Receive FIFO Locked mode.
                                            This parameter can be set to ENABLE or DISABLE. */

  FunctionalState TransmitFifoPriority;/*!< Enable or disable the transmit FIFO priority.
                                            This parameter can be set to ENABLE or DISABLE. */
  uint32_t		Debug_config;

} CAN_InitTypeDef_t;

typedef struct
{
  uint32_t FilterIdHigh;          /*!< Specifies the filter identification number (MSBs for a 32-bit
                                       configuration, first one for a 16-bit configuration).
                                       This parameter must be a number between
                                       Min_Data = 0x0000 and Max_Data = 0xFFFF. */

  uint32_t FilterIdLow;           /*!< Specifies the filter identification number (LSBs for a 32-bit
                                       configuration, second one for a 16-bit configuration).
                                       This parameter must be a number between
                                       Min_Data = 0x0000 and Max_Data = 0xFFFF. */

  uint32_t FilterMaskIdHigh;      /*!< Specifies the filter mask number or identification number,
                                       according to the mode (MSBs for a 32-bit configuration,
                                       first one for a 16-bit configuration).
                                       This parameter must be a number between
                                       Min_Data = 0x0000 and Max_Data = 0xFFFF. */

  uint32_t FilterMaskIdLow;       /*!< Specifies the filter mask number or identification number,
                                       according to the mode (LSBs for a 32-bit configuration,
                                       second one for a 16-bit configuration).
                                       This parameter must be a number between
                                       Min_Data = 0x0000 and Max_Data = 0xFFFF. */

  uint32_t FilterFIFOAssignment;  /*!< Specifies the FIFO (0 or 1U) which will be assigned to the filter.
                                       This parameter can be a value of @ref CAN_filter_FIFO */

  uint32_t FilterBank;            /*!< Specifies the filter bank which will be initialized.
                                       For single CAN instance(14 dedicated filter banks),
                                       this parameter must be a number between Min_Data = 0 and Max_Data = 13.
                                       For dual CAN instances(28 filter banks shared),
                                       this parameter must be a number between Min_Data = 0 and Max_Data = 27. */

  uint32_t FilterMode;            /*!< Specifies the filter mode to be initialized.
                                       This parameter can be a value of @ref CAN_filter_mode */

  uint32_t FilterScale;           /*!< Specifies the filter scale.
                                       This parameter can be a value of @ref CAN_filter_scale */

  uint32_t FilterActivation;      /*!< Enable or disable the filter.
                                       This parameter can be a value of @ref CAN_filter_activation */

  uint32_t SlaveStartFilterBank;  /*!< Select the start filter bank for the slave CAN instance.
                                       For single CAN instances, this parameter is meaningless.
                                       For dual CAN instances, all filter banks with lower index are assigned to master
                                       CAN instance, whereas all filter banks with greater index are assigned to slave
                                       CAN instance.
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 27. */

} CAN_FilterTypeDef_t;

typedef struct
{
  uint32_t StdId;    /*!< Specifies the standard identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x7FF. */

  uint32_t ExtId;    /*!< Specifies the extended identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x1FFFFFFF. */

  uint32_t IDE;      /*!< Specifies the type of identifier for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_identifier_type */

  uint32_t RTR;      /*!< Specifies the type of frame for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_remote_transmission_request */

  uint32_t DLC;      /*!< Specifies the length of the frame that will be transmitted.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 8. */

  FunctionalState TransmitGlobalTime; /*!< Specifies whether the timestamp counter value captured on start
                          of frame transmission, is sent in DATA6 and DATA7 replacing pData[6] and pData[7].
                          @note: Time Triggered Communication Mode must be enabled.
                          @note: DLC must be programmed as 8 bytes, in order these 2 bytes are sent.
                          This parameter can be set to ENABLE or DISABLE. */

} CAN_TxHeaderTypeDef_t;

typedef struct{
	CAN_TypeDef			*Instance;

	CAN_InitTypeDef_t		Init;

	CAN_StateTypeDef_t		State;

	__IO uint32_t		ErrorCode;

}CAN_HandleTypeDef_t;

typedef struct
	{
	__IO uint32_t  GPIOA_EN		       :1;
	__IO uint32_t  GPIOB_EN		       :1;
	__IO uint32_t  GPIOC_EN		       :1;
	__IO uint32_t  GPIOD_EN		       :1;
	__IO uint32_t  GPIOE_EN		       :1;
	__IO uint32_t  GPIOF_EN		       :1;
	__IO uint32_t  GPIOG_EN		       :1;
	__IO uint32_t  GPIOH_EN		       :1;
	__IO uint32_t  				       :4;
	__IO uint32_t  CRC_EN			   :1;
	__IO uint32_t  				       :5;
	__IO uint32_t  BKP_SRAMEN		   :1;
	__IO uint32_t  				       :2;
	__IO uint32_t  DMA1_EN			   :1;
	__IO uint32_t  DMA2_EN			   :1;
	__IO uint32_t  				       :6;
	__IO uint32_t  OTGHS_EN		       :1;
	__IO uint32_t  OTGHS_ULPIEN	       :1;
	__RE uint32_t  			           :1;

} RCC_REG_AHB1ENR_t;

typedef struct
{

	__IO uint32_t	INRQ				:1;
	__IO uint32_t	SLEEP				:1;
	__IO uint32_t	TXFP				:1;
	__IO uint32_t	RFLM				:1;
	__IO uint32_t	NART				:1;
	__IO uint32_t	AWUM				:1;
	__IO uint32_t	ABOM				:1;
	__IO uint32_t	TTCM				:1;
	__RE uint32_t						:7; //RESERVED
	__IO uint32_t	RESET				:1;
	__IO uint32_t	DBF					:1;
	__RE uint32_t						:15; //RESERVED


} CAN_MCR_t;

typedef struct
{

	__IO uint32_t	INAK				:1;
	__IO uint32_t	SLAK				:1;
	__IO uint32_t	ERRI				:1;
	__IO uint32_t	WKUI				:1;
	__IO uint32_t	SLAKI				:1;
	__RE uint32_t						:3;
	__IO uint32_t	TXM					:1;
	__IO uint32_t	RXM					:1;
	__IO uint32_t	SAMP				:1;
	__IO uint32_t	RX					:1;
	__RE uint32_t						:20; //RESERVED


} CAN_MSR_t;

typedef struct
{

	__IO uint32_t	RQCP0				:1;
	__IO uint32_t	TXOK0				:1;
	__IO uint32_t	ALST0				:1;
	__IO uint32_t	TERR0				:1;
	__RE uint32_t						:3;
	__IO uint32_t	ABRQ0					:1;
	__IO uint32_t	RQCP1				:1;
	__IO uint32_t	TXOK1				:1;
	__IO uint32_t	ALST1				:1;
	__IO uint32_t	TERR1				:1;
	__RE uint32_t						:3; //RESERVED
	__IO uint32_t	ABRQ1				:1;
	__IO uint32_t	RQCP2				:1;
	__IO uint32_t	TXOK2				:1;
	__IO uint32_t	ALST2				:1;
	__IO uint32_t	TERR2				:1;
	__RE uint32_t						:3; //RESERVED
	__IO uint32_t	ABRQ2				:1;
	__IO uint32_t	CODE				:2;
	__IO uint32_t	TME0				:1;
	__IO uint32_t	TME1				:1;
	__IO uint32_t	TME2				:1;
	__IO uint32_t	LOW0				:1;
	__IO uint32_t	LOW1				:1;
	__IO uint32_t	LOW2				:1;

} CAN_TSR_t;

typedef struct
{

	__IO uint32_t	BRP					:10;
	__RE uint32_t						:6; //RESERVED
	__IO uint32_t	TS1					:4;
	__IO uint32_t	TS2					:3;
	__RE uint32_t						:1; //RESERVED
	__IO uint32_t	SJW					:2;
	__RE uint32_t						:4; //RESERVED
	__IO uint32_t	LBKM				:1;
	__IO uint32_t	SILM				:1;

} CAN_BTR_t;


typedef struct
	{
	__IO uint32_t  TIM2EN	      	   :1;
	__IO uint32_t  TIM3EN		       :1;
	__IO uint32_t  TIM4EN		       :1;
	__IO uint32_t  TIM5EN		       :1;
	__IO uint32_t  TIM6EN		       :1;
	__IO uint32_t  TIM7EN		       :1;
	__IO uint32_t  TIM12EN		       :1;
	__IO uint32_t  TIM13EN		       :1;
	__IO uint32_t  TIM14EN		       :1;
	__RE uint32_t  				       :2;
	__IO uint32_t  WWDGREN		       :1;
	__IO uint32_t  				       :2;
	__IO uint32_t  SPI2EN		       :1;
	__IO uint32_t  SPI3EN		       :1;
	__IO uint32_t  SPDIFRXEN		   :1;
	__IO uint32_t  USART2EN		 	   :1;
	__IO uint32_t  USART3EN		 	   :1;
	__IO uint32_t  USART4EN		 	   :1;
	__IO uint32_t  USART5EN		 	   :1;
	__IO uint32_t  I2C1EN		 	   :1;
	__IO uint32_t  I2C2EN		 	   :1;
	__IO uint32_t  I2C3EN		 	   :1;
	__IO uint32_t  FMPI2C1EN		   :1;
	__IO uint32_t  CAN1EN		 	   :1;
	__IO uint32_t  CAN2EN		 	   :1;
	__IO uint32_t  CECEN			   :1;
	__IO uint32_t  PWREN			   :1;
	__IO uint32_t  DACEN			   :1;
	__RE uint32_t  				       :2;

} RCC_REG_APB1ENR_t;

typedef struct
{

	__IO uint32_t	TXRQ				:1;
	__IO uint32_t	RTR					:1;
	__IO uint32_t	IDE					:1;
	__IO uint32_t	EXID				:18; // TODO: CORRECT THIS
	__IO uint32_t	STID				:11;

} CAN_TI0R_t;

typedef struct
{

	__IO uint32_t	TXRQ				:1;
	__IO uint32_t	RTR					:1;
	__IO uint32_t	IDE					:1;
	__IO uint32_t	EXID				:18; // TODO: CORRECT THIS
	__IO uint32_t	STID				:11;

} CAN_TI1R_t;

typedef struct
{

	__IO uint32_t	TXRQ				:1;
	__IO uint32_t	RTR					:1;
	__IO uint32_t	IDE					:1;
	__IO uint32_t	EXID				:18; // TODO: CORRECT THIS
	__IO uint32_t	STID				:11;

} CAN_TI2R_t;

/*
 * ----------------------------------------------------
 * |												  |
 * | MAILBOX REGISTERS	- 	Data lenght / Time stamp  |
 * |												  |
 * ----------------------------------------------------
 */


typedef struct
{

	__IO uint32_t	DLC					:4;
	__RE uint32_t						:12;
	__IO uint32_t	TIME				:16;


} CAN_TDT0R_t;

typedef struct
{

	__IO uint32_t	DLC					:4;
	__RE uint32_t						:12;
	__IO uint32_t	TIME				:16;


} CAN_TDT1R_t;

typedef struct
{

	__IO uint32_t	DLC					:4;
	__RE uint32_t						:12;
	__IO uint32_t	TIME				:16;


} CAN_TDT2R_t;

/*
 * ----------------------------------------------------
 * |												  |
 * | MAILBOX REGISTERS	- 	DATA REGISTERS (LOW/HIGH) |
 * |												  |
 * ----------------------------------------------------
 */

typedef struct
{

	__IO uint32_t	DATA4				:8;
	__IO uint32_t	DATA5				:8;
	__IO uint32_t	DATA6				:8;
	__IO uint32_t	DATA7				:8;

} CAN_TDH0R_t;

typedef struct
{

	__IO uint32_t	DATA4				:8;
	__IO uint32_t	DATA5				:8;
	__IO uint32_t	DATA6				:8;
	__IO uint32_t	DATA7				:8;

} CAN_TDH1R_t;

typedef struct
{

	__IO uint32_t	DATA4				:8;
	__IO uint32_t	DATA5				:8;
	__IO uint32_t	DATA6				:8;
	__IO uint32_t	DATA7				:8;

} CAN_TDH2R_t;

///////////////////////////////////////////////////////

typedef struct
{

	__IO uint32_t	DATA0				:8;
	__IO uint32_t	DATA1				:8;
	__IO uint32_t	DATA2				:8;
	__IO uint32_t	DATA3				:8;

} CAN_TDL0R_t;

typedef struct
{

	__IO uint32_t	DATA0				:8;
	__IO uint32_t	DATA1				:8;
	__IO uint32_t	DATA2				:8;
	__IO uint32_t	DATA3				:8;

} CAN_TDL1R_t;

typedef struct
{

	__IO uint32_t	DATA0				:8;
	__IO uint32_t	DATA1				:8;
	__IO uint32_t	DATA2				:8;
	__IO uint32_t	DATA3				:8;

} CAN_TDL2R_t;


//Definition of functions
void CAN_Init(CAN_HandleTypeDef_t *hcan);
void CAN_Start(CAN_HandleTypeDef_t *hcan);
void CAN_AddTxMessage(CAN_HandleTypeDef_t *hcan, const CAN_TxHeaderTypeDef_t *pHeader, const uint8_t CANData[], uint32_t *pTxMailbox);
void delay(int x);



#endif /* CAN_H_ */
