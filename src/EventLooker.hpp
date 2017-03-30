//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#ifndef __json2xml_EventLooker_hpp__
#define __json2xml_EventLooker_hpp__

namespace json2xml {
//////////////////////////////////////////////////////////////////
     enum class Event {
	  UNDEF,
	  OBJECTSTART,
	  OBJECTEND,
	  ARRAYSTART,
	  ARRAYEND,
	  KEY,
	  VALUE
     };
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
     class EventLooker {

     public:
	  EventLooker(const Event = Event::UNDEF,
		      const Event = Event::UNDEF);

	  Event previous() const;
	  Event current() const;

	  void set(const Event);

     private:
	  Event _previous;
	  Event _current;
     };
//////////////////////////////////////////////////////////////////
}
#endif // __json2xml_EventLooker_hpp__
