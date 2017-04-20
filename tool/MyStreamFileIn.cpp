//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "MyStreamFileIn.hpp"

//////////////////////////////////////////////////////////////////
MyStreamFileIn::MyStreamFileIn(const File::Name n):
     File(n)
{
     return;
}

MyStreamFileIn::~MyStreamFileIn() {
     close();
}

void MyStreamFileIn::open() {
     stream.open(name);
     good(stream);
}

void MyStreamFileIn::close() {
     stream.close();
}

std::istream& MyStreamFileIn::get() const {
     return (std::istream&)stream;
}
//////////////////////////////////////////////////////////////////
