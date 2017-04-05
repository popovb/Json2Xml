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

json2xml::Instructions
json2xml::ObjectStartHandler::handle(TagHistory& th,
				     PlaceLooker&) const {
     Instructions is;
     //
     //TODO
     //
     if (previous == Event::UNDEF) {
	  Instruction i({ InstType::OPEN, { th.pop() } });
	  is.push_back(i);

     } else {
	  //
	  //TODO
	  //
     }
     return is;
}
//////////////////////////////////////////////////////////////////
