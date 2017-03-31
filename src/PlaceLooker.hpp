//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <stack>

#ifndef __json2xml_PlaceLooker_hpp__
#define __json2xml_PlaceLooker_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class PlaceLooker {

     public:
	  using count_t = int;

	  void set_object();
	  void set_array();

	  bool is_object() const;
	  bool is_array() const;

	  count_t get_count() const;

	  void release();

	  PlaceLooker& operator++(int);

     private:
	  enum class place_t {
	       OBJECT,
	       ARRAY
	  };

	  struct item_t {
	       place_t place;
	       count_t count;
	  };

	  std::stack<item_t> places;
	  bool is_(const place_t) const;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_PlaceLooker_hpp__
