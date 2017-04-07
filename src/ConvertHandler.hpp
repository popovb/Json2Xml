//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <Json2Xml/Option.hpp>
#include <Json2Xml/Handler.hpp>
#include "SimpleJson/Handler.hpp"
#include "SimpleJson/Common.hpp"
#include "EventLooker.hpp"
#include "TagHistory.hpp"
#include "PlaceLooker.hpp"
#include "ObjectHandlerFabric.hpp"
#include "Worker.hpp"

#ifndef __json2xml_ConvertHandler_hpp__
#define __json2xml_ConvertHandler_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class ConvertHandler: public simple_json::Handler {

     public:
	  ConvertHandler(json2xml::Handler&, const Option&);
	  virtual ~ConvertHandler();

	  virtual void ObjectStart() override;
	  virtual void ObjectEnd() override;

	  virtual void ArrayStart() override;
	  virtual void ArrayEnd() override;

	  virtual void Key(const simple_json::key_t) override;
	  virtual void Value(const simple_json::value_t) override;

     protected:
	  json2xml::Handler& handler;
	  const Option& option;
	  ObjectHandlerFabric ohf;
	  Worker* worker;

	  TagHistory th;
	  EventLooker el;
	  PlaceLooker pl;

	  void handle(const String = "");
	  void count();
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_ConvertHandler_hpp__
