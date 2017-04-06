//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "KeyHandler.hpp"

//////////////////////////////////////////////////////////////////
json2xml::KeyHandler::KeyHandler(const Event p):
     previous(p)
{
     return;
}

json2xml::Instructions
json2xml::KeyHandler::handle(TagHistory& th,
			     PlaceLooker&,
			     const Argument a) const {
     Instructions is;
     if (previous == Event::VALUE) {
	  Instruction i({ InstType::CLOSE, { th.pop() } });
	  is.push_back(i);
     }
     Instruction i({ InstType::OPEN, { a } });
     is.push_back(i);
     th.push(a);
     return is;
}
//////////////////////////////////////////////////////////////////
