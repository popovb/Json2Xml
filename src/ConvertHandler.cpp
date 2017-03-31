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
     el.set(Event::OBJECTSTART);
     if (el.previous() == Event::UNDEF) {
	  handler.OpenTag(pop());

     } else {

     }
     //handler.OpenTag(new_tag_name());
     //
     //TODO
     //
     push_place( {Place::IN_OBJECT, 0} );
}

void json2xml::ConvertHandler::ObjectEnd() {
     el.set(Event::OBJECTEND);
     if (el.previous() == Event::OBJECTSTART) {
	  handler.CloseTag(pop());

     } else if (el.previous() == Event::OBJECTEND) {
	  handler.CloseTag(pop());

     } else {
	  handler.CloseTag(pop());
	  handler.CloseTag(pop());
     }
     //
     //TODO
     //
     pop_place();
}

void json2xml::ConvertHandler::ArrayStart() {
     el.set(Event::ARRAYSTART);
     //
     //TODO
     //
     push_place( {Place::IN_ARRAY, 0} );
}

void json2xml::ConvertHandler::ArrayEnd() {
     el.set(Event::ARRAYEND);
     //
     //TODO
     //
     pop_place();
}

void json2xml::ConvertHandler::Key(const simple_json::key_t k) {
     el.set(Event::KEY);
     if (el.previous() == Event::VALUE) {
	  handler.CloseTag(pop());
     }
     //
     //TODO
     //
     handler.OpenTag(k);
     closed_tags.push(k);
}

void json2xml::ConvertHandler::Value(const simple_json::value_t v) {
     el.set(Event::VALUE);
     auto pp = pop_place();
     //error!!!
     if (pp.place == Place::IN_ARRAY) {
	  (pp.count)++;
	  handler.OpenTag(option.getArraysItemName());
	  handler.AttributeValue(option.getArraysCountName(),
				 std::to_string(pp.count));
	  handler.Text(v);
	  handler.CloseTag(option.getArraysItemName());//error!!
	  push_place(pp);

     } else {
	  handler.Text(v);
     }
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
