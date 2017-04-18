//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Handler.hpp"
#include <sstream>

#ifndef __json2xml_TestHandler_hpp__
#define __json2xml_TestHandler_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     using LineDelimiter = String;
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     class TestHandler: public Handler {

     public:
	  TestHandler(const LineDelimiter);

	  void Text(const String) override;
	  void OpenTag(const String) override;
	  void CloseTag(const String) override;
	  void AttributeValue(const String,
			      const String) override;

	  String get() const;

     private:
	  const LineDelimiter ld;
	  std::stringstream stream;

	  static String text;
	  static String open;
	  static String close;
	  static String attribute;

	  static String left;
	  static String right;

	  void process(const String);
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_TestHandler_hpp__
