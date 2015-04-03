// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Copyright (c) 1994-1999 Inet Technologies, Inc.
// All Rights Reserved.
// This product and related documentation is
// protected by copyright and distributed under licenses restricting
// its use, copying, distribution and decompilation.
// No part of this product or related documentation may be reproduced
// in any form by any means without prior written authorization
// of Inet, Inc. and its licensors, if any.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

/*======================================================================*
 * TITLE:
 * FILE NAME: SipTokenMessage.cpp
 *	
 * PURPOSE:
 * REVISION HISTORY:
 * 	When		Who				What					SPR#
 * ASSUMPTIONS:
 * Notes:
 *======================================================================*/

#pragma implementation

/*----------------------------------------------------------------------*
 Includes:
 *----------------------------------------------------------------------*/
/* OS includes. */
#include <stdio.h>

/* System includes. */

/* Subsystem includes. */
//#include "SipDefs.h"
#include "SipTokenMessage.h"

/*----------------------------------------------------------------------*
 Data: 
 *----------------------------------------------------------------------*/
SipTokenMessage* SipTokenMessage::pInstance = NULL;
UInt8 SipTokenMessage::tokenMap[][];
UInt8 SipTokenMessage::mask[];

/*----------------------------------------------------------------------*
 *----------------------------------------------------------------------*/

/************************************************************************
 * ROUTINE: Ctor
 *
 * INS:	
 * OUTS:
 * Notes:
 ************************************************************************/
SipTokenMessage::SipTokenMessage (void)
	{
	int i, j;
	//	...Initial Token Map
	for (i=0; i<MAX_MSGCHARTYPE; i++)
		for (j=0; j<MAX_MSGLEN; j++)
			tokenMap[i][j] = 0;
	//	...Initial Mask
	for (i = 0; i < 8; i++)
		mask[i] = 1 << i;
	mask[8] = 0;
			
	//	...message method/type	
	Insert("INVITE", 		Msg_Invite);
	Insert("CANCEL", 		Msg_Cancel);
	Insert("ACK", 			Msg_Ack);
	Insert("PRACK", 		Msg_Prack);
	Insert("BYE", 			Msg_Bye);
	Insert("OPTIONS", 		Msg_Options);
	Insert("REGISTER", 		Msg_Register);
	Insert("SIP/2.0", 		Msg_Response);
	}
	
	
/************************************************************************
 * ROUTINE: Insert
 *
 * INS:	
 * OUTS:
 * Notes:	Private
 ************************************************************************/
inline void SipTokenMessage::Insert (char* s, Int8 t)
	{
	int 	i = 0;
	UInt8*	pMask = NULL;
	if (!*s) return;
	t--;
	while (1)
		{
		pMask = &(tokenMap[*s][i]);
		*pMask |= mask[t];
		if (!*s)
			break;
		s++;
		i++;
		}
	}

	 
/************************************************************************
 * ROUTINE: Search
 *
 * INS:	
 * OUTS:
 * Notes:	Get the Type from Token
 ************************************************************************/
inline Int8 SipTokenMessage::Search (char* s)
	{
	UInt8	m;
	int		i = 1;
	char 	c;
	m = tokenMap[*s][0];
	while (m)
		{
		c = *++s;
		m &= tokenMap[c][i];
		if (!c)
			break;
		i++;
		}
	i = 0;
	while (m)
		{
		m >>= 1;
		i++;
		}	
	return i;
	}
	 

/************************************************************************
 * ROUTINE: Instance
 *
 * INS:	
 * OUTS:
 * Notes:	
 ************************************************************************/
inline SipTokenMessage* SipTokenMessage::Instance (void)
	{
	if (pInstance)
		{
		return pInstance;
		}
	return pInstance = new SipTokenMessage;
	}

	
/************************************************************************
 * ROUTINE: Release
 *
 * INS:	
 * OUTS:
 * Notes:	
 ************************************************************************/
inline void SipTokenMessage::Release (void)
	{
	if (pInstance)
		{
		delete pInstance;
		}
	pInstance = NULL;
	}

	
//	End of File