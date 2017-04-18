//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ArgProcessor.hpp"

//////////////////////////////////////////////////////////////////
ArgProcessor::ArgProcessor(const Program& p):
     programm(p)
{
     return;
}

Config ArgProcessor::process(int, char**) const {
     //
     //TODO
     //
     return Config();
}
//////////////////////////////////////////////////////////////////
