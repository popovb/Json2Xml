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
     push_place( {Place::IN_OBJECT, 0} );
}

void json2xml::ConvertHandler::ObjectEnd() {
     if (last_event == Event::OBJECTSTART) {
	  handler.CloseTag(pop());

     } else if (last_event == Event::OBJECTEND) {
	  handler.CloseTag(pop());

     } else {
	  handler.CloseTag(pop());
	  handler.CloseTag(pop());
     }
     //
     //TODO
     //
     last_event = Event::OBJECTEND;
     pop_place();
}

void json2xml::ConvertHandler::ArrayStart() {
     //
     //TODO
     //
     last_event = Event::ARRAYSTART;
     push_place( {Place::IN_ARRAY, 0} );
}

void json2xml::ConvertHandler::ArrayEnd() {
     //
     //TODO
     //
     last_event = Event::ARRAYEND;
     pop_place();
}

void json2xml::ConvertHandler::Key(const simple_json::key_t k) {
     if (last_event == Event::VALUE) {
	  handler.CloseTag(pop());
     }
     //
     //TODO
     //
     handler.OpenTag(k);
     closed_tags.push(k);
     last_event = Event::KEY;
}

void json2xml::ConvertHandler::Value(const simple_json::value_t v) {
     auto pp = pop_place();
     if (pp.place == Place::IN_ARRAY) {
	  (pp.count)++;
	  handler.OpenTag(option.getArraysItemName());
	  handler.AttributeValue(option.getArraysCountName(),
				 std::to_string(pp.count));
	  handler.Text(v);
	  handler.CloseTag(option.getArraysItemName());
	  push_place(pp);

     } else {
	  handler.Text(v);
     }
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

void json2xml::ConvertHandler::push_place(const PlaceCount p) {
     places.push(p);
}

json2xml::ConvertHandler::PlaceCount
json2xml::ConvertHandler::pop_place() {
     if (places.size() == 0)
	  return {Place::IN_OBJECT, 0};
     auto res = places.top();
     places.pop();
     return res;
}
//////////////////////////////////////////////////////////////////
