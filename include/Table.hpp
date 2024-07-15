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

#ifndef TABLE_HPP
#define TABLE_HPP

#include "OutputColor.hpp"
#include "IOTools.hpp"
#include "ErrorHandler.hpp"

template<typename... Ts>
class Table
{
	public:
	
	Table(const int width = -1);
   
	void Begin(std::string name);
	void PrintHeader(Ts... args);
	void PrintRow(Ts... args);
	void End();

   virtual ~Table();

	protected:
	
	std::string ULBorderCorner = "╔";
	std::string URBorderCorner = "╗";
	std::string horizontalBorder = "═";
	std::string verticalBorder = "║";
	std::string verticalSeparator = "│";
	std::string leftAdjVerticalBorder = "╟";
	std::string rightAdjVerticalBorder = "╢";
	std::string rightDoubleAdjVerticalBorder = "╠";
	std::string leftDoubleAdjVerticalBorder = "╣";
	std::string horizontalSeparator = "─";
	std::string DLBorderCorner = "╚";
	std::string DRBorderCorner = "╝";
	std::string downAdjHorizontalBorder = "╤";
	std::string upAdjHorizontalBorder = "╧";
	std::string cross = "┼";
	
	int rowLength;
	double cellSize;
};

#endif
