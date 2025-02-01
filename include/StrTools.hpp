/** 
 *  @file   StrTools.hpp 
 *  @brief  Contains useful set of functions to work with std::string and to convert various types in std::string
 *  
 *  In order to use functions from this file libStrTools.so must be loaded
 *
 *  This file is a part of a project CppTools (https://github.com/Sergeyir/CppTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef CPP_TOOLS_STR_TOOLS_HPP
#define CPP_TOOLS_STR_TOOLS_HPP

#include <string>
#include <sstream>
#include <iomanip>

/// @namespace CppTools CppTools namespace
namespace CppTools
{
   /*! @brief Returns the length of the std::string type variable
    * @param[in] str stringh the length of which will be returned
    * @param[out] length the length of the passed string 
    */
   int utf8_strlen(const std::string& str);
   /*! @brief Converts double to std::string with the given precision
    * @param[in] val value to be converted 
    * @param[in] precision floating point precision
    * @param[out] string converted into string value
    */
   std::string DtoStr(const double val, const int precision = 2);
   /*! @brief Removes every 0 until first non-zero value from right to left after the dot
    *
    * Example: if the value is "5.240100" the function will return "5.2401"
    * @param[in] str string representation of floating point variable
    * @param[out] str input variable with obsolete precision removed
    */
   std::string RemoveObsoletePrecision(std::string str);
   /*! @brief Converts to std::string and removes every 0 until first non-zero value from right to left after the dot
    *
    * Example: if the value is 5.240100 the function will return "5.2401"
    * @param[in] value variable to be converted and "trimmed" of the obsolete precision
    * @param[out] str input variable with obsolete precision removed
    */
   std::string RemoveObsoletePrecision(const double value);
   /*! @brief Converts bool into std::string 
    * @param[in] val bool variable 
    * @param[out] boolalpha string variable that is either "true" or "false"
    */
   std::string BtoStr(const bool val);
}

#endif /* CPP_TOOLS_STR_TOOLS_HPP */
