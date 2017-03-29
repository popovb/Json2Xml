//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ConvertHandler.hpp"

//////////////////////////////////////////////////////////////////
json2xml::
ConvertHandler::ConvertHandler(json2xml::Handler& h,
			       const Option& o):
     handler(h),
     option(o)
{
     return;
}

json2xml::ConvertHandler::~ConvertHandler() {
     return;
}

void json2xml::ConvertHandler::ObjectStart() {
     handler.OpenTag(new_tag_name());
}

void json2xml::ConvertHandler::ObjectEnd() {
     handler.CloseTag(new_tag_name());
}

void json2xml::ConvertHandler::ArrayStart() {
     //
     //TODO
     //
}

void json2xml::ConvertHandler::ArrayEnd() {
     //
     //TODO
     //
}

void json2xml::ConvertHandler::Key(const simple_json::key_t) {
     //
     //TODO
     //
}

void json2xml::ConvertHandler::Value(const simple_json::value_t) {
     //
     //TODO
     //
}

json2xml::ConvertHandler::TagName
json2xml::ConvertHandler::new_tag_name() {
     if (keys.size() == 0) {
	  keys.push(option.getRootName());
	  return option.getRootName();
     }
     auto r = keys.top();
     keys.pop();
     return r;
}
//////////////////////////////////////////////////////////////////
