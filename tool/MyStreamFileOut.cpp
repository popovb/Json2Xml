//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "MyStreamFileOut.hpp"

//////////////////////////////////////////////////////////////////
MyStreamFileOut::MyStreamFileOut(const File::Name n):
     File(n)
{
     return;
}

MyStreamFileOut::~MyStreamFileOut() {
     close();
}

void MyStreamFileOut::open() {
     stream.open(name,
		 std::ios_base::out |
		 std::ios_base::binary);
     good(stream);
}

void MyStreamFileOut::close() {
     stream.close();
}

std::ostream& MyStreamFileOut::get() const {
     return (std::ostream&)stream;
}
//////////////////////////////////////////////////////////////////
