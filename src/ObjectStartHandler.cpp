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
ObjectStartHandler::ObjectStartHandler(const Option& o):
     option(o)
{
     return;
}

json2xml::Instructions
json2xml::ObjectStartHandler::handle(TagHistory&,
				     PlaceLooker&) const {
     //
     //TODO
     //
     Instructions i;
     return i;
}
//////////////////////////////////////////////////////////////////
