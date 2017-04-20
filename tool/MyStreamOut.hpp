//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "MyStream.hpp"
#include "Out.hpp"
#include <iostream>

#ifndef __MyStreamOut__
#define __MyStreamOut__

//////////////////////////////////////////////////////////////////
class MyStreamOut: public MyStream, public Out {

public:
     virtual ~MyStreamOut() { }
     
     virtual void open() override { }
     virtual void close() override { }
     virtual std::ostream& get() const override {
	  return std::cout;
     }
};
//////////////////////////////////////////////////////////////////
#endif // __MyStreamOut__
