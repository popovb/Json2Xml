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
     count();
     handle();
     pl.set_object();
}

void json2xml::ConvertHandler::ObjectEnd() {
     el.set(Event::OBJECTEND);
     handle();
     pl.release();
}

void json2xml::ConvertHandler::ArrayStart() {
     el.set(Event::ARRAYSTART);
     count();
     handle();
     pl.set_array();
}

void json2xml::ConvertHandler::ArrayEnd() {
     el.set(Event::ARRAYEND);
     handle();
     pl.release();
}

void json2xml::ConvertHandler::Key(const simple_json::key_t k) {
     el.set(Event::KEY);
     count();
     handle(k);
}

void json2xml::ConvertHandler::Value(const simple_json::value_t v) {
     el.set(Event::VALUE);
     count();
     handle(v);
}

void json2xml::ConvertHandler::handle(const String in) {
     auto hndlr = ohf.make(el);
     auto instr = hndlr->handle(th, pl, in);
     worker->start(instr);
}

void json2xml::ConvertHandler::count() {
     if (el.previous() == Event::KEY) return;
     pl++;
}
//////////////////////////////////////////////////////////////////
