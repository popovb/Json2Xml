//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ObjectHandler.hpp"
#include "Instructions.hpp"
#include <Json2Xml/Option.hpp>

#ifndef __json2xml_ValueHandler_hpp__
#define __json2xml_ValueHandler_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class ValueHandler: public _ObjectHandler {

     public:
	  ValueHandler(const Option&);
	  virtual ~ValueHandler();

	  virtual Instructions handle(TagHistory&,
				      PlaceLooker&) const override;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_ValueHandler_hpp__
