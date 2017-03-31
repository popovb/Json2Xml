//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <string>
#include <stack>

#ifndef __json2xml_TagHistory_hpp__
#define __json2xml_TagHistory_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     using String = std::string;
     using TagName = String;
     using DefaultTag = TagName;
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     class TagHistory {

     public:
	  TagHistory(const DefaultTag);

	  TagName pop();
	  void push(const TagName);

     private:
	  DefaultTag def_tag;

	  std::stack<TagName> tags;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_TagHistory_hpp__
