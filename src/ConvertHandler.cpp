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
     option(o),
     th(o.getRootName())
{
     return;
}

json2xml::ConvertHandler::~ConvertHandler() {
     return;
}

void json2xml::ConvertHandler::ObjectStart() {
     el.set(Event::OBJECTSTART);
     if (el.previous() == Event::UNDEF) {
	  handler.OpenTag(th.pop());

     } else {

     }
     //
     //TODO
     //
     pl.set_object();
}

void json2xml::ConvertHandler::ObjectEnd() {
     el.set(Event::OBJECTEND);
     if (el.previous() == Event::OBJECTSTART) {
	  handler.CloseTag(th.pop());

     } else if (el.previous() == Event::OBJECTEND) {
	  handler.CloseTag(th.pop());

     } else {
	  handler.CloseTag(th.pop());
	  handler.CloseTag(th.pop());
     }
     //
     //TODO
     //
     pl.release();
}

void json2xml::ConvertHandler::ArrayStart() {
     el.set(Event::ARRAYSTART);
     //
     //TODO
     //
     pl.set_array();
}

void json2xml::ConvertHandler::ArrayEnd() {
     el.set(Event::ARRAYEND);
     //
     //TODO
     //
     pl.release();
}

void json2xml::ConvertHandler::Key(const simple_json::key_t k) {
     el.set(Event::KEY);
     if (el.previous() == Event::VALUE) {
	  handler.CloseTag(th.pop());
     }
     //
     //TODO
     //
     handler.OpenTag(k);
     th.push(k);
}

void json2xml::ConvertHandler::Value(const simple_json::value_t v) {
     el.set(Event::VALUE);
     //error!!!
     if (pl.is_array()) {
	  pl++;
	  handler.OpenTag(option.getArraysItemName());
	  handler.AttributeValue(option.getArraysCountName(),
				 std::to_string(pl.get_count()));
	  handler.Text(v);
	  handler.CloseTag(option.getArraysItemName());//error!!

     } else {
	  handler.Text(v);
     }
}
//////////////////////////////////////////////////////////////////
