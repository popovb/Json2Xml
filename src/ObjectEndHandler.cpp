//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ObjectEndHandler.hpp"

//////////////////////////////////////////////////////////////////
json2xml::ObjectEndHandler::ObjectEndHandler(const Event e):
     previous(e)
{
     return;
}

json2xml::Instructions
json2xml::ObjectEndHandler::handle(TagHistory& th,
				   PlaceLooker&,
				   const Argument) const {
     Instructions is;
     Instruction i({ InstType::CLOSE, { th.pop() } });
     is.push_back(i);

     if (previous == Event::OBJECTSTART)
	  return is;

     if (previous == Event::OBJECTEND)
	  return is;

     Instruction i2({ InstType::CLOSE, { th.pop() } });
     is.push_back(i2);
     return is;
}
//////////////////////////////////////////////////////////////////
