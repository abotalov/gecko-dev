/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
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
#include "jri.h"

#ifndef _netscape_security_PrivilegeTable_H_
#define _netscape_security_PrivilegeTable_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct netscape_security_Privilege;
struct netscape_security_Target;
struct netscape_security_PrivilegeTable;

/*******************************************************************************
 * Class netscape/security/PrivilegeTable
 ******************************************************************************/

typedef struct netscape_security_PrivilegeTable netscape_security_PrivilegeTable;

struct netscape_security_PrivilegeTable {
  void *ptr;
};

/*******************************************************************************
 * Public Methods
 ******************************************************************************/

JRI_PUBLIC_API(struct netscape_security_Privilege *)
netscape_security_PrivilegeTable_get_1(JRIEnv* env, struct netscape_security_PrivilegeTable* self, struct netscape_security_Target *a);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* Class netscape/security/PrivilegeTable */
