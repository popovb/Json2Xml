//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <SimpleJson/Reader.hpp>
#include <SimpleJson/Common.hpp>
#include "rapidjson/reader.h"
#include "rapidjson/istreamwrapper.h"
#include "StringValues.hpp"

//////////////////////////////////////////////////////////////////
constexpr int parser_flags = rapidjson::kParseStopWhenDoneFlag     |
                             rapidjson::kParseCommentsFlag         |
                             rapidjson::kParseNumbersAsStringsFlag |
                             rapidjson::kParseTrailingCommasFlag;
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
bool simple_json::
Reader::Parse(std::istream& is, Handler& myhan) {
     using namespace rapidjson;
     struct MyHandler: public BaseReaderHandler<UTF8<>, MyHandler> {

	  MyHandler(Handler& h): mh(h) { }

	  bool Null() {
	       mh.Value(strings.Null());
	       return true;
	  }

	  bool Bool(bool b) {
	       mh.Value(strings.Bool(b));
	       return true;
	  }

	  bool Int(int)         { return true; }
	  bool Uint(unsigned)   { return true; }
	  bool Int64(int64_t)   { return true; }
	  bool Uint64(uint64_t) { return true; }
	  bool Double(double)   { return true; }

	  bool String(const char* str, SizeType, bool) {
	       mh.Value(value_t(str));
	       return true;
	  }

	  bool StartObject() {
	       mh.ObjectStart();
	       return true;
	  }

	  bool Key(const char* str, SizeType, bool) {
	       mh.Key(key_t(str));
	       return true;
	  }

	  bool EndObject(SizeType) {
	       mh.ObjectEnd();
	       return true;
	  }

	  bool StartArray() {
	       mh.ArrayStart();
	       return true;
	  }

	  bool EndArray(SizeType) {
	       mh.ArrayEnd();
	       return true;
	  }

     private:
	  Handler& mh;
	  StringValues strings;
     };

     MyHandler handler(myhan);
     IStreamWrapper ss(is);
     rapidjson::Reader r;
     return r.Parse<parser_flags>(ss, handler);
}
//////////////////////////////////////////////////////////////////
