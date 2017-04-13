//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <Json2Xml/TestHandler.hpp>

//////////////////////////////////////////////////////////////////
json2xml::String json2xml::TestHandler::text      = "T";
json2xml::String json2xml::TestHandler::open      = "O";
json2xml::String json2xml::TestHandler::close     = "C";
json2xml::String json2xml::TestHandler::attribute = "A";
json2xml::String json2xml::TestHandler::left      = "[";
json2xml::String json2xml::TestHandler::right     = "]";
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
json2xml::TestHandler::TestHandler(const LineDelimiter l):
     ld(l)
{
     stream << "";
     return;
}

void json2xml::TestHandler::Text(const String s) {
     stream << text;
     process(s);
     stream << ld;
}

void json2xml::TestHandler::OpenTag(const String s) {
     stream << open;
     process(s);
     stream << ld;
}

void json2xml::TestHandler::CloseTag(const String s) {
     stream << close;
     process(s);
     stream << ld;
}

void json2xml::TestHandler::AttributeValue(const String s1,
					   const String s2) {
     stream << attribute;
     process(s1);
     process(s2);
     stream << ld;
}

json2xml::String json2xml::TestHandler::get() const {
     return stream.str();
}

void json2xml::TestHandler::process(const String s) {
     stream << left;
     stream << s;
     stream << right;
}
//////////////////////////////////////////////////////////////////
