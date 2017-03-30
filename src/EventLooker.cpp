//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "EventLooker.hpp"

//////////////////////////////////////////////////////////////////
json2xml::EventLooker::EventLooker(const Event e1,
				   const Event e2):
     _previous(e1),
     _current(e2)
{
     return;
}

json2xml::Event json2xml::EventLooker::previous() const {
     return _previous;
}
     
json2xml::Event json2xml::EventLooker::current() const {
     return _current;
}

void json2xml::EventLooker::set(const Event e) {
     _previous = _current;
     _current = e;
}
//////////////////////////////////////////////////////////////////
