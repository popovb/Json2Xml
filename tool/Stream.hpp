//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "String.hpp"
#include <ostream>
#include <istream>

#ifndef __Stream__
#define __Stream__

//////////////////////////////////////////////////////////////////
class MyStreamOut;
class MyStreamIn;
class Stream {

public:
     using FileName = String;
     
public:
     Stream();
     ~Stream();

     std::ostream& out() const;
     std::istream& in() const;

     void set_input(const FileName);
     void set_output(const FileName);

     void open();

private:
     MyStreamIn* input;
     MyStreamOut* output;

     void kill_in();
     void kill_out();

     template <class Obj> void kill(Obj* obj) {
	  if (obj != nullptr) {
	       obj->close();
	       delete obj;
	  }
     }
};
//////////////////////////////////////////////////////////////////
#endif // __Stream__
