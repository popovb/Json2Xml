//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Instructions.hpp"

//////////////////////////////////////////////////////////////////
bool json2xml::operator==(const Instruction& l,
			  const Instruction& r) {
     if (l.type == r.type)
	  if (l.args == r.args) return true;
     return false;
}

bool json2xml::operator!=(const Instruction& l,
			  const Instruction& r) {
     if (l.type != r.type) return true;
     if (l.args != r.args) return true;
     return false;
}
//////////////////////////////////////////////////////////////////
