//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ObjectStartHandler.hpp"

//////////////////////////////////////////////////////////////////
json2xml::
ObjectStartHandler::ObjectStartHandler(const Option& o,
				       const Event e):
     option(o),
     previous(e)
{
     return;
}

//
//TODO need rafactoring!
//
json2xml::Instructions
json2xml::ObjectStartHandler::handle(TagHistory& th,
				     PlaceLooker&,
				     const Argument) const {
     //root object
     if (previous == Event::UNDEF) {
	  Instructions is;
	  Instruction i({ InstType::OPEN, { option.getRootName() } });
	  is.push_back(i);
	  th.push(option.getRootName());
	  return is;
     }

     //inner object
     if (previous != Event::KEY) {
	  Instructions is;
	  Instruction i({ InstType::OPEN, { option.getDefaultName() } });
	  is.push_back(i);
	  th.push(option.getDefaultName());
	  return is;
     }
     //
     //TODO
     //
     Instructions is;
     return is;
}
//////////////////////////////////////////////////////////////////
