/** 
 *  @file   IOTools.cpp 
 *  @brief  Contains useful set of functions to work with std::string and to convert various types in std::string
 *  
 *  In order to use functions from this file libStrTools.so must be loaded
 *
 *  This file is a part of a project CppTools (https://github.com/Sergeyir/CppTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef CPP_TOOLS_IOTOOLS_CPP
#define CPP_TOOLS_IOTOOLS_CPP

#include "../include/IOTools.hpp"

int CppTools::GetTerminalWidth()
{
   struct winsize terminalWindow;
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &(terminalWindow));
   return terminalWindow.ws_col;
}

void CppTools::PrintInfo(const std::string& message)
{
   std::cout << INFO_PROMPT << message << std::endl;
}

void CppTools::PrintSimpleSeparator(const std::string& leftEdge, const std::string& body, 
                                    const std::string& rightEdge, int length)
{
   if (length < 0) length = GetTerminalWidth();
   
   std::cout << leftEdge;
   for (int i = 0; i < length - utf8_strlen(leftEdge) - utf8_strlen(rightEdge); i++) 
   {
      std::cout << body;
   }
   std::cout << rightEdge << std::endl;
}

void CppTools::PrintSeparator(const std::string& message, const std::string& color, 
                              const std::string& leftEdge, const std::string& body, 
                              const std::string& rightEdge, int length)
{
   if (length < 0) length = GetTerminalWidth();
   
   std::cout << leftEdge;
   for (int i = 0; i < length/2 - utf8_strlen(message)/2 - utf8_strlen(leftEdge); i++) 
   {
      std::cout << body;
   }
   std::cout << color << message << COLOR_RESET;
   for (int i = 0; i < length - length/2 - utf8_strlen(message) + utf8_strlen(message)/2 - utf8_strlen(rightEdge); i++) 
   {
      std::cout << body;
   }
   std::cout << rightEdge << std::endl;
}

void CppTools::Print2EntrySeparator(const std::string& entry1, const std::string& entry2, 
                                    const std::string& leftEdge, const std::string& rightEdge, 
                                    int length)
{
   if (length < 0) length = GetTerminalWidth();
   
   std::cout << leftEdge << " " << entry1;
   int space_size = length - utf8_strlen(entry1) - utf8_strlen(entry2) - 
                    utf8_strlen(leftEdge) - utf8_strlen(rightEdge) - 2;
   for (int i = 0; i < space_size; i++) std::cout << " ";
   std::cout << entry2 << " " << rightEdge << std::endl;
}

void CppTools::PrintMessageBox(const std::string& message, const std::string& ULCorner, 
                               const std::string& URCorner, const std::string& horizontalLine, 
                               const std::string& verticalLine, const std::string& DLCorner, 
                               const std::string& DRCorner, int length)
{
   PrintSimpleSeparator(" " + ULCorner, horizontalLine, URCorner, length);
   PrintSeparator(message, "", " " + verticalLine, " ", verticalLine, length);
   PrintSimpleSeparator(" " + DLCorner, horizontalLine, DRCorner, length);
}

#endif /* CPP_TOOLS_IOTOOLS_CPP */
