//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <string>

#ifndef __json2xml_Encoder_hpp__
#define __json2xml_Encoder_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     using String = std::string;
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     class Encoder {

     public:
	  String encode(const String) const;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_Encoder_hpp__
