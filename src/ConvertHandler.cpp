//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ConvertHandler.hpp"
#include "RegularWorker.hpp"

//////////////////////////////////////////////////////////////////
json2xml::
ConvertHandler::ConvertHandler(json2xml::Handler& h,
			       const Option& o):
     handler(h),
     option(o),
     ohf(o),
     worker(new RegularWorker(h)),
     th(o.getDefaultName())
{
     return;
}

json2xml::ConvertHandler::~ConvertHandler() {
     if (worker != nullptr) delete worker;
     return;
}

void json2xml::ConvertHandler::ObjectStart() {
     el.set(Event::OBJECTSTART);
     pl++;
     pl.set_object();
     auto hndlr = ohf.make(el);
     auto instr = hndlr->handle(th, pl);
     worker->start(instr);
}

void json2xml::ConvertHandler::ObjectEnd() {
     el.set(Event::OBJECTEND);
     auto hndlr = ohf.make(el);
     auto instr = hndlr->handle(th, pl);
     worker->start(instr);

}

void json2xml::ConvertHandler::ArrayStart() {
     el.set(Event::ARRAYSTART);
     pl++;
     pl.set_array();
     //
     //TODO
     //
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
     pl++;
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
     pl++;
     //error!!!
     if (pl.is_array()) {
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
