//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "StringValues.hpp"

//////////////////////////////////////////////////////////////////
simple_json::String simple_json::StringValues::Null() {
     return "NULL";
}

simple_json::String
simple_json::StringValues::Bool(const bool b) {
     return (b ? "TRUE" : "FALSE");
}
//////////////////////////////////////////////////////////////////
