// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Copyright (c) 1994-2000 Inet, Inc.
// All Rights Reserved.
// This product and related documentation is
// protected by copyright and distributed under licenses restricting
// its use, copying, distribution and decompilation.
// No part of this product or related documentation may be reproduced
// in any form by any means without prior written authorization
// of Inet, Inc. and its licensors, if any.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#ifndef __SIPBASEMESSAGETYPE_H__
#define __SIPBASEMESSAGETYPE_H__

/**********************************************************************
 * .FILE NAME:
 *  SipTokenMessage.h
 *
 * .FUNCTION:
 *
 * .Notes:
 *
 * .REVISION HISTORY:
 *  SPR         Who             When            What
 *
 **********************************************************************/
 
// ... OS includes

// ... System includes

// ... Subsystem includes

#pragma interface

#define MAX_MSGCHARTYPE 90
#define MAX_MSGLEN		9

#define Msg_Invite 1
#define Msg_Cancel 2
#define Msg_Ack 3
#define Msg_Prack 4
#define Msg_Bye 5
#define Msg_Options 6
#define Msg_Register 7
#define Msg_Response 8

typedef char Int8;



class SipTokenMessage
	{
private:
	static UInt8					tokenMap[MAX_MSGCHARTYPE][MAX_MSGLEN];
	static UInt8					mask[8];
	static SipTokenMessage*			pInstance;
	inline							SipTokenMessage (void);

public:							
	inline static SipTokenMessage*	Instance (void);
	inline static void				Release (void);
	inline void						Insert (char*, Int8);
	inline Int8						Search (char*);
	};

#endif
