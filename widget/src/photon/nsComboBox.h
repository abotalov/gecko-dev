/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
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

#ifndef nsComboBox_h__
#define nsComboBox_h__

#include "nsWidget.h"
#include "nsIComboBox.h"

/**
 * Native Photon Listbox wrapper
 */

class nsComboBox : public nsWidget,
                   public nsIListWidget,
				   public nsIComboBox
{
public:
    nsComboBox();
    ~nsComboBox();

    NS_IMETHOD_(nsrefcnt) AddRef();
    NS_IMETHOD_(nsrefcnt) Release();
    NS_IMETHOD QueryInterface(const nsIID& aIID, void** aInstancePtr);

    // nsIComboBox interface
    NS_IMETHOD AddItemAt(nsString &aItem, PRInt32 aPosition);
    PRInt32    FindItem(nsString &aItem, PRInt32 aStartPos);
    PRInt32    GetItemCount();
    PRBool     RemoveItemAt(PRInt32 aPosition);
    PRBool     GetItemAt(nsString& anItem, PRInt32 aPosition);
    NS_IMETHOD GetSelectedItem(nsString& aItem);
    PRInt32    GetSelectedIndex();
    NS_IMETHOD SelectItem(PRInt32 aPosition);
    NS_IMETHOD Deselect() ;
	
    virtual PRBool  OnMove(PRInt32 aX, PRInt32 aY);
    virtual PRBool  OnPaint(nsPaintEvent & aEvent);
    virtual PRBool  OnResize(nsSizeEvent &aEvent);

    // nsIComboBox interface
    NS_IMETHOD      SetMultipleSelection(PRBool aMultipleSelections);
    PRInt32         GetSelectedCount();
    NS_IMETHOD      GetSelectedIndices(PRInt32 aIndices[], PRInt32 aSize);

protected:
    NS_IMETHOD  CreateNative(PtWidget_t *parentWindow);
    PRBool  mMultiSelect;
};

#endif // nsComboBox_h__
