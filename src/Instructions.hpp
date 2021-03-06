//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <string>
#include <vector>

#ifndef __json2xml_Instructions_hpp__
#define __json2xml_Instructions_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     using String = std::string;
     using Argument = String;
     using Arguments = std::vector<Argument>;
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     enum class InstType {
	  TEXT,
	  OPEN,
	  CLOSE,
	  AV
     };
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     struct Instruction {

	  InstType type;
	  Arguments args;
     };

     bool operator==(const Instruction&, const Instruction&);
     bool operator!=(const Instruction&, const Instruction&);
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     using Instructions = std::vector<Instruction>;
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_Instructions_hpp__
