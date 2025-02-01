/** 
 *  @file   ErrorHandler.cpp 
 *  @brief  Useful set of functions to print errors, warning, check existence of files, etc.
 *  
 *  In order to use these functions libErrorHandler.so must be loaded
 *
 *  @author Sergei Antsupov
 **/

#ifndef CPP_TOOLS_ERROR_HANDLER_CPP
#define CPP_TOOLS_ERROR_HANDLER_CPP

#include "../include/ErrorHandler.hpp"

void CppTools::PrintError(const std::string& message, const bool exitProgram)
{
   std::cerr << OutputSnippet::ERROR << message << COLOR_RESET << std::endl;
   if (exitProgram) exit(1);
}

void CppTools::PrintWarning(const std::string& message)
{
   std::cerr << OutputSnippet::WARNING << message << COLOR_RESET << std::endl;
}

bool CppTools::FileExists(const std::string& name)
{
   if (name == "") PrintError("Empty argument was passed for file check");
   std::ifstream file(name.c_str());
   
   if(!file.is_open()) return false;
   return true;
}

bool CppTools::CheckInputFile(const std::string& name, const bool closeAfterFail)
{
   if (!FileExists(name))
   {
      if (closeAfterFail) PrintError("File " + name + " not found");
      else PrintWarning("File " + name + " not found");
      return false;
   }
   return true;
}

void CppTools::CheckOutputFile(const std::string& name, const bool closeAfterFail,
                               const std::ios_base::openmode openmode)
{
   if (name == "") PrintError("Empty argument was passed for output file check");
   std::ofstream file(name.c_str(), openmode);
   if(!file.is_open()) PrintError("File " + name + " cannot be created");
}

#endif /*CPP_TOOLS_ERROR_HANDLER_CPP*/
