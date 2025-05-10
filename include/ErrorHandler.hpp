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

   /*! @brief Prints error prompt
    * @param[in] message text to print in the error prompt
    * @param[in] exitProgram if true the function calls exit(1) after printing error prompt
    */
   void PrintError(const std::string& message, const bool exitProgram = true);
   /*! @brief Prints warning prompt
    * @param[in] message text to print in the error prompt
    */
   void PrintWarning(const std::string& message);
   /*! @brief Returns true if the file exists, else false
    * @param[in] name name of file to be checked
    */
   bool FileExists(const std::string& name);
   /*! @brief Checks whether the file exists or not
    * If files exists the function does nothing, else it prints error or warning
    * @param[in] name name of file to be checked 
    * @param[in] closeAfterFail if true and if file does not exist function prints error and 
    * calls exit(1); if false and file does not exist function simply prints warning
    */
   bool CheckInputFile(const std::string& name, const bool closeAfterFail = true);
   /*! @brief Checks whether the file can be created
    * If files exists the function does nothing, else it prints error or warning
    * @param[in] name name of file to be checked
    * @param[in] closeAfterFail if true and if file cannot be created function prints error and 
    * calls exit(1); if false and file cannot be created function simply prints warning
    * @param[in] openmode used for constructor of ofstream 
    */
   void CheckOutputFile(const std::string& name, const bool closeAfterFail = true,
                        const std::ios_base::openmode openmode = std::ios::out);
}
#endif /* CPP_TOOLS_ERROR_HANDLER_HPP */
