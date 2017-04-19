//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "String.hpp"

#ifndef __Format__
#define __Format__

//////////////////////////////////////////////////////////////////
class Format {
     
public:
     String delimiter() const;
     size_t shift() const;

     void set_delimiter(const String);
     void set_shift(const String);
};
//////////////////////////////////////////////////////////////////
#endif // __Format__
