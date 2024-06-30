// $HEADER$
//------------------------------------------------------------------------------------------------
//                               Error handler functions declarations
//------------------------------------------------------------------------------------------------
// ErrorHandler
//
// ** Free and open code for anyone to use **
//
// Author: Sergei Antsupov
// Email: antsupov0124@gmail.com
//
/**
 * Basic set of functions for handling errors and warnings
 **/
//------------------------------------------------------------------------------------------------

#ifndef ERROR_HANDLER_HPP
#define ERROR_HANDLER_HPP

#include <iostream>
#include <fstream>

#include "OutputColor.hpp"

void PrintError(std::string message);
void PrintWarning(std::string message);
bool CheckInputFile(std::string name, const bool closeAfterFail = true);
void CheckOutputFile(std::string name);

#endif
