//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Config.hpp"

//////////////////////////////////////////////////////////////////
Config::TagNames& Config::getTagNames() {
     return tn;
}

Config::Formats& Config::getFormats() {
     return fm;
}

Config::Streams& Config::getStreams() {
     return st;
}
//////////////////////////////////////////////////////////////////
