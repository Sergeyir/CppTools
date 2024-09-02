// $HEADER$
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

#ifndef IOTOOLS_HPP
#define IOTOOLS_HPP

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <vector>

#include "ErrorHandler.hpp"
#include "StrTools.hpp"

template <typename... T>
void ReadFile(std::string file_name, T&... args)
{
   CheckInputFile(file_name);
   std::ifstream file(file_name);
   
   ((file >> args), ...);
}

template <typename... T>
void Print(T... args)
{
   ((std::cout << args << " "), ...);
   std::cout << std::endl;
}

int GetTerminalWidth();
double *ReadFileIntoArray(std::string fileName, const int size);
void PrintInfo(std::string message);
void PrintSimpleSeparator(std::string leftEdge = "|", std::string body = "-", 
                          std::string rightEdge = "|", int length = -1);
void PrintSeparator(std::string text, std::string color = "", 
                    std::string leftEdge = "//",  std::string body = "-", 
                    std::string rightEdge = "//", int length = -1);
void PrintEdgedLine(std::string entry1, std::string entry2, std::string leftEdge = "|",
                    std::string rightEdge = "|", int length = -1);
void PrintBigSeparator(std::string text, std::string ULCorner = "╓", std::string URCorner = "╖",
                       std::string horizontalLine = "─", std::string verticalLine = "║",
                       std::string DLCorner = "╙", std::string DRCorner = "╜");

#endif
