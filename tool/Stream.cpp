//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Stream.hpp"
#include "MyStreamIn.hpp"
#include "MyStreamOut.hpp"
#include "MyStreamFileIn.hpp"
#include "MyStreamFileOut.hpp"

//////////////////////////////////////////////////////////////////
Stream::Stream():
     input(new MyStreamIn),
     output(new MyStreamOut)
{
     return;
}

Stream::~Stream() {
     kill_out();
     kill_in();
}

std::ostream& Stream::out() const {
     return output->get();
}

std::istream& Stream::in() const {
     return input->get();
}

void Stream::set_input(const FileName fn) {
     kill_in();
     input = new MyStreamFileIn(fn);
}

void Stream::set_output(const FileName fn) {
     kill_out();
     output = new MyStreamFileOut(fn);
}

void Stream::open() {
     input->open();
     output->open();
}

void Stream::kill_in() {
     kill(input);
}

void Stream::kill_out() {
     kill(output);
}
//////////////////////////////////////////////////////////////////
