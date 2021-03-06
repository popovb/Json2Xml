//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "MyStreamOut.hpp"
#include "File.hpp"
#include <fstream>

#ifndef __MyStreamFileOut__
#define __MyStreamFileOut__

//////////////////////////////////////////////////////////////////
class MyStreamFileOut: public MyStreamOut, public File {

public:
     MyStreamFileOut(const File::Name);
     virtual ~MyStreamFileOut();

     virtual void open() override;
     virtual void close() override;
     virtual std::ostream& get() const override;

protected:
     std::ofstream stream;
};
//////////////////////////////////////////////////////////////////
#endif // __MyStreamFileOut__
