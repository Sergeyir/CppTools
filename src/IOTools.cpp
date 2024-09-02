// $SOURCE$
//------------------------------------------------------------------------------------------------
//                               IOTools functions declarations
//------------------------------------------------------------------------------------------------
// IOTools: input-output tools
//
// ** Free and open code for anyone to use **
//
// Author: Sergei Antsupov
// Email: antsupov0124@gmail.com
//
/**
 * Basic set of functions for handling input and output in the terminal
 **/
//------------------------------------------------------------------------------------------------

#ifndef IOTOOLS_CPP
#define IOTOOLS_CPP

#include "../include/IOTools.hpp"

int GetTerminalWidth()
{
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &(IOTools::terminalWindow));
   return IOTools::terminalWindow.ws_col;
}

double *ReadFileIntoArray(std::string fileName, const int size)
{
   CheckInputFile(fileName);
   double *buff = new double[size];
   std::ifstream file(fileName);
   
   for (int i = 0; i < size; i++) {file >> buff[i];};
   return buff;
}

void PrintInfo(std::string message)
{
   std::cout << OutputColor::GREEN << " INFO: " << OutputColor::RESET << message << std::endl;
}

void PrintSimpleSeparator(std::string leftEdge, std::string body, 
                          std::string rightEdge, int length)
{
   if (length < 0) length = GetTerminalWidth();
   
   std::cout << leftEdge;
   for (int i = 0; i < length - utf8_strlen(leftEdge) - utf8_strlen(rightEdge); i++) 
   {
      std::cout << body;
   }
   std::cout << rightEdge << std::endl;
}

void PrintSeparator(std::string text, std::string color, 
                    std::string leftEdge, std::string body, 
                    std::string rightEdge, int length)
{
   if (length < 0) length = GetTerminalWidth();
   
   std::cout << leftEdge;
   for (int i = 0; i < length/2 - utf8_strlen(text)/2 - utf8_strlen(leftEdge); i++) 
   {
      std::cout << body;
   }
   std::cout << color << text << OutputColor::RESET;
   for (int i = 0; i < length - length/2 - utf8_strlen(text) + utf8_strlen(text)/2 - utf8_strlen(rightEdge); i++) 
   {
      std::cout << body;
   }
   std::cout << rightEdge << std::endl;
}

void PrintEdgedLine(std::string entry1, std::string entry2, std::string leftEdge, 
                    std::string rightEdge, int length)
{
   if (length < 0) length = GetTerminalWidth();
   
   std::cout << leftEdge << " " << entry1;
   int space_size = length - utf8_strlen(entry1) - utf8_strlen(entry2) - 
                    utf8_strlen(leftEdge) - utf8_strlen(rightEdge) - 2;
   for (int i = 0; i < space_size; i++) std::cout << " ";
   std::cout << entry2 << " " << rightEdge << std::endl;
}

void PrintBigSeparator(std::string text, std::string ULCorner, std::string URCorner,
   std::string horizontalLine, std::string verticalLine,
   std::string DLCorner, std::string DRCorner)
{
   PrintSimpleSeparator(" " + ULCorner, horizontalLine, URCorner);
   PrintSeparator(text, "", " " + verticalLine, " ", verticalLine);
   PrintSimpleSeparator(" " + DLCorner, horizontalLine, DRCorner);
}

#endif
