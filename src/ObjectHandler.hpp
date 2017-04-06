//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "TagHistory.hpp"
#include "PlaceLooker.hpp"
#include "Instructions.hpp"
#include <memory>

#ifndef __json2xml_ObjectHandler_hpp__
#define __json2xml_ObjectHandler_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class _ObjectHandler {

     public:
	  virtual Instructions handle(TagHistory&,
				      PlaceLooker&,
				      const Argument = "") const = 0;
     };
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     using ObjectHandler = std::unique_ptr<_ObjectHandler>;
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_ObjectHandler_hpp__
