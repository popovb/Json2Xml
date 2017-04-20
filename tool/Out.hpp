//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <ostream>

#ifndef __Out__
#define __Out__

//////////////////////////////////////////////////////////////////
class Out {

public:
     virtual std::ostream& get() const = 0;
};
//////////////////////////////////////////////////////////////////
#endif // __Out__
