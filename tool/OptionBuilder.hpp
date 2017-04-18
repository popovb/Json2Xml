//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Config.hpp"
#include <Json2Xml/Option.hpp>

#ifndef __OptionBuilder__
#define __OptionBuilder__

//////////////////////////////////////////////////////////////////
class OptionBuilder {
     
public:
     json2xml::Option build(const Config&) const;
};
//////////////////////////////////////////////////////////////////
#endif // __OptionBuilder__
