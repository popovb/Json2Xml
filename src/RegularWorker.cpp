//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "RegularWorker.hpp"

//////////////////////////////////////////////////////////////////
json2xml::RegularWorker::RegularWorker(json2xml::Handler& h):
     handler(h)
{
     return;
}

json2xml::RegularWorker::~RegularWorker() {
     return;
}

void json2xml::RegularWorker::start(const Instructions& ins) {
     for (auto& i : ins) {
	  Argument a1("");
	  Argument a2("");
	  if (i.args.size() > 0) a1 = i.args[0];
	  if (i.args.size() > 1) a2 = i.args[1];

	  switch (i.type) {
	  case InstType::TEXT:
	       handler.Text(a1);
	       break;

	  case InstType::OPEN:
	       handler.OpenTag(a1);
	       break;

	  case InstType::CLOSE:
	       handler.CloseTag(a1);
	       break;

	  case InstType::AV:
	       handler.AttributeValue(a1, a2);
	       break;

	  default:
	       break;
	  }
     }
}
//////////////////////////////////////////////////////////////////
