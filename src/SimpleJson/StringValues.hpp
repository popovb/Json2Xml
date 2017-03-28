//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <SimpleJson/String.hpp>

#ifndef __StringValues_hpp__
#define __StringValues_hpp__

namespace simple_json {
//////////////////////////////////////////////////////////////////
     class StringValues {

     public:
	  static String Null();
	  static String Bool(const bool);
     };
//////////////////////////////////////////////////////////////////
}
#endif // __StringValues_hpp__
