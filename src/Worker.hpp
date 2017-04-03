//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Instructions.hpp"

#ifndef __json2xml_Worker_hpp__
#define __json2xml_Worker_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class Worker {

     public:
	  virtual ~Worker() = 0;

	  virtual void start(const Instructions&) = 0;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_Worker_hpp__
