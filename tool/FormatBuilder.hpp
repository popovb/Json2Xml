//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Format.hpp"
#include "String.hpp"

#ifndef __FormatBuilder__
#define __FormatBuilder__

//////////////////////////////////////////////////////////////////
class FormatBuilder {
     
public:
     template <class CFG>
     Format build(CFG& c) const {
	  Format f;
	  auto fc = c.getFormats();
	  if (fc.count(DELIMITER)) {
	       f.set_delimiter(fc[DELIMITER]);
	  }
	  if (fc.count(SHIFT)) {
	       f.set_shift(fc[SHIFT]);
	  }
	  return f;
     }

private:
     const String DELIMITER = "delimiter";
     const String SHIFT     = "shift_width";
};
//////////////////////////////////////////////////////////////////
#endif // __FormatBuilder__
