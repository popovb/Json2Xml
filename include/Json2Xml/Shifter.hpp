//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "String.hpp"

#ifndef __json2xml_Shifter_hpp__
#define __json2xml_Shifter_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class Shifter {

     public:
	  Shifter(const size_t);

	  Shifter& operator++(const int);
	  Shifter& operator--(const int);

	  String get() const;

     private:
	  size_t n;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_Shifter_hpp__
