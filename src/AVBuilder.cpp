//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "AVBuilder.hpp"
#include <sstream>

//////////////////////////////////////////////////////////////////
json2xml::String json2xml::AVBuilder::SPACE = " ";;
json2xml::String json2xml::AVBuilder::EQ    = "=";;
json2xml::String json2xml::AVBuilder::QUOTE = "\"";
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
void json2xml::AVBuilder::set(const String s1, const String s2) {
     avs.push_back({s1, s2});
}

json2xml::String json2xml::AVBuilder::get() const {
     if (avs.size() == 0) return "";
     std::stringstream ss;
     bool first(true);
     for (auto& i : avs) {
	  if(!first) ss << SPACE;
	  fill(ss, i);
	  first = false;
     }
     return ss.str();
}

void json2xml::AVBuilder::clear() {
     avs.clear();
}

json2xml::AVBuilder::operator bool() const {
     if (avs.size() == 0) return false;
     return true;
}

void json2xml::AVBuilder::fill(std::stringstream& ss,
			       att_val_t avt) const {
     ss << std::get<0>(avt);
     ss << EQ;
     ss << QUOTE;
     ss << std::get<1>(avt);
     ss << QUOTE;
}
//////////////////////////////////////////////////////////////////
