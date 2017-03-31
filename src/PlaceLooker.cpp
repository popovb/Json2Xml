//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "PlaceLooker.hpp"

//////////////////////////////////////////////////////////////////
void json2xml::PlaceLooker::set_object() {
     places.push({place_t::OBJECT, 0});
}

void json2xml::PlaceLooker::set_array() {
     places.push({place_t::ARRAY, 0});
}

bool json2xml::PlaceLooker::is_object() const {
     return is_(place_t::OBJECT);
}

bool json2xml::PlaceLooker::is_array() const {
     return is_(place_t::ARRAY);
}

json2xml::PlaceLooker::count_t
json2xml::PlaceLooker::get_count() const {
     if (places.size() == 0)
	  return 0;
     return places.top().count;
}

bool json2xml::PlaceLooker::is_(const place_t pt) const {
     if (places.size() == 0) return false;
     if (places.top().place == pt)
	  return true;
     return false;
}

void json2xml::PlaceLooker::release() {
     if (places.size() == 0) return;
     places.pop();
}

json2xml::PlaceLooker&
json2xml::PlaceLooker::operator++(int) {
     if (places.size() > 0)
	  (places.top().count)++;
     return *this;
}
//////////////////////////////////////////////////////////////////
