//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Format.hpp"

//////////////////////////////////////////////////////////////////
Format::Format():
     shift_size(2),
     delimiter_str("\r\n")
{
     return;
}

String Format::delimiter() const {
     return delimiter_str;
}

size_t Format::shift() const {
     return shift_size;
}

void Format::set_delimiter(const String s) {
     delimiter_str = s;
}

void Format::set_shift(const String s) {
     try {
	  shift_size = std::stoi(s);

     } catch (...) { ; }
}
//////////////////////////////////////////////////////////////////
