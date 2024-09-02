// $HEADER$
//------------------------------------------------------------------------------------------------
//                                   Box class declaration
//------------------------------------------------------------------------------------------------
// Box
//
// ** Free and open code for anyone to use **
//
// Author: Sergei Antsupov
// Email: antsupov0124@gmail.com
//
/**
 * Basic tool for putting text output in an ascii box
 **/
//------------------------------------------------------------------------------------------------

#ifndef BOX_HPP
#define BOX_HPP

#include "OutputColor.hpp"
#include "ErrorHandler.hpp"
#include "IOTools.hpp"
#include "StrTools.hpp"

class Box
{
   public:

   Box(const int boxWidth = -1);
   Box(std::string boxName, const int boxWidth = -1);
   void SetName(std::string boxName);
   void AddEntry(std::string entryName, const double entryValue, unsigned const int precision = 2);
   void AddEntry(std::string entryName, const int entryValue);
   void AddEntry(std::string entryName, std::string entryValue);
   void AddEntry(std::string entryName, const bool entryValue);
   void Print(std::string titleColor = OutputColor::GREEN);
   
   virtual ~Box();
   
   protected:
   
   std::string name; 
   std::vector<std::string> entryNames, entryValues;
   unsigned short width;
   void CheckEntry();
};

#endif
