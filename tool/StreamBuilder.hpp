//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Stream.hpp"
#include "String.hpp"

#ifndef __StreamBuilder__
#define __StreamBuilder__

//////////////////////////////////////////////////////////////////
class StreamBuilder {
     
public:
     template <class CFG>
     Stream build(const CFG& c) const {
	  Stream s;
	  auto ss = c.getStreams();
	  if (ss.count(INPUT)) {
	       s.set_input(ss[INPUT]);
	  }
	  if (ss.count(OUTPUT)) {
	       s.set_output(ss[OUTPUT]);
	  }
	  s.open();
	  return s;
     }

private:
     const String INPUT  = "input";
     const String OUTPUT = "output";
};
//////////////////////////////////////////////////////////////////
#endif // __StreamBuilder__
