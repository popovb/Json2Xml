//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <Json2Xml/PrettyXMLHandler.hpp>
#include "TagBuilder.hpp"
#include "Encoder.hpp"

//////////////////////////////////////////////////////////////////
json2xml::PrettyXMLHandler::PrettyXMLHandler(std::ostream& s,
					     const LineDelimiter l,
					     const size_t sz):
     stream(s),
     ld(l),
     shifter(sz),
     builder(new TagBuilder),
     encoder(new Encoder)
{
     return;
}

json2xml::PrettyXMLHandler::~PrettyXMLHandler() {
     if (encoder != nullptr) delete encoder;
     if (builder != nullptr) delete builder;
}

void json2xml::PrettyXMLHandler::Text(const String s) {
     previousTag();
     stream << shifter.get();
     stream << encoder->encode(s);
     stream << ld;
}

void json2xml::PrettyXMLHandler::OpenTag(const String s) {
     previousTag();
     builder->buildOpenTag(encoder->encode(s));
}

void json2xml::PrettyXMLHandler::CloseTag(const String s) {
     previousTag();
     shifter--;
     stream << shifter.get();
     stream << builder->getCloseTag(encoder->encode(s));
     stream << ld;
}

void json2xml::PrettyXMLHandler::AttributeValue(const String s1,
						const String s2) {
     builder->setAttributeValue(encoder->encode(s1),
				encoder->encode(s2));
}

void json2xml::PrettyXMLHandler::previousTag() {
     if (builder->hasTag()) {
	  stream << shifter.get();
	  stream << builder->getTag();
	  stream << ld;
	  shifter++;
     }
}
//////////////////////////////////////////////////////////////////
