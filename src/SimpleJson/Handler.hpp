//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Common.hpp"

#ifndef __Handler_hpp__
#define __Handler_hpp__

namespace simple_json {
//////////////////////////////////////////////////////////////////
     class Handler {

     public:
	  Handler();
	  virtual ~Handler();

	  virtual void ObjectStart();
	  virtual void ObjectEnd();

	  virtual void ArrayStart();
	  virtual void ArrayEnd();

	  virtual void Key(const key_t);
	  virtual void Value(const value_t);
     };
//////////////////////////////////////////////////////////////////
}
#endif // __Handler_hpp__
