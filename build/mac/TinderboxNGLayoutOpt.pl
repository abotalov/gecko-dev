#!perl

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

#
# nglayout build script (debug)
#
use NGLayoutBuildList;
use Cwd;
use Moz;


# configuration variables

$DEBUG 					= 0;
$ALIAS_SYM_FILES 		= 0;
$CLOBBER_LIBS 			= 1;
$MOZ_FULLCIRCLE 		= 0;
$GC_LEAK_DETECTOR		= 0;	# turn on to use GC leak detection

# The following two options will delete all files, but leave the directory structure intact.
$CLOBBER_DIST_ALL 		= 0;	# turn on to clobber all files inside dist (headers, xsym and libs)
$CLOBBER_DIST_LIBS 		= 0;	# turn on to clobber the aliases to libraries and sym files in dist

$pull{all} 				= 1;
$pull{lizard} 			= 0;
$pull{xpcom} 			= 0;
$pull{imglib} 			= 0;
$pull{netlib} 			= 0;
$pull{nglayout} 		= 0;
$pull{mac} 				= 0;

$build{all} 			= 1;	# turn off to do individual builds, or to do "most"
$build{most} 			= 0;	# turn off to do individual builds
$build{dist} 			= 0;
$build{dist_runtime}	= 0;	# implied by $build{dist}
$build{idl}             = 0;
$build{resources} 		= 0;
$build{stubs} 			= 0;
$build{runtime}			= 0;
$build{common} 			= 0;
$build{intl} 			= 0;
$build{nglayout} 		= 0;
$build{editor} 			= 0;
$build{viewer} 			= 0;
$build{xpapp} 			= 0;
$build{mailnews} 		= 0;
$build{apprunner} 		= 0;

# script


if ($pull{all})
{
	foreach $k (keys(%pull))
	{
		$pull{$k} = 1;
	}
}
if ($build{all})
{
	foreach $k (keys(%build))
	{
		$build{$k} = 1;
	}
}

# do the work

OpenErrorLog("::::Mozilla.BuildLog");		# Tinderbox requires that name

chdir("::::");

Checkout();

BuildDist();

BuildProjects();

print "Build complete\n";
