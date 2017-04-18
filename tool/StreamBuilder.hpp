//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Config.hpp"
#include "Stream.hpp"

#ifndef __StreamBuilder__
#define __StreamBuilder__

//////////////////////////////////////////////////////////////////
class StreamBuilder {
     
public:
     Stream build(const Config&) const;
};
//////////////////////////////////////////////////////////////////
#endif // __StreamBuilder__
