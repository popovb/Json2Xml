//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "String.hpp"

#ifndef __json2xml_Option_hpp__
#define __json2xml_Option_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     using RootName        = String;
     using DefaultName     = String;
     using ArraysItemName  = String;
     using ArraysCountName = String;
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     class Option {

     public:
	  Option(const RootName        = "Json",
		 const DefaultName     = "json",
		 const ArraysItemName  = "item",
		 const ArraysCountName = "n");

	  RootName getRootName() const;
	  DefaultName getDefaultName() const;
	  ArraysItemName getArraysItemName() const;
	  ArraysCountName getArraysCountName() const;

	  void setRootName(const RootName);
	  void setDefaultName(const DefaultName);
	  void setArraysItemName(const ArraysItemName);
	  void setArraysCountName(const ArraysCountName);

     private:
	  RootName rn;
	  DefaultName dn;
	  ArraysItemName ain;
	  ArraysCountName acn;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_Option_hpp__
