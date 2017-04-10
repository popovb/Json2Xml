//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ObjectHandler.hpp"
#include "Instructions.hpp"
#include "EventLooker.hpp"
#include <Json2Xml/Option.hpp>

#ifndef __json2xml_ObjectStartHandler_hpp__
#define __json2xml_ObjectStartHandler_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     class ObjectStartHandler: public _ObjectHandler {

     public:
	  ObjectStartHandler(const Option&, const Event);

	  Instructions handle(TagHistory&,
			      PlaceLooker&,
			      const Argument = "") const override;
     private:
	  const Option& option;
	  const Event previous;

	  Instructions prev_undef(TagHistory&,
				  const PlaceLooker&) const;
	  Instructions prev_objectstart(TagHistory&,
					const PlaceLooker&) const;
	  Instructions prev_objectend(TagHistory&,
				      const PlaceLooker&) const;
	  Instructions prev_arraystart(TagHistory&,
				       const PlaceLooker&) const;
	  Instructions prev_arrayend(TagHistory&,
				     const PlaceLooker&) const;
	  Instructions prev_key(TagHistory&,
				const PlaceLooker&,
				const Argument) const;
	  Instructions prev_value(TagHistory&,
				  const PlaceLooker&,
				  const Argument) const;
	  Instructions dflt(TagHistory&, const PlaceLooker&) const;

	  Instructions prev_undef_in_object(TagHistory&) const;
	  Instructions prev_undef_in_array(TagHistory&) const;
	  Instructions prev_undef_(TagHistory&) const;

	  Instructions prev_objectstart_in_object(TagHistory&) const;
	  Instructions prev_objectstart_in_array (TagHistory&) const;
	  Instructions prev_objectstart_(TagHistory&) const;

	  Instructions prev_objectend_in_object(TagHistory&) const;
	  Instructions
	  prev_objectend_in_array(TagHistory&,
				  const PlaceLooker::count_t) const;
	  Instructions prev_objectend_(TagHistory&) const;

	  Instructions prev_arraystart_in_object(TagHistory&) const;
	  Instructions
	  prev_arraystart_in_array(TagHistory&,
				   const PlaceLooker::count_t) const;
	  Instructions prev_arraystart_(TagHistory&) const;

	  Instructions prev_arrayend_in_object(TagHistory&) const;
	  Instructions prev_arrayend_in_array(TagHistory&) const;
	  Instructions prev_arrayend_(TagHistory&) const;

	  Instructions prev_key_in_object(TagHistory&,
					  const Argument) const;
	  Instructions prev_key_in_array(TagHistory&,
					 const Argument) const;
	  Instructions prev_key_(TagHistory&, const
				 Argument) const;

	  Instructions prev_value_in_object(TagHistory&,
					    const Argument) const;
	  Instructions prev_value_in_array(TagHistory&,
					   const Argument) const;
	  Instructions prev_value_(TagHistory&,
				   const Argument) const;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_ObjectStartHandler_hpp__
