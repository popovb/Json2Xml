/*
 * Copyright 2008, 2010  Boris Popov <popov.b@gmail.com>
 */

#define NO_DEBUG

#ifndef __mirroring_hpp__
#define __mirroring_hpp__

#include <string>
#include <list>

#ifdef DEBUG
#include <iostream>
#endif

namespace myXML {

namespace mr {

// =========================================== //
   class Pair {

      public:
	 Pair (std::string one,
	       std::string two);
	 ~Pair ();
	 std::string in_value;
	 std::string out_value;
   };
// =========================================== //

// =========================================== //
   typedef std::list <Pair> TranslateTable;
   typedef std::list <Pair>::iterator
      IteratorTranslateTable;
   typedef size_t Position;
   typedef size_t Size;
// =========================================== //

// =========================================== //
   class Mirroring {

      public:
	 Mirroring ();
	 virtual ~Mirroring ();
	 std::string& Fetch (std::string& str);

      protected:
	 void m_Fetch (std::string& str,
	       const Pair pair);
	 TranslateTable m_transTable;
	 void m_Replace (std::string& str,
	       const Pair p,
	       Position& pos);
   };
// =========================================== //

// =========================================== //
   class ToMirror : public Mirroring {

      public:
	 ToMirror ();
   };
// =========================================== //

// =========================================== //
   class FromMirror : public Mirroring {

      public:
	 FromMirror ();
   };
// =========================================== //

}

}
#endif
