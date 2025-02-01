/** 
 *  @file   Box.cpp
 *  @brief  Class Box to print variables name and value in the box in terminal
 *  
 *  In order to use Box class libErrorHandler.so, libIOTools.so, libStrTools.so, libBox.so must be loaded
 *
 *  @author Sergei Antsupov
 **/
#ifndef CPP_TOOLS_BOX_CPP
#define CPP_TOOLS_BOX_CPP

#include "../include/Box.hpp"

CppTools::Box::Box() {}

CppTools::Box::Box(const std::string& boxName, const int width) 
{
   SetName(boxName);
   SetWidth(width);
}

void CppTools::Box::SetName(const std::string& boxName) 
{
   name = boxName;
}

void CppTools::Box::SetWidth(const int width) 
{
   boxWidth = width;
}

void CppTools::Box::AddEntry(const std::string& name, const double value, 
                   const unsigned int precision)
{
   entryNames.push_back(name);
   entryValues.push_back(DtoStr(value, precision));
}

void CppTools::Box::AddEntry(const std::string& name, const int value)
{
   entryNames.push_back(name);
   entryValues.push_back(std::to_string(value));
}

void CppTools::Box::AddEntry(const std::string& name, const short value)
{
   entryNames.push_back(name);
   entryValues.push_back(std::to_string(value));
}

void CppTools::Box::AddEntry(const std::string& name, const long value)
{
   entryNames.push_back(name);
   entryValues.push_back(std::to_string(value));
}

void CppTools::Box::AddEntry(const std::string& name, const unsigned int value)
{
   entryNames.push_back(name);
   entryValues.push_back(std::to_string(value));
}

void CppTools::Box::AddEntry(const std::string& name, const unsigned short value)
{
   entryNames.push_back(name);
   entryValues.push_back(std::to_string(value));
}

void CppTools::Box::AddEntry(const std::string& name, const unsigned long value)
{
   entryNames.push_back(name);
   entryValues.push_back(std::to_string(value));
}

void CppTools::Box::AddEntry(const std::string& name, const std::string& value)
{
   entryNames.push_back(name);
   entryValues.push_back(value);
}

void CppTools::Box::AddEntry(const std::string& name, const bool value)
{
   entryNames.push_back(name);
   entryValues.push_back(BtoStr(value));
}

void CppTools::Box::AddEntry(const std::string& name, const std::vector<double>& values, 
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

void CppTools::Box::AddEntry(const std::string& name, const std::vector<int>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += std::to_string(values[i]) + ", ";
   }
   entryValues.back() += std::to_string(values.back());
}

void CppTools::Box::AddEntry(const std::string& name, const std::vector<short>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += std::to_string(values[i]) + ", ";
   }
   entryValues.back() += std::to_string(values.back());
}

void CppTools::Box::AddEntry(const std::string& name, const std::vector<long>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += std::to_string(values[i]) + ", ";
   }
   entryValues.back() += std::to_string(values.back());
}

void CppTools::Box::AddEntry(const std::string& name, const std::vector<unsigned int>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += std::to_string(values[i]) + ", ";
   }
   entryValues.back() += std::to_string(values.back());
}

void CppTools::Box::AddEntry(const std::string& name, const std::vector<unsigned short>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += std::to_string(values[i]) + ", ";
   }
   entryValues.back() += std::to_string(values.back());
}

void CppTools::Box::AddEntry(const std::string& name, const std::vector<unsigned long>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += std::to_string(values[i]) + ", ";
   }
   entryValues.back() += std::to_string(values.back());
}

void CppTools::Box::AddEntry(const std::string& name, const std::vector<std::string>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += values[i] + ", ";
   }
   entryValues.back() += values.back();
}

void CppTools::Box::AddEntry(const std::string& name, const std::vector<bool>& values)
{
   entryNames.push_back(name);
   entryValues.emplace_back("");
   for (unsigned long i = 0; i < values.size() - 1; i++)
   {
      entryValues.back() += BtoStr(values[i]) + ", ";
   }
   entryValues.back() += BtoStr(values.back());
}

void CppTools::Box::Print(const std::string& titleColor)
{
   if (entryNames.size() == 0) 
   {
      CppTools::PrintWarning("Box cannot be printed: number of entries is 0");
      return;
   }

   PrintSimpleSeparator(" ╔", "═", "╗ ", boxWidth);
   PrintSeparator(name, titleColor, " ║", " ", "║ ", boxWidth);
   PrintSimpleSeparator(" ╟", "─", "╢ ", boxWidth);
   
   for (long unsigned int i = 0; i < entryNames.size(); i++)
   {
      Print2EntrySeparator(entryNames[i], entryValues[i], " ║", "║ ", boxWidth);
   }
   
   PrintSimpleSeparator(" ╚", "═", "╝ ", boxWidth);
}

void CppTools::Box::Clear()
{
   entryNames.clear();
   entryValues.clear();
}

CppTools::Box::~Box()
{
   Clear();
}

#endif /*CPP_TOOLS_BOX_CPP*/
