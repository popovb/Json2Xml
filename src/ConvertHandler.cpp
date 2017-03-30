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
     if (last_event == Event::UNDEF) {
	  handler.OpenTag(pop());

     } else {

     }
     //handler.OpenTag(new_tag_name());
     //
     //TODO
     //
     last_event = Event::OBJECTSTART;
}

void json2xml::ConvertHandler::ObjectEnd() {
     if (last_event == Event::OBJECTSTART) {
	  handler.CloseTag(pop());

     } else {
	  handler.CloseTag(pop());
	  handler.CloseTag(pop());
     }
     //
     //TODO
     //
     last_event = Event::OBJECTEND;
}

void json2xml::ConvertHandler::ArrayStart() {
     //
     //TODO
     //
     last_event = Event::ARRAYSTART;
}

void json2xml::ConvertHandler::ArrayEnd() {
     //
     //TODO
     //
     last_event = Event::ARRAYEND;
}

void json2xml::ConvertHandler::Key(const simple_json::key_t k) {
     handler.OpenTag(k);
     closed_tags.push(k);
     last_event = Event::KEY;
}

void json2xml::ConvertHandler::Value(const simple_json::value_t v) {
     handler.Text(v);
     last_event = Event::VALUE;
}

json2xml::ConvertHandler::TagName json2xml::ConvertHandler::pop() {
     if (closed_tags.size() == 0) {
	  closed_tags.push(option.getRootName());
	  return option.getRootName();

     } else {
	  auto r = closed_tags.top();
	  closed_tags.pop();
	  return r;
     }
}
//////////////////////////////////////////////////////////////////
