//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "String.hpp"
#include <stdexcept>

#ifndef __File__
#define __File__

//////////////////////////////////////////////////////////////////
class File {

public:
     using Name = String;

public:
     File(const Name n): name(n) { }
     virtual ~File() { }

protected:
     const Name name;
     template <class Stream> void good(Stream& s) {
	  if (s.good()) return;
	  throw std::runtime_error("Error in file " + name + "!");
     }
};
//////////////////////////////////////////////////////////////////
#endif // __File__
