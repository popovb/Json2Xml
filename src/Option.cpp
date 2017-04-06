//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <Json2Xml/Option.hpp>

//////////////////////////////////////////////////////////////////
json2xml::Option::Option(const RootName n,
			 const DefaultName _dn,
			 const ArraysItemName in,
			 const ArraysCountName cn):
     rn(n),
     dn(_dn),
     ain(in),
     acn(cn)
{
     return;
}

json2xml::RootName json2xml::Option::getRootName() const {
     return rn;
}

json2xml::RootName json2xml::Option::getDefaultName() const {
     return dn;
}

json2xml::ArraysItemName
json2xml::Option::getArraysItemName() const {
     return ain;
}

json2xml::ArraysCountName
json2xml::Option::getArraysCountName() const {
     return acn;
}
//////////////////////////////////////////////////////////////////
