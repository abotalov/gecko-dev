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

#ifndef TOOLKIT_H      
#define TOOLKIT_H

#include "nsIToolkit.h"

struct PLEventQueue;
struct MethodInfo;

/**
 * Wrapper around the thread running the message pump.
 * The toolkit abstraction is necessary because the message pump must
 * execute within the same thread that created the widget under Win32.
 */ 

class nsToolkit : public nsIToolkit
{

public:
    nsToolkit();
    virtual ~nsToolkit();
  
    NS_DECL_ISUPPORTS
    NS_IMETHOD Init(PRThread *aThread);
};

#endif  // TOOLKIT_H
