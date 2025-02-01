/** 
 *  @file   Table.cpp 
 *  @brief  Contains realisation of class Table
 *
 *  In order to use Table class libIOTools.so, libErrorHandler, libTable must be loaded
 *
 *  This file is a part of a project CppTools (https://github.com/Sergeyir/CppTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef CPP_TOOLS_TABLE_CPP
#define CPP_TOOLS_TABLE_CPP

#include "../include/Table.hpp"


CppTools::Table::Table() 
{
   numberOfColumns = 1;
   tableWidth = GetTerminalWidth();
}

CppTools::Table::Table(const unsigned short nColumns, const int width) 
{
   numberOfColumns = nColumns;
   if (width > 0) tableWidth = width;
   else tableWidth = GetTerminalWidth();
};

void CppTools::Table::Begin(const std::string& name)
{
   PrintSimpleSeparator(" " + ULBorderCornerTable, horizontalBorderTable, URBorderCornerTable, tableWidth);
   PrintSeparator(name, COLOR_GREEN, " " + verticalBorderTable, " ", verticalBorderTable, tableWidth);
}

void CppTools::Table::End()
{
   std::cout << " " << BLBorderCornerTable;
   for (int i = 0; i < tableWidth - utf8_strlen(rightTableAdjLeftVerticalBorderTable) - 
        utf8_strlen(leftTableAdjRightVerticalBorderTable) - 1; i++)
   {
      if (i != 0 && i % static_cast<int>(cellWidth) == 0 && 
          tableWidth - i >= cellWidth) std::cout << topCellAdjBottomHorizontalBorderTable;
      else std::cout << horizontalBorderTable;
   }
   std::cout << BRBorderCornerTable << std::endl;
}

CppTools::Table::~Table() {};

#endif /* CPP_TOOLS_TABLE_CPP */
