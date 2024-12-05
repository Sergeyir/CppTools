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

Box::Box() {}

Box::Box(const std::string& boxName) 
{
   name = boxName;
}

void Box::SetName(const std::string& boxName) 
{
   name = boxName;
}

void Box::AddEntry(const std::string& entryName, const double entryValue, 
                   const unsigned int precision)
{
   entryNames.push_back(entryName);
   entryValues.push_back(DtoStr(entryValue, precision));
}

void Box::AddEntry(const std::string& entryName, const int entryValue)
{
   entryNames.push_back(entryName);
   entryValues.push_back(std::to_string(entryValue));
}

void Box::AddEntry(const std::string& entryName, const short entryValue)
{
   entryNames.push_back(entryName);
   entryValues.push_back(std::to_string(entryValue));
}

void Box::AddEntry(const std::string& entryName, const long entryValue)
{
   entryNames.push_back(entryName);
   entryValues.push_back(std::to_string(entryValue));
}

void Box::AddEntry(const std::string& entryName, const unsigned int entryValue)
{
   entryNames.push_back(entryName);
   entryValues.push_back(std::to_string(entryValue));
}

void Box::AddEntry(const std::string& entryName, const unsigned short entryValue)
{
   entryNames.push_back(entryName);
   entryValues.push_back(std::to_string(entryValue));
}

void Box::AddEntry(const std::string& entryName, const unsigned long entryValue)
{
   entryNames.push_back(entryName);
   entryValues.push_back(std::to_string(entryValue));
}

void Box::AddEntry(const std::string& entryName, const std::string& entryValue)
{
   entryNames.push_back(entryName);
   entryValues.push_back(entryValue);
}

void Box::AddEntry(const std::string& entryName, const bool entryValue)
{
   entryNames.push_back(entryName);
   entryValues.push_back(BtoStr(entryValue));
}

void Box::Print(const std::string& titleColor)
{
   if (entryNames.size() == 0) 
   {
      PrintWarning("Box cannot be printed: number of entries is 0");
      return;
   }

   const unsigned short width = GetTerminalWidth() - 1;
   
   PrintSimpleSeparator(" ╔", "═", "╗", width);
   PrintSeparator(name, titleColor, " ║", " ", "║", width);
   PrintSimpleSeparator(" ╟", "─", "╢", width);
   
   for (long unsigned int i = 0; i < entryNames.size(); i++)
   {
      PrintEdgedLine(entryNames[i], entryValues[i], " ║", "║", width);
   }
   
   PrintSimpleSeparator(" ╚", "═", "╝", width);   
}

void Box::Clear()
{
   entryNames.clear();
   entryValues.clear();
}

Box::~Box()
{
   Clear();
}

#endif /*BOX_CPP*/
