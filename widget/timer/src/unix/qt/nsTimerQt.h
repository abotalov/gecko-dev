/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
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

#ifndef __nsTimerQt_h__
#define __nsTimerQt_h__

#include "nsTimerEventHandler.h"

/*
 * Implementation of timers using Qt QTimer class 
 */
class nsTimerQt : public nsITimer
                  
{
public:


    nsTimerQt();
    virtual ~nsTimerQt();
    
    virtual nsresult Init(nsTimerCallbackFunc aFunc,
                          void *aClosure,
//                        PRBool aRepeat, 
                          PRUint32 aDelay);
    
    virtual nsresult Init(nsITimerCallback *aCallback,
//                        PRBool aRepeat, 
                          PRUint32 aDelay);
    
    NS_DECL_ISUPPORTS
    
    virtual void Cancel();
    virtual PRUint32 GetDelay() { return mDelay; }
    virtual void SetDelay(PRUint32 aDelay) { mDelay=aDelay; };
    virtual void* GetClosure() { return mClosure; }

    void FireTimeout();
    
private:
    nsresult Init(PRUint32 aDelay);
    
private:
    PRUint32            mDelay;
    nsTimerCallbackFunc mFunc;
    void              * mClosure;
    nsITimerCallback  * mCallback;
    PRBool              mRepeat;
    nsTimerQt         * mNext;
    QTimer            * mTimer;
    nsTimerEventHandler  * mEventHandler;
};

#endif // __nsTimerQt_h__

