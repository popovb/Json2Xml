//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <Json2Xml/Converter.hpp>
#include "SimpleJson/Reader.hpp"
#include "ConvertHandler.hpp"

//////////////////////////////////////////////////////////////////
json2xml::Converter::Converter(const Option o):
     option(o)
{
     return;
}

bool json2xml::Converter::convert(std::istream& i, Handler& h) {
     simple_json::Reader R;
     ConvertHandler CH(h, option);
     return R.Parse(i, CH);
}
//////////////////////////////////////////////////////////////////
