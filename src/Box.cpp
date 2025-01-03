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

void Box::AddEntry(const std::string& name, const double value, 
                   const unsigned int precision)
{
   entryNames.push_back(name);
   entryValues.push_back(DtoStr(value, precision));
}

void Box::AddEntry(const std::string& name, const int value)
{
   entryNames.push_back(name);
   entryValues.push_back(std::to_string(value));
}

void Box::AddEntry(const std::string& name, const short value)
{
   entryNames.push_back(name);
   entryValues.push_back(std::to_string(value));
}

void Box::AddEntry(const std::string& name, const long value)
{
   entryNames.push_back(name);
   entryValues.push_back(std::to_string(value));
}

void Box::AddEntry(const std::string& name, const unsigned int value)
{
   entryNames.push_back(name);
   entryValues.push_back(std::to_string(value));
}

void Box::AddEntry(const std::string& name, const unsigned short value)
{
   entryNames.push_back(name);
   entryValues.push_back(std::to_string(value));
}

void Box::AddEntry(const std::string& name, const unsigned long value)
{
   entryNames.push_back(name);
   entryValues.push_back(std::to_string(value));
}

void Box::AddEntry(const std::string& name, const std::string& value)
{
   entryNames.push_back(name);
   entryValues.push_back(value);
}

void Box::AddEntry(const std::string& name, const bool value)
{
   entryNames.push_back(name);
   entryValues.push_back(BtoStr(value));
}

void Box::AddEntry(const std::string& name, const std::vector<double>& values, 
                   const unsigned int precision)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += DtoStr(values[i], precision) + ", ";
   }
   entryValues.back() += DtoStr(values.back(), precision);
}

void Box::AddEntry(const std::string& name, const std::vector<int>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += std::to_string(values[i]) + ", ";
   }
   entryValues.back() += std::to_string(values.back());
}

void Box::AddEntry(const std::string& name, const std::vector<short>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += std::to_string(values[i]) + ", ";
   }
   entryValues.back() += std::to_string(values.back());
}

void Box::AddEntry(const std::string& name, const std::vector<long>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += std::to_string(values[i]) + ", ";
   }
   entryValues.back() += std::to_string(values.back());
}

void Box::AddEntry(const std::string& name, const std::vector<unsigned int>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += std::to_string(values[i]) + ", ";
   }
   entryValues.back() += std::to_string(values.back());
}

void Box::AddEntry(const std::string& name, const std::vector<unsigned short>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += std::to_string(values[i]) + ", ";
   }
   entryValues.back() += std::to_string(values.back());
}

void Box::AddEntry(const std::string& name, const std::vector<unsigned long>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += std::to_string(values[i]) + ", ";
   }
   entryValues.back() += std::to_string(values.back());
}

void Box::AddEntry(const std::string& name, const std::vector<std::string>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += values[i] + ", ";
   }
   entryValues.back() += values.back();
}

void Box::AddEntry(const std::string& name, const std::vector<bool>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += BtoStr(values[i]) + ", ";
   }
   entryValues.back() += BtoStr(values.back());
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
