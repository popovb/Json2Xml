//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Conv.hpp"
#include "OptionBuilder.hpp"
#include "FormatBuilder.hpp"
#include "StreamBuilder.hpp"
#include <Json2Xml/Converter.hpp>
#include <Json2Xml/PrettyXMLHandler.hpp>
#include <stdexcept>

//////////////////////////////////////////////////////////////////
void Conv::run(Config& cfg) const {
     OptionBuilder ob;
     auto o = ob.build(cfg);
     FormatBuilder fb;
     auto f = fb.build(cfg);
     StreamBuilder sb;
     auto s = sb.build(cfg);
     using namespace json2xml;
     Converter C(o);
     PrettyXMLHandler PXML(s.out(), f.delimiter(), f.shift());
     if (! C.convert(s.in(), PXML)) {
	  throw std::runtime_error("Error of converting!");
     }
     return;
}
//////////////////////////////////////////////////////////////////
