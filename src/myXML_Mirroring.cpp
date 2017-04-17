/*
 * Copyright 2008, 2010  Boris Popov <popov.b@gmail.com>
 */

#define NO_DEBUG

#include "myXML_Mirroring.hpp"

// =========================================== //
myXML::mr::Mirroring::Mirroring () {
   return;
}

myXML::mr::Mirroring::~Mirroring () {
   m_transTable.clear ();
   return;
}

std::string&
myXML::mr::Mirroring::Fetch (std::string& str) {

   IteratorTranslateTable it;
   IteratorTranslateTable it_end;
   it = m_transTable.begin ();
   it_end = m_transTable.end ();
   while (it != it_end) {
      m_Fetch (str, (*it));
      it++;
   }
   return str;
}

void
myXML::mr::Mirroring::m_Fetch (std::string& str,
      const Pair p) {
   Position pos;
   pos = str.find (p.in_value, 0);
   while (pos != std::string::npos) {
      // вызов replace
      m_Replace (str, p, pos);
      pos = str.find (p.in_value, pos);

      #ifdef DEBUG
      std::cerr << std::endl;
      std::cerr << str;
      #endif

   }
   return;
}

void
myXML::mr::Mirroring::m_Replace (std::string& str,
      const Pair p, Position& pos) {

      std::string::iterator it;
      it = str.begin ();
      Position lpos = 0;
      while (lpos != pos) {
	 lpos++;
	 it++;
      }

      Size sizein = (p.in_value).size ();
      std::string::iterator itend;
      itend = it;
      lpos = 0;
      while (lpos != sizein) {
	 lpos++;
	 itend++;
      }

      str.erase (it, itend);
      str.insert (pos, p.out_value);

      pos = pos + (p.out_value).size ();
   return;
}
// =========================================== //

// =========================================== //
myXML::mr::ToMirror::ToMirror () {
   m_transTable.push_back (Pair ("&", "&amp;"));
   m_transTable.push_back (Pair ("<", "&lt;"));
   m_transTable.push_back (Pair (">", "&gt;"));
   m_transTable.push_back (Pair ("'", "&apos;"));
   m_transTable.push_back (Pair ("\"", "&quot;"));
   return;
}
// =========================================== //

// =========================================== //
myXML::mr::FromMirror::FromMirror () {
   m_transTable.push_back (Pair ("&amp;", "&"));
   m_transTable.push_back (Pair ("&lt;", "<"));
   m_transTable.push_back (Pair ("&gt;", ">"));
   m_transTable.push_back (Pair ("&apos;", "'"));
   m_transTable.push_back (Pair ("&quot;", "\""));
   return;
}
// =========================================== //

// =========================================== //
myXML::mr::Pair::Pair
(std::string one, std::string two) {
   in_value = one;
   out_value = two;
   return;
}

myXML::mr::Pair::~Pair () {
   return;
}
// =========================================== //
