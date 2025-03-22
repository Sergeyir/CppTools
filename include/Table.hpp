/** 
 *  @file   Table.hpp 
 *  @brief  Contains declaration of class Table
 *
 *  In order to use Table class libIOTools.so, libErrorHandler, libTable must be loaded
 *
 *  This file is a part of a project CppTools (https://github.com/Sergeyir/CppTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef CPP_TOOLS_TABLE_HPP
#define CPP_TOOLS_TABLE_HPP

#include "OutputColor.hpp"
#include "IOTools.hpp"
#include "ErrorHandler.hpp"

/// @namespace CppTools
namespace CppTools
{
   /*! @class Table
    * @brief Class Table can be used to print values and text in the table
    *
    * Example:
      @code
      CppTools::Table t(3, 50); // 3 columns, 50 characters in width
      t.Begin("my table"); // name of the table
      t.PrintHeader("name1", "name2", "name3"); // header
      t.PrintRow("r1c1", "r1c2", "r1c3"); // printing 1st row
      t.PrintRow("r2c1", "r2c2", "r2c3");  // printing 2nd row
      t.PrintRow("some value", "another value", "1"); t.End(); // printing 3rd row
      t.End(); // printing the bottom part of the table
      @endcode
      Result:
      \verbatim
       ╔═══════════════════════════════════════════════╗
       ║                   my table                    ║
       ╠════════════════╤═══════════════╤══════════════╣
       ║ name1          │ name2         │ name3        ║
       ╟────────────────┼───────────────┼──────────────╢
       ║ r1c1           │ r1c2          │ r1c3         ║
       ║ r2c1           │ r2c2          │ r2c3         ║
       ║ some value     │ another value │ 1            ║
       ╚════════════════╧═══════════════╧══════════════╝
      \endverbatim
    */
   class Table
   {
      public:

      ///@brief Default constructor
      Table();
      /*! @brief Constructor with parameters
       * @param[in] numberOfColumns number of columns in the table 
       * @param[in] width width of the table (negative value will result for the table to be printed with the width of a terminal). This width includes 2 empty spaces on the very left and right of the table
       */
      Table(const unsigned short nColumns, const int width = -1);
      /*! @brief Prints the top part of the table with it's name
       * @param[in] name name of the table that will be printed 
       */
      void Begin(const std::string& name);
      /*! @brief Prints header of the table
       * @param[in] args parameter pack containing names of columns. Number of parameters passed must not exceed number of columns passed in the constructor
       */
      template<typename... Ts>
      void PrintHeader(Ts... args)
      {
         constexpr unsigned short size = sizeof...(args);
         if (size != numberOfColumns) 
         {
            PrintError("Table: Number of arguments is not equal to the number of columns:" + 
                       std::to_string(size) + " vs " + std::to_string(numberOfColumns));
         }

         std::string dummy[size] = {(std::string) args...};

         //checks whether or not next cell should be printed
         bool check = true;
         //number of the next cell to be printed
         int currentCell = 0;

         //size of the cell
         cellWidth = static_cast<double>(tableWidth - 2*utf8_strlen(verticalBorderTable))/size;

         //finishing the title
         std::cout << " " << rightTableAdjLeftVerticalBorderTable;
         for (int i = 0; i < tableWidth - utf8_strlen(leftTableAdjRightVerticalBorderTable) - 
              utf8_strlen(rightTableAdjLeftVerticalBorderTable) - 1; i++)
         {
            if (i != 0 && i % static_cast<int>(cellWidth) == 0 && 
                tableWidth - i >= cellWidth) 
            {
               std::cout << bottomCellAdjTopHorizontalBorderTable;
            }
            else std::cout << horizontalBorderTable;
         }
         std::cout << leftTableAdjRightVerticalBorderTable << std::endl;

         //printing header
         std::cout << " " << verticalBorderTable;
         for (int i = 0; i < tableWidth - utf8_strlen(leftTableAdjRightVerticalBorderTable) - 
              utf8_strlen(rightTableAdjLeftVerticalBorderTable) - 1; i++)
         {
            if (i != 0 && i % static_cast<int>(cellWidth) == 0 && tableWidth - i >= cellWidth) 
            {
               std::cout << verticalBorderCell;
               check = true;
            }
            else if (check && currentCell < size)
            {
               std::cout << " " << dummy[currentCell];
               i += utf8_strlen(" " + dummy[currentCell]) - 1;
               currentCell++;
               check = false;
            }
            else std::cout << " ";
         }
         std::cout << verticalBorderTable << std::endl;

         //printing header separator
         std::cout << " " << rightCellAdjLeftVerticalBorderTable;
         for (int i = 0; i < tableWidth - utf8_strlen(leftTableAdjRightVerticalBorderTable) - 
              utf8_strlen(rightTableAdjLeftVerticalBorderTable) - 1; i++)
         {
            if (i != 0 && i % static_cast<int>(cellWidth) == 0 && 
                tableWidth - i >= cellWidth) std::cout << cross;
            else std::cout << horizontalCellBorder;
         }
         std::cout << leftCellAdjRightVerticalBorderTable << std::endl;
      }
      /*! @brief Prints cells contents in the last row
       * @param[in] args parameter pack containing values of the cells in the latest row. Number of parameters passed must not exceed number of columns passed in the constructor
       */
      template<typename... Ts>
      void PrintRow(Ts... args)
      {
         constexpr unsigned short size = sizeof...(args);

         if (size != numberOfColumns) 
         {
            PrintError("Number of arguments is not equal to the number of columns:" + 
                       std::to_string(size) + " vs " + std::to_string(numberOfColumns));
         }

         std::string dummy[size] = {(std::string) args...};

         //checks whether or not next cell shoudl be printed
         bool check = true;
         //number of the next cell to be printed
         int currentCell = 0;

         //printing the row
         std::cout << " " << verticalBorderTable;
         for (int i = 0; i < tableWidth - utf8_strlen(leftTableAdjRightVerticalBorderTable) - 
              utf8_strlen(rightTableAdjLeftVerticalBorderTable) - 1; i++)
         {
            if (i != 0 && i % static_cast<int>(cellWidth) == 0 && tableWidth - i >= cellWidth) 
            {
               std::cout << verticalBorderCell;
               check = true;
            }
            else if (check && currentCell < size)
            {
               std::cout << " " << dummy[currentCell];
               i += utf8_strlen(" " + dummy[currentCell]) - 1;
               currentCell++;
               check = false;
            }
            else std::cout << " ";
         }
         std::cout << verticalBorderTable << std::endl;
      }

      /*! @brief Prints the end of the table (bottom line that separates cell contents from other contents in terminal)
       */
      void End();

      /*! @brief Default desctructor 
       */
      virtual ~Table();

      protected:

      /// upper left border corner of the table
      std::string ULBorderCornerTable = "╔";
      /// upper right border corner of the table
      std::string URBorderCornerTable = "╗";
      /// horizontal border of the table
      std::string horizontalBorderTable = "═";
      /// vertical border border of the table
      std::string verticalBorderTable = "║";
      /// vertical separator between cells of the table
      std::string verticalBorderCell = "│";
      /// left vertical border of the table that is adjacent 
      /// to horizontal border of the cell to the right
      std::string rightCellAdjLeftVerticalBorderTable = "╟";
      /// right vertical border of the table that is adjacent 
      /// to horizontal border of the cell to the left
      std::string leftCellAdjRightVerticalBorderTable = "╢";
      /// left vertical border of the table that is adjacent 
      /// to horizontal border of the table to the right
      std::string rightTableAdjLeftVerticalBorderTable = "╠";
      /// right vertical border of the table that is adjacent 
      /// to horizontal border of the tablle to the left
      std::string leftTableAdjRightVerticalBorderTable = "╣";
      /// horizontal border of cells
      std::string horizontalCellBorder = "─";
      /// bottom left border of the table
      std::string BLBorderCornerTable = "╚";
      /// bottom right border of the table
      std::string BRBorderCornerTable = "╝";
      /// top horizontal border of the table that is adjacent 
      /// to vertical border of the cell to the bottom
      std::string bottomCellAdjTopHorizontalBorderTable = "╤";
      /// bottom horizontal border of the table that is adjacent 
      /// to vertical border of the cell to the top
      std::string topCellAdjBottomHorizontalBorderTable = "╧";
      /// cross between cells borders
      std::string cross = "┼";

      /// number of columns in a table
      int numberOfColumns;
      /// lenght of a row, i.e. width of a table
      int tableWidth;
      /// width of one cell
      double cellWidth;
   };
}

#endif /* CPP_TOOLS_TABLE_HPP */
