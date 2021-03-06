//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <Json2Xml/Shifter.hpp>
#include <sstream>

//////////////////////////////////////////////////////////////////
json2xml::Shifter::Shifter(const size_t u):
     n(u),
     pos(0)
{
     return;
}

json2xml::Shifter& json2xml::Shifter::operator++(const int) {
     pos++;
     return *this;
}

json2xml::Shifter& json2xml::Shifter::operator--(const int) {
     pos--;
     return *this;
}

json2xml::String json2xml::Shifter::get() const {
     std::stringstream ss;
     for (size_t i = 0; i < pos; i++)
	  for (size_t j = 0; j < n; j++) ss << " ";
     return ss.str();
}
//////////////////////////////////////////////////////////////////
