rem -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
rem 
rem  The contents of this file are subject to the Netscape Public
rem  License Version 1.1 (the "License"); you may not use this file
rem  except in compliance with the License. You may obtain a copy of
rem  the License at http://www.mozilla.org/NPL/
rem 
rem  Software distributed under the License is distributed on an "AS
rem  IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
rem  implied. See the License for the specific language governing
rem  rights and limitations under the License.
rem 
rem  The Original Code is mozilla.org code.
rem 
rem  The Initial Developer of the Original Code is Netscape
rem  Communications Corporation.  Portions created by Netscape are
rem  Copyright (C) 1998 Netscape Communications Corporation. All
rem  Rights Reserved.
rem 
rem  Contributor(s): 
rem 

del s:\ns\raptor\ui\src\windows\win32_d.obj\%1.obj
del s:\ns\raptor\ui\tests\windows\win32_d.obj\winmain.obj
nmake -f makefile.win
