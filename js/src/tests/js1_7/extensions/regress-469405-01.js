/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

//-----------------------------------------------------------------------------
var BUGNUMBER = 469405;
var summary = 'Do not assert: !regs.sp[-2].isPrimitive()';
var actual = '';
var expect = '';

printBugNumber(BUGNUMBER);
printStatus (summary);

try
{ 
  (function() {
    var a, b;
    for each (a in [{}, {__iterator__: function(){}}]) for (b in a) { }
  })();
}
catch(ex)
{
  print('caught ' + ex);
}

reportCompare(expect, actual, summary);
