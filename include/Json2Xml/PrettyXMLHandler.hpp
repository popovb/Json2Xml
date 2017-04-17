//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Handler.hpp"
#include "Shifter.hpp"
#include <iostream>

#ifndef __json2xml_PrettyXMLHandler_hpp__
#define __json2xml_PrettyXMLHandler_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     using LineDelimiter = String;
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     class TagBuilder;
     class Encoder;
     class PrettyXMLHandler: public Handler {

     public:
	  PrettyXMLHandler(std::ostream& = std::cout,
			   const LineDelimiter = "\r\n",
			   const size_t = 2);
	  ~PrettyXMLHandler();

	  void Text(const String) override;
	  void OpenTag(const String) override;
	  void CloseTag(const String) override;
	  void AttributeValue(const String,
			      const String) override;
     private:
	  std::ostream& stream;
	  const LineDelimiter ld;
	  Shifter shifter;
	  TagBuilder* builder;
	  Encoder* encoder;

	  void previousTag();
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_PrettyXMLHandler_hpp__
