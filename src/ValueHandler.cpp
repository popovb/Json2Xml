//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ValueHandler.hpp"

//////////////////////////////////////////////////////////////////
json2xml::ValueHandler::ValueHandler(const Option& o):
     option(o)
{
     return;
}

json2xml::Instructions
json2xml::ValueHandler::handle(TagHistory&,
			       PlaceLooker& pl,
			       const Argument v) const {
     Instructions is;
     if (pl.is_array()) {
	  Instruction i1({ InstType::OPEN,
			   { option.getArraysItemName() } });
	  Instruction i2({ InstType::AV,
			   { option.getArraysCountName(),
			     std::to_string(pl.get_count()) } });
	  Instruction i3({ InstType::TEXT, { v } });
	  Instruction i4({ InstType::CLOSE,
			   { option.getArraysItemName() } });
	  is.push_back(i1);
	  is.push_back(i2);
	  is.push_back(i3);
	  is.push_back(i4);

     } else {
	  Instruction i({ InstType::TEXT, { v } });
	  is.push_back(i);
     }
     //
     //TODO
     //
     return is;
}
//////////////////////////////////////////////////////////////////
