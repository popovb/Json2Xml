//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ArrayStartHandler.hpp"

//////////////////////////////////////////////////////////////////
json2xml::
ArrayStartHandler::ArrayStartHandler(const Option& o,
				     const Event e):
     option(o),
     previous(e)
{
     return;
}

json2xml::Instructions
json2xml::ArrayStartHandler::handle(TagHistory& th,
				    PlaceLooker& pl,
				    const Argument a) const {
     switch (previous) {
     case Event::UNDEF:
	  return prev_undef(th, pl);
	  
     case Event::OBJECTSTART:
	  return prev_objectstart(th, pl);
	  
     case Event::OBJECTEND:
	  return prev_objectend(th, pl);
	  
     case Event::ARRAYSTART:
	  return prev_arraystart(th, pl);
	  
     case Event::ARRAYEND:
	  return prev_arrayend(th, pl);
	  
     case Event::KEY:
	  return prev_key(th, pl, a);
	  
     case Event::VALUE:
	  return prev_value(th, pl, a);

     default:
	  return dflt(th, pl);
     }
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_undef (TagHistory& th, const PlaceLooker& pl) const {
     if (pl.is_object()) {
	  return prev_undef_in_object(th);
	  
     } else if (pl.is_array()) {
	  return prev_undef_in_array(th);

     } else {
	  return prev_undef_(th);
     }
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_objectstart (TagHistory& th, const PlaceLooker& pl) const {
     if (pl.is_object()) {
	  return prev_objectstart_in_object(th);
	  
     } else if (pl.is_array()) {
	  return prev_objectstart_in_array(th);

     } else {
	  return prev_objectstart_(th);
     }
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_objectend(TagHistory& th, const PlaceLooker& pl) const {
     if (pl.is_object()) {
	  return prev_objectend_in_object(th);
	  
     } else if (pl.is_array()) {
	  return prev_objectend_in_array(th, pl.get_count());

     } else {
	  return prev_objectend_(th);
     }
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_arraystart(TagHistory& th, const PlaceLooker& pl) const {
     if (pl.is_object()) {
	  return prev_arraystart_in_object(th);
	  
     } else if (pl.is_array()) {
	  return prev_arraystart_in_array(th, pl.get_count());

     } else {
	  return prev_arraystart_(th);
     }
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_arrayend(TagHistory& th, const PlaceLooker& pl) const {
     if (pl.is_object()) {
	  return prev_arrayend_in_object(th);
	  
     } else if (pl.is_array()) {
	  return prev_arrayend_in_array(th, pl.get_count());

     } else {
	  return prev_arrayend_(th);
     }
}

json2xml::Instructions json2xml::ArrayStartHandler::
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

json2xml::Instructions json2xml::ArrayStartHandler::
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

json2xml::Instructions json2xml::ArrayStartHandler::
dflt(TagHistory&, const PlaceLooker&) const {
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_undef_in_object(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_undef_in_array(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}
     
json2xml::Instructions json2xml::ArrayStartHandler::
prev_undef_(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_objectstart_in_object(TagHistory& th) const {
     Instructions is;
     Instruction i({ InstType::OPEN, { option.getDefaultName() } });
     is.push_back(i);
     th.push(option.getDefaultName());
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_objectstart_in_array(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_objectstart_(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_objectend_in_object(TagHistory& th) const {
     Instructions is;
     Instruction i({ InstType::OPEN, { option.getDefaultName() } });
     is.push_back(i);
     th.push(option.getDefaultName());
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::   
prev_objectend_in_array(TagHistory& th,
			const PlaceLooker::count_t i) const {
     Instructions is;
     Instruction i1({ InstType::OPEN, { option.getArraysItemName() } });
     Instruction i2({ InstType::AV, { option.getArraysCountName(),
      				      std::to_string(i) } });
     is.push_back(i1);
     is.push_back(i2);
     th.push(option.getArraysItemName());
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::   
prev_objectend_(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::   
prev_arraystart_in_object(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::        
prev_arraystart_in_array(TagHistory& th,
			 const PlaceLooker::count_t i) const {
  Instructions is;
     Instruction i1({ InstType::OPEN, { option.getArraysItemName() } });
     Instruction i2({ InstType::AV, { option.getArraysCountName(),
				      std::to_string(i) } });
     is.push_back(i1);
     is.push_back(i2);
     th.push(option.getArraysItemName());
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_arraystart_(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_arrayend_in_object(TagHistory& th) const {
     Instructions is;
     Instruction i({ InstType::OPEN, { option.getDefaultName() } });
     is.push_back(i);
     th.push(option.getDefaultName());
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::
prev_arrayend_in_array(TagHistory& th,
		       const PlaceLooker::count_t i) const {
     Instructions is;
     Instruction i1({ InstType::OPEN, { option.getArraysItemName() } });
     Instruction i2({ InstType::AV, { option.getArraysCountName(),
				      std::to_string(i) } });
     is.push_back(i1);
     is.push_back(i2);
     th.push(option.getArraysItemName());
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::     
prev_arrayend_(TagHistory&) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::     
prev_key_in_object(TagHistory&,
		   const Argument) const {
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::          
prev_key_in_array(TagHistory&,
		  const Argument) const {
     Instructions is;
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::          
prev_key_(TagHistory&, const
	  Argument) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}
     
json2xml::Instructions json2xml::ArrayStartHandler::          
prev_value_in_object(TagHistory& th,
		     const Argument) const {
     Instructions is;
     Instruction i({ InstType::OPEN, { option.getDefaultName() } });
     is.push_back(i);
     th.push(option.getDefaultName());
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::               
prev_value_in_array(TagHistory& th,
		    const Argument,
		    const PlaceLooker::count_t i) const {
     Instructions is;
     Instruction i1({ InstType::OPEN, { option.getArraysItemName() } });
     Instruction i2({ InstType::AV, { option.getArraysCountName(),
				      std::to_string(i) } });
     is.push_back(i1);
     is.push_back(i2);
     th.push(option.getArraysItemName());
     return is;
}

json2xml::Instructions json2xml::ArrayStartHandler::                    
prev_value_(TagHistory&,
	    const Argument) const {
     //NOT SUPPORT
     Instructions is;
     return is;
}
//////////////////////////////////////////////////////////////////
