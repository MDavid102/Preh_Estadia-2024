/*
 * CAN.C
 *
 *  Created on: Jan 16, 2024
 *      Author: Mr.Robot
 */
#include <stdint.h>
#include "CAN.H"
CAN_HandleTypeDef_t hcan;


void CAN_Init(CAN_HandleTypeDef_t *hcan){
	//uint32_t tickstart;

	if(hcan == NULL)
	{
		return _ERROR;
	}

	assert_param(IS_CAN_ALL_INSTANCE(hcan->Instance));
	assert_param(IS_FUNCTIONAL_STATE(hcan->Init.TimeTriggeredMode));
	assert_param(IS_FUNCTIONAL_STATE(hcan->Init.AutoBusOff));
	assert_param(IS_FUNCTIONAL_STATE(hcan->Init.AutoWakeUp));
	assert_param(IS_FUNCTIONAL_STATE(hcan->Init.AutoRetransmission));
	assert_param(IS_FUNCTIONAL_STATE(hcan->Init.ReceiveFifoLocked));
	assert_param(IS_FUNCTIONAL_STATE(hcan->Init.TransmitFifoPriority));
	assert_param(IS_CAN_MODE(hcan->Init.Mode));
	assert_param(IS_CAN_SJW(hcan->Init.SyncJumpWidth));
	assert_param(IS_CAN_BS1(hcan->Init.TimeSeg1));
	assert_param(IS_CAN_BS2(hcan->Init.TimeSeg2));
	assert_param(IS_CAN_PRESCALER(hcan->Init.Prescaler));

	SET_BIT(hcan->Instance->MCR, CAN_MCR_INRQ);

	//hcan->Instance->MSR & CAN_MSR_INAK == 0U;
	CLEAR_BIT(hcan->Instance->MCR, CAN_MCR_SLEEP);

	 if (hcan->Init.TimeTriggeredMode == ENABLE)
	  {
	    SET_BIT(hcan->Instance->MCR, CAN_MCR_TTCM);
	  }
	  else
	  {
	    CLEAR_BIT(hcan->Instance->MCR, CAN_MCR_TTCM);
	  }

	  /* Set the automatic bus-off management */
	  if (hcan->Init.AutoBusOff == ENABLE)
	  {
	    SET_BIT(hcan->Instance->MCR, CAN_MCR_ABOM);
	  }
	  else
	  {
	    CLEAR_BIT(hcan->Instance->MCR, CAN_MCR_ABOM);
	  }

	  /* Set the automatic wake-up mode */
	  if (hcan->Init.AutoWakeUp == ENABLE)
	  {
	    SET_BIT(hcan->Instance->MCR, CAN_MCR_AWUM);
	  }
	  else
	  {
	    CLEAR_BIT(hcan->Instance->MCR, CAN_MCR_AWUM);
	  }

	  /* Set the automatic retransmission */
	  if (hcan->Init.AutoRetransmission == ENABLE)
	  {
	    CLEAR_BIT(hcan->Instance->MCR, CAN_MCR_NART);
	  }
	  else
	  {
	    SET_BIT(hcan->Instance->MCR, CAN_MCR_NART);
	  }

	  /* Set the receive FIFO locked mode */
	  if (hcan->Init.ReceiveFifoLocked == ENABLE)
	  {
	    SET_BIT(hcan->Instance->MCR, CAN_MCR_RFLM);
	  }
	  else
	  {
	    CLEAR_BIT(hcan->Instance->MCR, CAN_MCR_RFLM);
	  }

	  /* Set the transmit FIFO priority */
	  if (hcan->Init.TransmitFifoPriority == ENABLE)
	  {
	    SET_BIT(hcan->Instance->MCR, CAN_MCR_TXFP);
	  }
	  else
	  {
	    CLEAR_BIT(hcan->Instance->MCR, CAN_MCR_TXFP);
	  }

	  if(hcan->Init.Debug_config == ENABLE)
	  {
		  SET_BIT(hcan->Instance->MCR, DBF);
	  }
	  else{
		  CLEAR_BIT(hcan->Instance->MCR, DBF);
	  }

	  /* Set the bit timing register */
	  WRITE_REG(hcan->Instance->BTR, (uint32_t)(hcan->Init.Mode           |
	                                            hcan->Init.SyncJumpWidth  |
	                                            hcan->Init.TimeSeg1       |
	                                            hcan->Init.TimeSeg2       |
	                                            (hcan->Init.Prescaler - 1U)));



	  hcan->State = _CAN_STATE_READY;

	  return _OK;

}

void CAN_AddTxMessage(CAN_HandleTypeDef_t *hcan, const CAN_TxHeaderTypeDef_t *pHeader,
					 const uint8_t CANData[], uint32_t *pTxMailbox)
{
	uint32_t trasnmitmailbox;
	CAN_StateTypeDef_t state = hcan->State;
	uint32_t tsr = READ_REG(hcan->Instance->TSR);

	assert_param(IS_CAN_IDTYPE(pHeader->IDE));
	assert_param(IS_CAN_RTR(pHeader->RTR));
	assert_param(IS_CAN_DLC(pHeader->DLC));

	if (pHeader->IDE == CAN_ID_STD)
	  {
	    assert_param(IS_CAN_STDID(pHeader->StdId));
	  }
	  else
	  {
	    assert_param(IS_CAN_EXTID(pHeader->ExtId));
	  }
	assert_param(IS_FUNCTIONAL_STATE(pHeader->TransmitGlobalTime));

	 if ((state == _CAN_STATE_READY) ||
	     (state == _CAN_STATE_LISTENING))
	  {
	    /* Check that all the Tx mailboxes are not full */
	    if (((tsr & CAN_TSR_TME0) != 0U) ||
	        ((tsr & CAN_TSR_TME1) != 0U) ||
	        ((tsr & CAN_TSR_TME2) != 0U))
	    {
	      /* Select an empty transmit mailbox */
	    	trasnmitmailbox = (tsr & CAN_TSR_CODE) >> CAN_TSR_CODE_Pos;

	      /* Store the Tx mailbox */
	      *pTxMailbox = (uint32_t)1 << trasnmitmailbox;

	      /* Set up the Id */
	      if (pHeader->IDE == CAN_ID_STD)
	      {
	        hcan->Instance->sTxMailBox[trasnmitmailbox].TIR = ((pHeader->StdId << CAN_TI0R_STID_Pos) |
	                                                           pHeader->RTR);
	      }
	      else
	      {
	        hcan->Instance->sTxMailBox[trasnmitmailbox].TIR = ((pHeader->ExtId << CAN_TI0R_EXID_Pos) |
	                                                           pHeader->IDE |
	                                                           pHeader->RTR);
	      }

	      /* Set up the DLC */
	      hcan->Instance->sTxMailBox[trasnmitmailbox].TDTR = (pHeader->DLC);

	      /* Set up the Transmit Global Time mode */
	      if (pHeader->TransmitGlobalTime == ENABLE)
	      {
	        SET_BIT(hcan->Instance->sTxMailBox[trasnmitmailbox].TDTR, CAN_TDT0R_TGT);
	      }

	      /* Set up the data field */
	      WRITE_REG(hcan->Instance->sTxMailBox[trasnmitmailbox].TDHR,
	                ((uint32_t)aData[7] << CAN_TDH0R_DATA7_Pos) |
	                ((uint32_t)aData[6] << CAN_TDH0R_DATA6_Pos) |
	                ((uint32_t)aData[5] << CAN_TDH0R_DATA5_Pos) |
	                ((uint32_t)aData[4] << CAN_TDH0R_DATA4_Pos));
	      WRITE_REG(hcan->Instance->sTxMailBox[trasnmitmailbox].TDLR,
	                ((uint32_t)aData[3] << CAN_TDL0R_DATA3_Pos) |
	                ((uint32_t)aData[2] << CAN_TDL0R_DATA2_Pos) |
	                ((uint32_t)aData[1] << CAN_TDL0R_DATA1_Pos) |
	                ((uint32_t)aData[0] << CAN_TDL0R_DATA0_Pos));

	      /* Request transmission */
	      SET_BIT(hcan->Instance->sTxMailBox[trasnmitmailbox].TIR, CAN_TI0R_TXRQ);

	      /* Return function status */
	      return _OK;
	    }
	  }

}


void CAN_Start(CAN_HandleTypeDef_t *hcan)
{
	CLEAR_BIT(hcan->Instance->MCR, CAN_MCR_INRQ);

	while (hcan->Instance->MCR & CAN_MCR_INAK)
	{
		//Error handler
	}
}
