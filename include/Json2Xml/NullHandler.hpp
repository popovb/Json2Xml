//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Handler.hpp"

#ifndef __NullHandler_hpp__
#define __NullHandler_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class NullHandler: public Handler {

     public:
	  virtual void Text(const String) { }
	  virtual void OpenTag(const String) { }
	  virtual void CloseTag(const String) { }
	  virtual void AttributeValue(const String,
				      const String) { }
     };
//////////////////////////////////////////////////////////////////
}
#endif // __NullHandler_hpp__
