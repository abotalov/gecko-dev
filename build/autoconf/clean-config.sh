#!/bin/sh
#
# The contents of this file are subject to the Netscape Public
# License Version 1.1 (the "License"); you may not use this file
# except in compliance with the License. You may obtain a copy of
# the License at http://www.mozilla.org/NPL/
#
# Software distributed under the License is distributed on an "AS
# IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
# implied. See the License for the specific language governing
# rights and limitations under the License.
#
# The Original Code is mozilla.org code.
#
# The Initial Developer of the Original Code is Netscape
# Communications Corporation.  Portions created by Netscape are
# Copyright (C) 1998 Netscape Communications Corporation. All
# Rights Reserved.
#
# Contributor(s): 
#

# clean-config.sh - Removes all files generated by mozilla configure.
#    Only removes files from the topsrcdir. To clean up an objdir,
#    simply remove the directory and start over.
#
# Usage:
#    1. cd <topsrcdir>
#    2. build/autoconf/clean-config.sh
#
# Send comments, improvements, bugs to slamm@netscape.com

topsrcdir=`cd \`dirname $0\`/../..; pwd`

if [ ! -f configure.in ]; then
  echo "clean-config.sh only cleans the source tree. To run," 2>&1
  echo "  cd $topsrcdir; build/autoconf/clean-config.sh" 2>&1
  echo "  (To clean a separate objdir, simple remove the directory.)" 2>&1
  exit 1
fi

if [ -f mailnews/makefiles ]; then
  MOZ_MAIL_NEWS=1
  export MOZ_MAIL_NEWS
fi

if [ -d editor ]; then
  MOZ_EDITOR=1
  export MOZ_EDITOR
fi

. allmakefiles.sh

rm -fr $MAKEFILES \
    config-defs.h \
    config.cache \
    config.log \
    config.status \
    $NULL
