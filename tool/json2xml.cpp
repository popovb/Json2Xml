//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Program.hpp"
#include "ArgProcessor.hpp"
#include "Conv.hpp"
#include <iostream>
#include <exception>

//////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {
     Program p;
     ArgProcessor ap(p);
     try {
	  auto config = ap.process(argc, argv);
	  Conv c;
	  c.run(config);
     } catch (std::exception& e) {
	  std::cerr << e.what() << std::endl;
	  return 1;
     }
     return 0;
}
//////////////////////////////////////////////////////////////////
