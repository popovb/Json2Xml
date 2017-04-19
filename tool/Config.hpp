//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "String.hpp"
#include <map>

#ifndef __Config__
#define __Config__

//////////////////////////////////////////////////////////////////
class Config {

public:
     using arg_t = String;
     using val_t = String;
     using section = std::map<arg_t, val_t>;
     using TagNames = section;

public:
     TagNames& getTagNames() const;

private:
     TagNames tn;
};
//////////////////////////////////////////////////////////////////
#endif // __Config__
