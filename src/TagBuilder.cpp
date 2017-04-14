//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "TagBuilder.hpp"
#include <sstream>

//////////////////////////////////////////////////////////////////
json2xml::String json2xml::TagBuilder::LEFT  = "<";
json2xml::String json2xml::TagBuilder::SLASH = "/";
json2xml::String json2xml::TagBuilder::RIGHT = ">";
json2xml::String json2xml::TagBuilder::SPACE = " ";
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
json2xml::TagBuilder::TagBuilder():
     tag("")
{
     return;
}

void json2xml::TagBuilder::
setAttributeValue(const String s1, const String s2) {
     avb.set(s1, s2);
}

json2xml::String json2xml::TagBuilder::getTag() {
     std::stringstream ss;
     ss << LEFT;
     ss << tag;
     if (avb) {
	  ss << SPACE;
	  ss << avb.get();
     }
     ss << RIGHT;
     tag = "";
     avb.clear();
     return ss.str();
}

bool json2xml::TagBuilder::hasTag() const {
     if (tag.size() == 0) return false;
     return true;
}

json2xml::String
json2xml::TagBuilder::getCloseTag(const String s) const {
     std::stringstream ss;
     ss << LEFT;
     ss << SLASH;
     ss << s;
     ss << RIGHT;
     return ss.str();
}

void json2xml::TagBuilder::buildOpenTag(const String s) {
     tag = s;
}
//////////////////////////////////////////////////////////////////
