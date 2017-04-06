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
json2xml::KeyHandler::handle(TagHistory&,
			     PlaceLooker&,
			     const Argument) const {
     //
     //TODO
     //
     Instructions i;
     return i;
}
//////////////////////////////////////////////////////////////////
