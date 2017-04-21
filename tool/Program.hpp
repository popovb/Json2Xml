//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "String.hpp"

#ifndef __Program__
#define __Program__

//////////////////////////////////////////////////////////////////
struct Program {
     const String version     = "0.1.0";
     const String name        = "Json2Xml";
     const String description =
	  name + " - converter from json to xml";
     const String year        = "2017";
     const String author      = "Boris Popov";
     const String email       = "popov@whitekefir.ru";
     const String copy        = "Copyright";
     const String copysgn     = "(c)";
     const String comma       = ",";
     const String left        = "<";
     const String right       = ">";
     const String sp          = " ";
     const String lf          = "\r\n";
     const String free        = "This is a free software.";
     const String github      = "https://github.com/popovb/Json2Xml";
     const String copyright   =
	  copy    +
	  sp      +
	  copysgn +
	  sp      +
	  year    +
	  comma   +
	  sp      +
	  author  +
	  sp      +
	  left    +
	  email   +
	  right   +
	  lf      +
	  free    +
	  sp      +
	  github;
};
//////////////////////////////////////////////////////////////////
#endif // __Program__
