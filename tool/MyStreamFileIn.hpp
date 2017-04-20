//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "MyStreamIn.hpp"
#include "File.hpp"
#include <fstream>

#ifndef __MyStreamFileIn__
#define __MyStreamFileIn__

//////////////////////////////////////////////////////////////////
class MyStreamFileIn: public MyStreamIn, public File {

public:
     MyStreamFileIn(const File::Name);
     virtual ~MyStreamFileIn();

     virtual void open() override;
     virtual void close() override;
     virtual std::istream& get() const override;

protected:
     std::ifstream stream;
};
//////////////////////////////////////////////////////////////////
#endif // __MyStreamFileIn__
