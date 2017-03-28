//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "String.hpp"

#ifndef __json2xml_Handler_hpp__
#define __json2xml_Handler_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class Handler {

     public:
	  virtual void Text(const String) = 0;
	  virtual void OpenTag(const String) = 0;
	  virtual void CloseTag(const String) = 0;
	  virtual void AttributeValue(const String,
				      const String) = 0;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_Handler_hpp__
