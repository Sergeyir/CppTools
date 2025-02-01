/** 
 *  @file   OutputColor.hpp 
 *  @brief  Contains aliases for colors to use in output in terminal
 *
 *  This file is a part of a project CppTools (https://github.com/Sergeyir/CppTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef CPP_TOOLS_OUTPUT_COLOR
#define CPP_TOOLS_OUTPUT_COLOR

#include <string>

/// @namespace CppTools CppTools namespace
namespace CppTools
{
   /// default color in terminal (aka white)
   const std::string COLOR_RESET = "\033[0m";
   /// black text
   const std::string COLOR_BLACK = "\033[30m";
   /// red text
   const std::string COLOR_RED ="\033[31m";
   /// green text
   const std::string COLOR_GREEN = "\033[32m";
   /// yellow text
   const std::string COLOR_YELLOW = "\033[33m";
   /// blue text
   const std::string COLOR_BLUE = "\033[34m";
   /// magenta text
   const std::string COLOR_MAGENTA = "\033[35m";
   /// cyan text
   const std::string COLOR_CYAN = "\033[36m";
   /// white text
   const std::string COLOR_WHITE = "\033[37m";

   /// bold black text
   const std::string COLOR_BOLD_BLACK = "\033[1m\033[30m";
   /// bold red text
   const std::string COLOR_BOLD_RED = "\033[1m\033[31m";
   /// bold green text
   const std::string COLOR_BOLD_GREEN = "\033[1m\033[32m";
   /// bold yellow text
   const std::string COLOR_BOLD_YELLOW = "\033[1m\033[33m";
   /// bold blue text
   const std::string COLOR_BOLD_BLUE = "\033[1m\033[34m";
   /// bold magenta text
   const std::string COLOR_BOLD_MAGENTA = "\033[1m\033[35m";
   /// bold cyan text
   const std::string COLOR_BOLD_CYAN = "\033[1m\033[36m";
   /// bold white text
   const std::string COLOR_BOLD_WHITE = "\033[1m\033[37m";
}

#endif /* CPP_TOOLS_OUTPUT_COLOR */
