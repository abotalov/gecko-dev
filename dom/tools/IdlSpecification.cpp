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

#include "IdlSpecification.h"

#include "IdlInterface.h"
#include "nsVoidArray.h"

#include <string.h>
#include <ostream.h>

ostream& operator<<(ostream &s, IdlSpecification &aSpecification)
{
  for (int i = 0; i < aSpecification.InterfaceCount(); i++) {
    s << *(aSpecification.GetInterfaceAt(i)) << '\n';
  }
  return s;
}


IdlSpecification::IdlSpecification()
{
  mInterfaces = (nsVoidArray*)0;
}

IdlSpecification::~IdlSpecification()
{
  if (mInterfaces) {
    for (int i = 0; i < mInterfaces->Count(); i++) {
      IdlInterface *interfaceObj = (IdlInterface*)mInterfaces->ElementAt(i);
      delete interfaceObj;
    }
  }
}

void IdlSpecification::AddInterface(IdlInterface *aInterface)
{
  if (aInterface) {
    if (mInterfaces == 0) {
      mInterfaces = new nsVoidArray();
    }

    mInterfaces->AppendElement((void*)aInterface);
  }
}

int IdlSpecification::ContainInterface(char *aInterfaceName)
{
  if (mInterfaces) {
    for (int i = 0; i < mInterfaces->Count(); i++) {
      IdlInterface *interfaceObj = (IdlInterface*)mInterfaces->ElementAt(i);
      if (0 == strcmp(interfaceObj->GetName(), aInterfaceName)) {
        return 1;
      }
    }
  }

  return 0;
}

IdlInterface* IdlSpecification::GetInterfaceAt(long aIndex)
{
  IdlInterface *interfaceObj = (IdlInterface*)0;
  if (mInterfaces) {
    interfaceObj = (IdlInterface*)mInterfaces->ElementAt(aIndex);
  }

  return interfaceObj;
}

long IdlSpecification::InterfaceCount()
{
  if (mInterfaces) {
    return mInterfaces->Count();
  }
  return 0;
}


