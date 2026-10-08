/** 
 *  @file   ErrorHandler.cpp 
 *  @brief  Contains useful set of functions to print errors, warning, check existence of files, etc.
 *  
 *  In order to use functions from this file libErrorHandler.so must be loaded
 *
 *  This file is a part of a project CppTools (https://github.com/Sergeyir/CppTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef CPP_TOOLS_ERROR_HANDLER_CPP
#define CPP_TOOLS_ERROR_HANDLER_CPP

#include "../include/ErrorHandler.hpp"

void CppTools::PrintError(const std::string& message, const bool exitProgram, 
                          const std::source_location location)
{
   std::cerr << " In " << location.file_name() << '('
              << location.line() << ':' << location.column() << ") `"
              << location.function_name() << "`: " << std::endl;
   std::cerr << ERROR_PROMPT << message << COLOR_RESET << std::endl;
   if (exitProgram) exit(1);
}

void CppTools::PrintWarning(const std::string& message)
{
   std::cerr << WARNING_PROMPT << message << COLOR_RESET << std::endl;
}

bool CppTools::CheckInputFile(const std::string& name, const bool closeAfterFail, 
                              const std::source_location location)
{
   if (!std::filesystem::exists(name))
   {
      if (closeAfterFail) PrintError("File " + name + " not found", true, location);
      else PrintWarning("File " + name + " not found");
      return false;
   }
   return true;
}

#endif /* CPP_TOOLS_ERROR_HANDLER_CPP */
