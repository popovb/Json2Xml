//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <ostream>
#include <istream>

#ifndef __Stream__
#define __Stream__

//////////////////////////////////////////////////////////////////
class Stream {
     
public:
     std::ostream& out() const;
     std::istream& in() const;
};
//////////////////////////////////////////////////////////////////
#endif // __Stream__
