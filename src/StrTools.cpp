/** 
 *  @file   StrTools.cpp 
 *  @brief  Contains useful set of functions to work with std::string and to convert various types in std::string
 *  
 *  In order to use functions from this file libStrTools.so must be loaded
 *
 *  This file is a part of a project CppTools (https://github.com/Sergeyir/CppTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef CPP_TOOLS_STR_TOOLS_CPP
#define CPP_TOOLS_STR_TOOLS_CPP

#include "../include/StrTools.hpp"

int CppTools::utf8_strlen(const std::string& str)
{
   int length = 0;
   for (long unsigned int i=0; i < str.length(); i++, length++)
   {
      const unsigned char c = (unsigned char) str[i];
      if      (c>=0 && c<=127)     i+=0;
      else if ((c & 0xE0) == 0xC0) i+=1;
      else if ((c & 0xF0) == 0xE0) i+=2;
      else if ((c & 0xF8) == 0xF0) i+=3;
      else return 0;
   }
   return length;
}

std::string CppTools::RemoveObsoletePrecision(std::string str)
{
   for (unsigned long i = str.size()-1; i > str.find("."); i--)
   {
      if (str[i] == '0') str.erase(i);
      else break;
   }
   // removes '.' if no numbers remain after it
   if (str.size() - 1 == str.find(".")) str.erase(str.size() - 1); 
   return str;
}

std::string CppTools::RemoveObsoletePrecision(const double value)
{
   return RemoveObsoletePrecision(std::to_string(value));
}

std::string CppTools::DtoStr(const double val, const int precision)
{
   std::stringstream ssval;
   ssval << std::fixed << std::setprecision(precision) << val;
   return ssval.str();
}

std::string CppTools::BtoStr(const bool val)
{
   if (val) return "true";
   return "false";
}

#endif /* CPP_TOOLS_STR_TOOLS_CPP */
