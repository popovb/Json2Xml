//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ArgProcessor.hpp"
#include "args.hxx"
#include <iostream>
#include <string>

//////////////////////////////////////////////////////////////////
ArgProcessor::ArgProcessor(const Program& p):
     program(p)
{
     return;
}

Config ArgProcessor::process(int argc, char** argv) const {
     Config Cfg;
     using namespace args;
     ArgumentParser parser(program.description,
			   program.copyright);
     HelpFlag help(parser,
		   "help",
		   "display this help menu",
		   {'h', "help"});
     Flag version(parser,
		  "version",
		  "display version",
		  {'v', "version"});
     ValueFlag<std::string> input(parser,
				  "input",
				  "input file (default: stdin)",
				  {'i', "input-file"});
     ValueFlag<std::string> output(parser,
				   "output",
				   "output file (default: stdout)",
				   {'o', "output-file"});
     ValueFlag<std::string> delimiter(parser,
				      "delimiter",
				      "line delimiter",
				      {'d'});
     ValueFlag<std::string> shift(parser,
				  "shift",
				  "shift width",
				  {'s'});
     ValueFlag<std::string> tagroot(parser,
				    "tagroot",
				    "root tag name",
				    {"tag_root"});
     ValueFlag<std::string> tagdefault(parser,
				       "tagdefault",
				       "default tag name",
				       {"tag_default"});
     ValueFlag<std::string> tagarritem(parser,
				       "tagarritem",
				       "arrays item tag name",
				       {"tag_arr_item"});
     ValueFlag<std::string> tagarrcount(parser,
					"tagarrcount",
					"arrays count attribute name",
					{"attr_arr_count"});
     try {
	  parser.ParseCLI(argc, argv);
     }
     catch (args::Help) {
	  std::cout << parser;
	  exit(0);
     }
     catch (args::ParseError e) {
	 std::cerr << e.what() << std::endl;
	 std::cerr << parser;
	 exit(2);
     }

     if (version) {
	  std::cout << program.version << std::endl;
	  exit(0);
     }

     if (input) {
	  Cfg.toStreams("input", get(input));
     }

     if (output) {
	  Cfg.toStreams("output", get(output));
     }

     if (delimiter) {
	  Cfg.toFormats("delimiter", get(delimiter));
     }

     if (shift) {
	  Cfg.toFormats("shift_width", get(shift));
     }

     if (tagroot) {
	  Cfg.toTagNames("root_name", get(tagroot));
     }

     if (tagdefault) {
	  Cfg.toTagNames("default_name", get(tagdefault));
     }

     if (tagarritem) {
	  Cfg.toTagNames("arrays_item_name", get(tagarritem));
     }

     if (tagarrcount) {
	  Cfg.toTagNames("arrays_count_name", get(tagarrcount));
     }
     return Cfg;
}
//////////////////////////////////////////////////////////////////
