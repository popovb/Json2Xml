//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <Json2Xml/Option.hpp>

#ifndef __OptionBuilder__
#define __OptionBuilder__

//////////////////////////////////////////////////////////////////
class OptionBuilder {
     
public:
     template <class CFG>
     json2xml::Option build(const CFG& c) const {
	  json2xml::Option o;
	  auto tg = c.getTagNames();
	  if (tg.count("root_name")) {
	       o.setRootName(tg["root_name"]);
	  }
	  if (tg.count("default_name")) {
	       o.setDefaultName(tg["default_name"]);
	  }
	  if (tg.count("arrays_item_name")) {
	       o.setArraysItemName(tg["arrays_item_name"]);
	  }
	  if (tg.count("arrays_count_name")) {
	       o.setArraysCountName(tg["arrays_count_name"]);
	  }
	  return o;
     }
};
//////////////////////////////////////////////////////////////////
#endif // __OptionBuilder__
