//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Worker.hpp"
#include <Json2Xml/Handler.hpp>

#ifndef __json2xml_RegularWorker_hpp__
#define __json2xml_RegularWorker_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class RegularWorker: public Worker {

     public:
	  RegularWorker(json2xml::Handler&);
	  virtual ~RegularWorker();

	  virtual void start(const Instructions&) override;

     private:
	  json2xml::Handler& handler;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_RegularWorker_hpp__
