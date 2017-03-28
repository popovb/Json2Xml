//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Handler.hpp"
#include <istream>

#ifndef __Reader_hpp__
#define __Reader_hpp__

namespace simple_json {
//////////////////////////////////////////////////////////////////
     class Reader {

     public:
	  bool Parse(std::istream&, Handler&);
     };
//////////////////////////////////////////////////////////////////
}
#endif // __Reader_hpp__
