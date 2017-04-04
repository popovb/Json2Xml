//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <Json2Xml/Option.hpp>
#include "EventLooker.hpp"
#include "ObjectHandler.hpp"

#ifndef __json2xml_ObjectHandlerFabric_hpp__
#define __json2xml_ObjectHandlerFabric_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class ObjectHandlerFabric {

     public:
	  ObjectHandlerFabric(const Option&);

	  ObjectHandler make(EventLooker&) const;

     private:
	  const Option& option;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_ObjectHandlerFabric_hpp__
