/** 
 *  @file   ErrorHandler.hpp 
 *  @brief  Contains useful set of functions to print errors, warning, check existence of files, etc.
 *  
 *  In order to use functions from this file libErrorHandler.so must be loaded
 *
 *  This file is a part of a project CppTools (https://github.com/Sergeyir/CppTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef CPP_TOOLS_ERROR_HANDLER_HPP
#define CPP_TOOLS_ERROR_HANDLER_HPP

#include <iostream>
#include <fstream>
#include <filesystem>

#if (__cplusplus >= 202000L || _MSVC_LANG >= 202000L)
#include <source_location>
#endif

#include "OutputColor.hpp"

/// @namespace CppTools
namespace CppTools
{
   /// String containing red text "ERROR"
   const std::string ERROR_PROMPT = COLOR_RED + " ERROR: " + COLOR_WHITE; 
   /// String containing magenta text "WARNING"
   const std::string WARNING_PROMPT = COLOR_MAGENTA + " WARNING: " + COLOR_RESET; 
   /// String containing green text "INFO"
   const std::string INFO_PROMPT = " [ " + COLOR_GREEN + "INFO" + COLOR_RESET + " ] "; 

#if (__cplusplus >= 202000L || _MSVC_LANG >= 202000L)
   /*! @brief Prints error prompt (C++>=20)
    * @param[in] message text to print in the error prompt
    * @param[in] exitProgram if true the function calls exit(1) after printing error prompt
    */
   void PrintError(const std::string& message, const bool exitProgram = true,
                   const std::source_location location = std::source_location::current());
#else
   /*! @brief Prints error prompt (C++<20)
    * @param[in] message text to print in the error prompt
    * @param[in] exitProgram if true the function calls exit(1) after printing error prompt
    */
   void PrintError(const std::string& message, const bool exitProgram = true, 
                   const char* file = __FILE__, const int line = __LINE__, const char *func = "");
#endif
   /*! @brief Prints warning prompt
    * @param[in] message text to print in the error prompt
    */
   void PrintWarning(const std::string& message);
#if (__cplusplus >= 202000L || _MSVC_LANG >= 202000L)
   /*! @brief Checks whether the file exists or not (C++>=20)
    * If files exists the function does nothing, else it prints error or warning
    * @param[in] name name of file to be checked 
    * @param[in] closeAfterFail if true and if file does not exist function prints error and 
    * calls exit(1); if false and file does not exist function simply prints warning
    */
   bool CheckInputFile(const std::string& name, const bool closeAfterFail = true, 
                       const std::source_location location = std::source_location::current());
#else
   /*! @brief Checks whether the file exists or not (C++<20)
    * If files exists the function does nothing, else it prints error or warning
    * @param[in] name name of file to be checked 
    * @param[in] closeAfterFail if true and if file does not exist function prints error and 
    * calls exit(1); if false and file does not exist function simply prints warning
    */
   bool CheckInputFile(const std::string& name, const bool closeAfterFail = true, 
                       const char* file = __FILE__, const int line = __LINE__, const char* func = "");
#endif
}
#endif /* CPP_TOOLS_ERROR_HANDLER_HPP */
