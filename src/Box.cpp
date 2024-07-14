// $SOURCE$
//------------------------------------------------------------------------------------------------
//                                   Box class realisation
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

#ifndef BOX_CPP
#define BOX_CPP

#include "../include/Box.hpp"

Box::Box(const int boxWidth) 
{
   if (width > 0) width = boxWidth;
   else width = GetTerminalWidth();
}

Box::Box(std::string boxName, const int boxWidth)
{
   name = boxName;
   if (width > 0) width = boxWidth;
   else width = GetTerminalWidth();
}

void Box::SetName(std::string boxName)
{
   name = boxName;
}

void Box::AddEntry(std::string entryName, const double entryValue, unsigned const int precision)
{
   entryNames.push_back(entryName);
   entryValues.push_back(DtoStr(entryValue, precision));
   CheckEntry();
}

void Box::AddEntry(std::string entryName, const int entryValue)
{
   entryNames.push_back(entryName);
   entryValues.push_back(std::to_string(entryValue));
   CheckEntry();
}

void Box::AddEntry(std::string entryName, std::string entryValue)
{
   entryNames.push_back(entryName);
   entryValues.push_back(entryValue);
   CheckEntry();
}

void Box::AddEntry(std::string entryName, const bool entryValue)
{
   entryNames.push_back(entryName);
   entryValues.push_back(BtoStr(entryValue));
   CheckEntry();
}

void Box::Print(std::string titleColor)
{
   if (entryNames.size() == 0) 
   {
      PrintWarning("Box cannot be printed: number of entries is 0");
      return;
   }
   
   PrintSimpleSeparator(" ╔", "═", "╗", width);
   PrintSeparator(name, titleColor, " ║", " ", "║", width);
   PrintSimpleSeparator(" ╟", "─", "╢", width);
   
   for (long unsigned int i = 0; i < entryNames.size(); i++)
   {
      PrintEdgedLine(entryNames[i], entryValues[i], " ║", "║", width);
   }
   
   PrintSimpleSeparator(" ╚", "═", "╝", width);
   
   entryNames.clear();
   entryValues.clear();
}

Box::~Box()
{
   entryNames.clear();
   entryValues.clear();
}

void Box::CheckEntry()
{
   if (static_cast<int>(entryNames.back().length() + entryValues.back().length()) > width - 2)
   {
      PrintWarning("Box entry " + entryNames.back() + " is too long: it will not be printed");
      entryNames.pop_back();
      entryValues.pop_back();
   }
}

#endif
