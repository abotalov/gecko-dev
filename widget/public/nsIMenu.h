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

#ifndef nsIMenu_h__
#define nsIMenu_h__

#include "nsISupports.h"
#include "nsString.h"
#include "nsIDOMNode.h"
#include "nsIDOMElement.h"
#include "nsIWebShell.h"

class nsIMenuBar;
class nsIMenu;
class nsIMenuItem;
class nsIMenuListener;

// {35A3DEC1-4992-11d2-8DBA-00609703C14E}
#define NS_IMENU_IID      \
{ 0x35a3dec1, 0x4992, 0x11d2, \
  { 0x8d, 0xba, 0x0, 0x60, 0x97, 0x3, 0xc1, 0x4e } }


/**
 * Menu widget
 */
class nsIMenu : public nsISupports {

  public:
    NS_DEFINE_STATIC_IID_ACCESSOR(NS_IMENU_IID)

  /**
    * Creates the Menu
    *
    */
    NS_IMETHOD Create(nsISupports * aParent, const nsString &aLabel) = 0;

   /**
    * Get the Menu's Parent
    *
    */
    NS_IMETHOD GetParent(nsISupports *&aParent) = 0;

   /**
    * Get the Menu label
    *
    */
    NS_IMETHOD GetLabel(nsString &aText) = 0;

   /**
    * Set the Menu label
    *
    */
    NS_IMETHOD SetLabel(const nsString &aText) = 0;

	/**
    * Get the Menu Access Key
    *
    */
	NS_IMETHOD GetAccessKey(nsString &aText) = 0;
   
	/**
    * Set the Menu Access Key
    *
    */
	NS_IMETHOD SetAccessKey(const nsString &aText) = 0;

	/**
    * Set the Menu enabled state
    *
    */
	NS_IMETHOD SetEnabled(PRBool aIsEnabled) = 0;

	/**
    * Get the Menu enabled state
    *
    */
	NS_IMETHOD GetEnabled(PRBool* aIsEnabled) = 0;
	
	/**
    * Query if this is the help menu. Mostly for MacOS voodoo.
    *
    */
	NS_IMETHOD IsHelpMenu(PRBool* aIsHelpMenu) = 0;
	
	/**
    * Adds a Menu Item
    *
    */
    NS_IMETHOD AddItem(nsISupports* aItem) = 0;

   /**
    * Adds a separator
    *
    */
    NS_IMETHOD AddSeparator() = 0;

   /**
    * Returns the number of menu items
    * This does count separators as items
    */
    NS_IMETHOD GetItemCount(PRUint32 &aCount) = 0;

   /**
    * Returns a Menu or Menu Item at a specified Index
    *
    */
    NS_IMETHOD GetItemAt(const PRUint32 aPos, nsISupports *& aMenuItem) = 0;

   /**
    * Inserts a Menu Item at a specified Index
    *
    */
    NS_IMETHOD InsertItemAt(const PRUint32 aPos, nsISupports * aMenuItem) = 0;

   /**
    * Removes an Menu Item from a specified Index
    *
    */
    NS_IMETHOD RemoveItem(const PRUint32 aPos) = 0;

   /**
    * Removes all the Menu Items
    *
    */
    NS_IMETHOD RemoveAll() = 0;

   /**
    * Gets Native MenuHandle
    *
    */
    NS_IMETHOD  GetNativeData(void** aData) = 0;

   /**
    * Sets Native MenuHandle
    *
    */
    NS_IMETHOD  SetNativeData(void* aData) = 0;
    
   /**
    * Adds menu listener for dynamic construction
    *
    */
    NS_IMETHOD AddMenuListener(nsIMenuListener * aMenuListener) = 0;

   /**
    * Removes menu listener for dynamic construction
    *
    */
    NS_IMETHOD RemoveMenuListener(nsIMenuListener * aMenuListener) = 0;

   /**
    * Set DOMNode
    *
    */
    NS_IMETHOD SetDOMNode(nsIDOMNode * aMenuNode) = 0;

	/**
    * Set DOMElement
    *
    */
    NS_IMETHOD SetDOMElement(nsIDOMElement * aMenuElement) = 0;

	/**
    * Set WebShell
    *
    */
    NS_IMETHOD SetWebShell(nsIWebShell * aWebShell) = 0;
};

#endif
