/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * The contents of this file are subject to the Netscape Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation. All
 * Rights Reserved.
 *
 * Contributor(s): 
 */

#ifndef nsDataHandler_h___
#define nsDataHandler_h___

#include "nsIProtocolHandler.h"
// {B6ED3030-6183-11d3-A178-0050041CAF44}
#define NS_DATAHANDLER_CID \
    { 0xb6ed3030, 0x6183, 0x11d3, { 0xa1, 0x78, 0x00, 0x50, 0x04, 0x1c, 0xaf, 0x44 } }

class nsDataHandler : public nsIProtocolHandler
{
public:
    NS_DECL_ISUPPORTS

    // nsIProtocolHandler methods:
    NS_DECL_NSIPROTOCOLHANDLER

    // nsDataHandler methods:
    nsDataHandler();
    virtual ~nsDataHandler();

    // Define a Create method to be used with a factory:
    static NS_METHOD
    Create(nsISupports* aOuter, const nsIID& aIID, void* *aResult);
    
protected:
    nsISupports*        mEventSinkGetter;
};

#endif /* nsDataHandler_h___ */
