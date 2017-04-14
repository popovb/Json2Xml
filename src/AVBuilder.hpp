//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <string>
#include <list>
#include <tuple>

#ifndef __json2xml_AVBuilder__
#define __json2xml_AVBuilder__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     using String = std::string;
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     class AVBuilder {

     public:
	  void set(const String, const String);
	  String get() const;
	  void clear();

	  operator bool() const;

     private:
	  using att_t = String;
	  using val_t = String;
	  using att_val_t = std::pair<att_t, val_t>;
	  using AttVals = std::list<att_val_t>;

	  AttVals avs;
	  
	  static String SPACE;
	  static String EQ;
	  static String QUOTE;

	  void fill(std::stringstream&, att_val_t) const;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_AVBuilder__
