//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ArrayEndHandler.hpp"

//////////////////////////////////////////////////////////////////
json2xml::ArrayEndHandler::ArrayEndHandler() {
     return;
}

json2xml::Instructions
json2xml::ArrayEndHandler::handle(TagHistory& th,
				  PlaceLooker&,
				  const Argument) const {
     Instructions is;
     Instruction i({ InstType::CLOSE, { th.pop() } });
     is.push_back(i);
     return is;
}
//////////////////////////////////////////////////////////////////
