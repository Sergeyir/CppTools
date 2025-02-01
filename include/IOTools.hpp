/** 
 *  @file   IOTools.hpp 
 *  @brief  Contains useful set of functions to work with std::string and to convert various types in std::string
 *  
 *  In order to use functions from this file libStrTools.so must be loaded
 *
 *  This file is a part of a project CppTools (https://github.com/Sergeyir/CppTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef CPP_TOOLS_IOTOOLS_HPP
#define CPP_TOOLS_IOTOOLS_HPP

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <vector>

#include "ErrorHandler.hpp"
#include "StrTools.hpp"

/// @namespace CppTools CppTools namespace
namespace CppTools
{
   /*! @brief Variadic print functions
    * @param[in] args parameter pack, every element of which will be printed
    */
   template <typename... T>
   void Print(T... args)
   {
      ((std::cout << args << " "), ...);
      std::cout << std::endl;
   }

   /*! @brief Returns terminal width
    */
   int GetTerminalWidth();
   /*! @brief Prints info prompt
    * @param[in] message text to be printed in the info prompt
    */
   void PrintInfo(const std::string& message);
   /*! @brief Prints vertical separator (with width of terminal by default)
    * 
    * @param[in] leftEdge - left edge of a separator, only printed once
    * @param[in] body - body of a separator, can be printed multiple times to fill in the length.
    * @param[in] rightEdge - right edge of a separator, only printed once
    * @param[in] length - length of a separator; negative values will result separator to be printed with a width of a terminal
    *
    * Example: Calling PrintSimpleSeparator("|", "*", "|", 7) will print
    *
      \verbatim
      |*****|
      \endverbatim
    */
   void PrintSimpleSeparator(const std::string& leftEdge = "|", const std::string& body = "-", 
                             const std::string& rightEdge = "|", int length = -1);
   /*! @brief Prints vertical separator (with width of terminal by default) with message in the middle
    * @param[in] message - text to be printed in the middle
    * @param[in] color - color of the message (see OutputColors.hpp file)
    * @param[in] leftEdge - left edge of a separator, only printed once
    * @param[in] body - body of a separator, can be printed multiple times to fill in the length.
    * @param[in] rightEdge - right edge of a separator, only printed once
    * @param[in] length - length of a separator; negative values will result separator to be printed with a width of a terminal
    *
    * Example: Calling PrintSeparator("text", "", "|", "*", "|", 12) will print (note the spaces on the left and on the right since they contribute to the length)
    *
      \verbatim
      |***text***|
      \endverbatim
    */
   void PrintSeparator(const std::string& message, const std::string& color = "", 
                       const std::string& leftEdge = "//",  const std::string& body = "-", 
                       const std::string& rightEdge = "//", int length = -1);
   /*! @brief Prints vertical separator (with width of terminal by default) with one text entry on the left and the other on the left
    * @param[in] entry1 - text to be printed on the left
    * @param[in] entry2 - text to be printed on the right
    * @param[in] leftEdge - left edge of a separator, only printed once
    * @param[in] rightEdge - right edge of a separator, only printed once
    * @param[in] length - length of a separator; negative values will result separator to be printed with a width of a terminal
    *
    * Example: Calling Print2EntrySeparator("left", "right", "|", "|", 20) will print without quotes
    *
      \verbatim
      | left       right |
      \endverbatim
    */
   void Print2EntrySeparator(const std::string& entry1, const std::string& entry2, 
                             const std::string& leftEdge = "|", const std::string& rightEdge = "|", 
                             int length = -1);
   /*! @brief Prints vertical separator (with width of terminal by default) constisting of 3 lines with message in the middle
    * @param[in] message - text to be printed in the middle
    * @param[in] ULCorner - upper left corner of a separator 
    * @param[in] URCorner - upper right corner of a separator 
    * @param[in] horizontalLine - horizontal line of a separator 
    * @param[in] BLCorner - bottom left corner of a separator 
    * @param[in] BRCorner - bottom right corner of a separator 
    * @param[in] length - length of a separator; negative values will result separator to be printed with a width of a terminal
    *
    * Example: Calling PrintBigSeparator("text", "UL", "UR", "-", "|", "BL", "BR", 20) will print (note the spaces on the left and on the right since they contribute to the length)
    *
      \verbatim
       UL---------------UR 
       |      text       | 
       BL---------------BR 
      \endverbatim
    */
   void PrintMessageBox(const std::string& message, const std::string& ULCorner = "╓", 
                        const std::string& URCorner = "╖", const std::string& horizontalLine = "─", 
                        const std::string& verticalLine = "║", const std::string& BLCorner = "╙", 
                        const std::string& BRCorner = "╜", int length = -1);
}

#endif /* CPP_TOOLS_IOTOOLS_HPP */
