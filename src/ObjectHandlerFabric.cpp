//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ObjectHandlerFabric.hpp"
#include "ObjectNullHandler.hpp"
#include "ObjectStartHandler.hpp"
#include "ObjectEndHandler.hpp"
#include "ArrayStartHandler.hpp"
#include "ArrayEndHandler.hpp"
#include "KeyHandler.hpp"
#include "ValueHandler.hpp"
#include <memory>

//////////////////////////////////////////////////////////////////
json2xml::
ObjectHandlerFabric::ObjectHandlerFabric(const Option& o):
     option(o)
{
     return;
}

json2xml::ObjectHandler
json2xml::ObjectHandlerFabric::make(EventLooker& el) const {
     auto current = el.current();
     switch (current) {

     case Event::UNDEF:
	  return std::make_unique<ObjectNullHandler>();

     case Event::OBJECTSTART:
	  return std::make_unique<ObjectStartHandler>(option,
						      el.previous());
     case Event::OBJECTEND:
	  return std::make_unique<ObjectEndHandler>(el.previous());

     case Event::ARRAYSTART:
	  return std::make_unique<ArrayStartHandler>(option,
						     el.previous());
     case Event::ARRAYEND:
	  return std::make_unique<ArrayEndHandler>();

     case Event::KEY:
	  return std::make_unique<KeyHandler>(option, el.previous());

     case Event::VALUE:
	  return std::make_unique<ValueHandler>(option, el.previous());

     default:
	  return std::make_unique<ObjectNullHandler>();
     }
}
//////////////////////////////////////////////////////////////////
