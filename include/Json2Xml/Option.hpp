//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "String.hpp"

#ifndef __Option_hpp__
#define __Option_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     using RootName        = String;
     using ArraysItemName  = String;
     using ArraysCountName = String;
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     class Option {

     public:
	  Option(const RootName        = "json",
		 const ArraysItemName  = "item",
		 const ArraysCountName = "n");

	  RootName getRootName() const;
	  ArraysItemName getArraysItemName() const;
	  ArraysCountName getArraysCountName() const;

     private:
	  const RootName rn;
	  const ArraysItemName ain;
	  const ArraysCountName acn;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __Option_hpp__