//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ObjectHandler.hpp"
#include "Instructions.hpp"
#include "EventLooker.hpp"

#ifndef __json2xml_ObjectEndHandler_hpp__
#define __json2xml_ObjectEndHandler_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class ObjectEndHandler: public _ObjectHandler {

     public:
	  ObjectEndHandler(const Event);
	  virtual Instructions handle(TagHistory&,
				      PlaceLooker&) const override;
     private:
	  const Event previous;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_ObjectEndHandler_hpp__
