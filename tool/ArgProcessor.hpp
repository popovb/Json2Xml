//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Program.hpp"
#include "Config.hpp"

#ifndef __ArgProcessor__
#define __ArgProcessor__

//////////////////////////////////////////////////////////////////
class ArgProcessor {
     
public:
     ArgProcessor(const Program&);

     Config process(int, char**) const;
};
//////////////////////////////////////////////////////////////////
#endif // __ArgProcessor__
