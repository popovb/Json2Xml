//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "TagHistory.hpp"

//////////////////////////////////////////////////////////////////
json2xml::TagHistory::TagHistory(const DefaultTag dt):
     def_tag(dt)
{
     return;
}

json2xml::DefaultTag json2xml::TagHistory::pop() {
     if (tags.size() == 0) return def_tag;
     auto r = tags.top();
     tags.pop();
     return r;
}

void json2xml::TagHistory::push(const TagName tn) {
     tags.push(tn);
}
//////////////////////////////////////////////////////////////////
