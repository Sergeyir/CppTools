// $HEADER$
//------------------------------------------------------------------------------------------------
//                                   Table class declaration
//------------------------------------------------------------------------------------------------
// Table
//
// ** Free and open code for anyone to use **
//
// Author: Sergei Antsupov
// Email: antsupov0124@gmail.com
//
/**
 * Basic tool for putting text output in an ascii table
 **/
//------------------------------------------------------------------------------------------------

#ifndef TABLE_CPP
#define TABLE_CPP

#include "../include/Table.hpp"

Table::Table(const int width) 
{
   if (width > 0) rowLength = width;
   else rowLength = GetTerminalWidth();
};

void Table::Begin(std::string name)
{
   PrintSimpleSeparator(" " + ULBorderCorner, horizontalBorder, URBorderCorner);
   PrintSeparator(name, OutputColor::green, " " + verticalBorder, " ", verticalBorder);
}

void Table::PrintHeader(Ts... args)
{
   constexpr int size = sizeof...(args);

   std::string dummy[size] = {(std::string) args...};
   
   //checks whether or not next cell should be printed
   bool check = true;
   //number of the next cell to be printed
   int ncell = 0;

   //size of the cell
   cellSize = static_cast<double>(rowLength - 2*utf8_strlen(verticalBorder))/size;

   //finishing the title
   std::cout << " " << rightDoubleAdjVerticalBorder;
   for (int i = 0; i < rowLength - utf8_strlen(rightDoubleAdjVerticalBorder) - 
        utf8_strlen(leftDoubleAdjVerticalBorder) - 1; i++)
   {
      if (i != 0 && i % static_cast<int>(cellSize) == 0 && 
          rowLength - i >= cellSize) 
      {
         std::cout << downAdjHorizontalBorder;
      }
      else std::cout << horizontalBorder;
   }
   std::cout << leftDoubleAdjVerticalBorder << std::endl;

   //printing header
   std::cout << " " << verticalBorder;
   for (int i = 0; i < rowLength - utf8_strlen(rightDoubleAdjVerticalBorder) - 
        utf8_strlen(leftDoubleAdjVerticalBorder) - 1; i++)
   {
      if (i != 0 && i % static_cast<int>(cellSize) == 0 && rowLength - i >= cellSize) 
      {
         std::cout << verticalSeparator;
         check = true;
      }
      else if (check && ncell < size)
      {
         std::cout << " " << dummy[ncell];
         i += utf8_strlen(" " + dummy[ncell]) - 1;
         ncell++;
         check = false;
      }
      else std::cout << " ";
   }
   std::cout << verticalBorder << std::endl;

   //printing header separator
   std::cout << " " << leftAdjVerticalBorder;
   for (int i = 0; i < rowLength - utf8_strlen(rightDoubleAdjVerticalBorder) - 
        utf8_strlen(leftDoubleAdjVerticalBorder) - 1; i++)
   {
      if (i != 0 && i % static_cast<int>(cellSize) == 0 && 
          rowLength - i >= cellSize) std::cout << cross;
      else std::cout << horizontalSeparator;
   }
   std::cout << rightAdjVerticalBorder << std::endl;
}

void Table::PrintRow(Ts... args)
{
   constexpr int size = sizeof...(args);

   std::string dummy[size] = {(std::string) args...};
   
   //checks whether or not next cell shoudl be printed
   bool check = true;
   //number of the next cell to be printed
   int ncell = 0;

   //printing the row
   std::cout << " " << verticalBorder;
   for (int i = 0; i < rowLength - utf8_strlen(rightDoubleAdjVerticalBorder) - 
        utf8_strlen(leftDoubleAdjVerticalBorder) - 1; i++)
   {
      if (i != 0 && i % static_cast<int>(cellSize) == 0 && rowLength - i >= cellSize) 
      {
         std::cout << verticalSeparator;
         check = true;
      }
      else if (check && ncell < size)
      {
         std::cout << " " << dummy[ncell];
         i += utf8_strlen(" " + dummy[ncell]) - 1;
         ncell++;
         check = false;
      }
      else std::cout << " ";
   }
   std::cout << verticalBorder << std::endl;
}

void Table::End()
{
   std::cout << " " << DLBorderCorner;
   for (int i = 0; i < rowLength - utf8_strlen(rightDoubleAdjVerticalBorder) - utf8_strlen(leftDoubleAdjVerticalBorder) - 1; i++)
   {
      if (i != 0 && i % static_cast<int>(cellSize) == 0 && 
          rowLength - i >= cellSize) std::cout << upAdjHorizontalBorder;
      else std::cout << horizontalBorder;
   }
   std::cout << DRBorderCorner << std::endl;
}

Box::~Box() {};

#endif
