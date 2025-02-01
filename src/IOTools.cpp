/** 
 *  @file   IOTools.cpp 
 *  @brief  Useful set of functions to work with input and output of the terminal
 *  
 *  In order to use these functions libErrorHandler.so, libStrTools.so, libIOTools.so must be loaded
 *
 *  @author Sergei Antsupov
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
   std::cout << CppTools::OutputSnippet::INFO << message << std::endl;
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

#endif /*CPP_TOOLS_IOTOOLS_CPP*/
