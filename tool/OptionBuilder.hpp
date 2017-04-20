//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <Json2Xml/Option.hpp>
#include "String.hpp"

#ifndef __OptionBuilder__
#define __OptionBuilder__

//////////////////////////////////////////////////////////////////
class OptionBuilder {
     
public:
     template <class CFG>
     json2xml::Option build(CFG& c) const {
	  json2xml::Option o;
	  Config::TagNames& tg = c.getTagNames();
	  if (tg.count(ROOT_NAME)) {
	       o.setRootName(tg[ROOT_NAME]);
	  }
	  if (tg.count(DEFAULT_NAME)) {
	       o.setDefaultName(tg[DEFAULT_NAME]);
	  }
	  if (tg.count(ARRAYS_ITEM_NAME)) {
	       o.setArraysItemName(tg[ARRAYS_ITEM_NAME]);
	  }
	  if (tg.count(ARRAYS_COUNT_NAME)) {
	       o.setArraysCountName(tg[ARRAYS_COUNT_NAME]);
	  }
	  return o;
     }

private:
     const String ROOT_NAME         = "root_name";
     const String DEFAULT_NAME      = "default_name";
     const String ARRAYS_ITEM_NAME  = "arrays_item_name";
     const String ARRAYS_COUNT_NAME = "arrays_count_name";
};
//////////////////////////////////////////////////////////////////
#endif // __OptionBuilder__
