//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "AVBuilder.hpp"
#include <string>

#ifndef __json2xml_TagBuilder__
#define __json2xml_TagBuilder__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     using String = std::string;
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     class TagBuilder {

     public:
	  TagBuilder();

	  void setAttributeValue(const String, const String);
	  String getTag();
	  bool hasTag() const;

	  String getCloseTag(const String) const;
	  void buildOpenTag(const String);

     private:
	  String tag;

	  static String LEFT;
	  static String SLASH;
	  static String RIGHT;
	  static String SPACE;

	  AVBuilder avb;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_TagBuilder__
