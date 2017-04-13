//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ValueHandler.hpp"

//////////////////////////////////////////////////////////////////
json2xml::ValueHandler::ValueHandler(const Option& o,
				     const Event p):
     option(o),
     previous(p)
{
     return;
}

json2xml::Instructions
json2xml::ValueHandler::handle(TagHistory& th,
			       PlaceLooker& pl,
			       const Argument a) const {
     switch (previous) {
     case Event::UNDEF:
	  return prev_undef(th, pl);
	  
     case Event::OBJECTSTART:
	  return prev_objectstart(th, pl, a);
	  
     case Event::OBJECTEND:
	  return prev_objectend(th, pl, a);
	  
     case Event::ARRAYSTART:
	  return prev_arraystart(th, pl, a);
	  
     case Event::ARRAYEND:
	  return prev_arrayend(th, pl, a);
	  
     case Event::KEY:
	  return prev_key(th, pl, a);
	  
     case Event::VALUE:
	  return prev_value(th, pl, a);

     default:
	  return dflt(th, pl);
     }
     /*
     Instructions is;
     if (pl.is_array()) {
	  Instruction i1({ InstType::OPEN,
			   { option.getArraysItemName() } });
	  Instruction i2({ InstType::AV,
			   { option.getArraysCountName(),
			     std::to_string(pl.get_count()) } });
	  Instruction i3({ InstType::TEXT, { v } });
	  Instruction i4({ InstType::CLOSE,
			   { option.getArraysItemName() } });
	  is.push_back(i1);
	  is.push_back(i2);
	  is.push_back(i3);
	  is.push_back(i4);

     } else {
	  Instruction i({ InstType::TEXT, { v } });
	  is.push_back(i);
     }
     //
     //TODO
     //
     return is;
     */
}


json2xml::Instructions json2xml::ValueHandler::
prev_undef (TagHistory& th, const PlaceLooker& pl) const {
     if (pl.is_object()) {
	  return prev_undef_in_object(th);
	  
     } else if (pl.is_array()) {
	  return prev_undef_in_array(th);

     } else {
	  return prev_undef_(th);
     }
}

json2xml::Instructions json2xml::ValueHandler::
prev_objectstart (TagHistory& th,
		  const PlaceLooker& pl,
		  const Argument a) const {
     if (pl.is_object()) {
	  return prev_objectstart_in_object(th, a);
	  
     } else if (pl.is_array()) {
	  return prev_objectstart_in_array(th, a);

     } else {
	  return prev_objectstart_(th);
     }
}

json2xml::Instructions json2xml::ValueHandler::
prev_objectend(TagHistory& th,
	       const PlaceLooker& pl,
	       const Argument a) const {
     if (pl.is_object()) {
	  return prev_objectend_in_object(th, a);
	  
     } else if (pl.is_array()) {
	  return prev_objectend_in_array(th, pl.get_count(), a);

     } else {
	  return prev_objectend_(th);
     }
}

json2xml::Instructions json2xml::ValueHandler::
prev_arraystart(TagHistory& th,
		const PlaceLooker& pl,
		const Argument a) const {
     if (pl.is_object()) {
	  return prev_arraystart_in_object(th);
	  
     } else if (pl.is_array()) {
	  return prev_arraystart_in_array(th,
					  pl.get_count(),
					  a);

     } else {
	  return prev_arraystart_(th);
     }
}

json2xml::Instructions json2xml::ValueHandler::
prev_arrayend(TagHistory& th,
	      const PlaceLooker& pl,
	      const Argument a) const {
     if (pl.is_object()) {
	  return prev_arrayend_in_object(th, a);
	  
     } else if (pl.is_array()) {
	  return prev_arrayend_in_array(th,
					pl.get_count(),
					a);
     } else {
	  return prev_arrayend_(th);
     }
}

json2xml::Instructions json2xml::ValueHandler::
prev_key(TagHistory& th, const PlaceLooker& pl,
	 const Argument a) const {
     if (pl.is_object()) {
	  return prev_key_in_object(th, a);
	  
     } else if (pl.is_array()) {
	  return prev_key_in_array(th, a);

     } else {
	  return prev_key_(th, a);
     }
}

json2xml::Instructions json2xml::ValueHandler::
prev_value(TagHistory& th, const PlaceLooker& pl,
	   const Argument a) const {
     if (pl.is_object()) {
	  return prev_value_in_object(th, a);
	  
     } else if (pl.is_array()) {
	  return prev_value_in_array(th, a, pl.get_count());

     } else {
	  return prev_value_(th, a);
     }
}

json2xml::Instructions json2xml::ValueHandler::
dflt(TagHistory&, const PlaceLooker&) const {
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ValueHandler::
prev_undef_in_object(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ValueHandler::
prev_undef_in_array(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}
     
json2xml::Instructions json2xml::ValueHandler::
prev_undef_(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ValueHandler::
prev_objectstart_in_object(TagHistory& th,
			   const Argument a) const {
     Instructions is;
     Instruction i0({ InstType::OPEN,
		      { option.getDefaultName() } });
     Instruction i1({ InstType::TEXT,
		      { a } });
     Instruction i2({ InstType::CLOSE,
		      { option.getDefaultName() } });
     is.push_back(i0);
     is.push_back(i1);
     is.push_back(i2);
     return is;
}

json2xml::Instructions json2xml::ValueHandler::
prev_objectstart_in_array(TagHistory&,
			  const Argument) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ValueHandler::
prev_objectstart_(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ValueHandler::
prev_objectend_in_object(TagHistory& th,
			 const Argument a) const {
     Instructions is;
     Instruction i0({ InstType::OPEN,
		      { option.getDefaultName() } });
     Instruction i1({ InstType::TEXT,
		      { a } });
     Instruction i2({ InstType::CLOSE,
		      { option.getDefaultName() } });
     is.push_back(i0);
     is.push_back(i1);
     is.push_back(i2);
     return is;
}

json2xml::Instructions json2xml::ValueHandler::   
prev_objectend_in_array(TagHistory& th,
			const PlaceLooker::count_t i,
			const Argument a) const {
     //
     //TODO
     //
     Instructions is;
     // Instruction i1({ InstType::OPEN, { option.getArraysItemName() } });
     // Instruction i2({ InstType::AV, { option.getArraysCountName(),
     // 				      std::to_string(i) } });
     // Instruction i3({ InstType::AV, { "name", a } });
     // is.push_back(i1);
     // is.push_back(i2);
     // is.push_back(i3);
     // th.push(option.getArraysItemName());
     return is;
}

json2xml::Instructions json2xml::ValueHandler::   
prev_objectend_(TagHistory&) const {
     //
     //TODO
     //
     // //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ValueHandler::   
prev_arraystart_in_object(TagHistory&) const {
     //
     //TODO
     //
     // //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ValueHandler::        
prev_arraystart_in_array(TagHistory& th,
			 const PlaceLooker::count_t i,
			 const Argument a) const {
     //
     //TODO
     //
     Instructions is;
     // Instruction i1({ InstType::OPEN, { option.getArraysItemName() } });
     // Instruction i2({ InstType::AV, { option.getArraysCountName(),
     // 				      std::to_string(i) } });
     // Instruction i3({ InstType::AV, { "name", a } });
     // is.push_back(i1);
     // is.push_back(i2);
     // is.push_back(i3);
     // th.push(option.getArraysItemName());
     return is;
}

json2xml::Instructions json2xml::ValueHandler::
prev_arraystart_(TagHistory&) const {
     //
     //TODO
     //
     // //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ValueHandler::
prev_arrayend_in_object(TagHistory& th,
			const Argument a) const {
     //
     //TODO
     //
     Instructions is;
     // Instruction i({ InstType::OPEN, { a } });
     // is.push_back(i);
     // th.push(a);
     return is;
}

json2xml::Instructions json2xml::ValueHandler::
prev_arrayend_in_array(TagHistory& th,
		       const PlaceLooker::count_t i,
		       const Argument a) const {
     //
     //TODO
     //
     Instructions is;
     // Instruction i1({ InstType::OPEN, { option.getArraysItemName() } });
     // Instruction i2({ InstType::AV, { option.getArraysCountName(),
     // 				      std::to_string(i) } });
     // Instruction i3({ InstType::AV, { "name", a } });
     // is.push_back(i1);
     // is.push_back(i2);
     // is.push_back(i3);
     // th.push(option.getArraysItemName());
     return is;
}

json2xml::Instructions json2xml::ValueHandler::     
prev_arrayend_(TagHistory&) const {
     //
     //TODO
     //
     // //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ValueHandler::     
prev_key_in_object(TagHistory&,
		   const Argument) const {
     //
     //TODO
     //
     // //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ValueHandler::          
prev_key_in_array(TagHistory&,
		  const Argument) const { 
     //
     //TODO
     //
     // //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ValueHandler::          
prev_key_(TagHistory&, const
	  Argument) const {
     //
     //TODO
     //
     // //NOT SUPPORT
     Instructions is;
     return is;
}
     
json2xml::Instructions json2xml::ValueHandler::          
prev_value_in_object(TagHistory& th,
		     const Argument a) const {
     //
     //TODO
     //
     Instructions is;
     // Instruction i({ InstType::OPEN, { a } });
     // is.push_back(i);
     // th.push(a);
     return is;
}

json2xml::Instructions json2xml::ValueHandler::               
prev_value_in_array(TagHistory& th,
		    const Argument a,
		    const PlaceLooker::count_t i) const {
     //
     //TODO
     //
     Instructions is;
     // Instruction i1({ InstType::OPEN, { option.getArraysItemName() } });
     // Instruction i2({ InstType::AV, { option.getArraysCountName(),
     // 				      std::to_string(i) } });
     // Instruction i3({ InstType::AV, { "name", a } });
     // is.push_back(i1);
     // is.push_back(i2);
     // is.push_back(i3);
     // th.push(option.getArraysItemName());
     return is;
}

json2xml::Instructions json2xml::ValueHandler::                    
prev_value_(TagHistory&,
	    const Argument) const {
     //
     //TODO
     //
     // //NOT SUPPORT
     Instructions is;
     return is;
}
//////////////////////////////////////////////////////////////////
