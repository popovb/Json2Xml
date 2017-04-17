//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Encoder.hpp"
#include "myXML_Mirroring.hpp"

//////////////////////////////////////////////////////////////////
json2xml::String
json2xml::Encoder::encode(const String s) const {
     if (s.size() == 0) return s;
     String in(s);
     myXML::mr::ToMirror tm;
     return String(tm.Fetch(in));
}
//////////////////////////////////////////////////////////////////
