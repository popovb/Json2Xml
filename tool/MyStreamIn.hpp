//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "MyStream.hpp"
#include "In.hpp"
#include <iostream>

#ifndef __MyStreamIn__
#define __MyStreamIn__

//////////////////////////////////////////////////////////////////
class MyStreamIn: public MyStream, public In {

public:
     virtual ~MyStreamIn() { }
     virtual void open() override { }
     virtual void close() override { }
     virtual std::istream& get() const override {
	  return std::cin;
     }
};
//////////////////////////////////////////////////////////////////
#endif // __MyStreamIn__
