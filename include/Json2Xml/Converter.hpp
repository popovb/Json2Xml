//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Option.hpp"
#include "Handler.hpp"
#include <istream>

#ifndef __json2xml_Converter_hpp__
#define __json2xml_Converter_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class Converter {

     public:
	  Converter(const Option = Option());

	  bool convert(std::istream&, Handler&);

     private:
	  const Option option;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_Converter_hpp__
