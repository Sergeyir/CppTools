// $HEADER$
//------------------------------------------------------------------------------------------------
//                                  Box class declaration
//------------------------------------------------------------------------------------------------
// Box
//
// ** Free and open code for anyone to use **
//
// Author: Sergei Antsupov
// Email: antsupov0124@gmail.com
//
/**
 * Basic tool for putting text output in an ascii box
 **/
//------------------------------------------------------------------------------------------------

#ifndef BOX_HPP
#define BOX_HPP

#include "ErrorHandler.h"
#include "OutputTool.h"
#include "StrTool.h"

class Box
{
	private:
	std::string name; 
	std::vector<std::string> Vname, Ventry;

	long unsigned int width;

	void CheckEntry()
	{
		if (Vname.back().length() + Ventry.back().length() > width - 2)
		{
			PrintWarning("Box entry " + Vname.back() + " is too long: it will not be printed");
			Vname.pop_back();
			Ventry.pop_back();
		}
	}

	public :

	Box(const int length = 80) {width = length;};
	
	Box(std::string box_name, const long unsigned length = 80)
	{
		name = box_name;
		width = length;
	}

	~Box()
	{
		Vname.clear();
		Ventry.clear();
	}

	void SetName(std::string box_name)
	{
		name = box_name;
	}
	
	void AddEntry(std::string name, const double val, unsigned const int precision = 2)
	{
		Vname.push_back(name);
		Ventry.push_back(DtoStr(val, precision));
		CheckEntry();
	}

	void AddEntry(std::string name, const int val)
	{
		Vname.push_back(name);
		Ventry.push_back(std::to_string(val));
		CheckEntry();
	}

	void AddEntry(std::string name, std::string entry)
	{
		Vname.push_back(name);
		Ventry.push_back(entry);
		CheckEntry();
	}

	void AddEntry(std::string name, bool val)
	{
		Vname.push_back(name);
		Ventry.push_back(BtoStr(val));
		CheckEntry();
	}

	void Print(std::string color = "\033[32m")
	{
		if (Vname.size() == 0) 
		{
			PrintWarning("Box cannot be printed: number of entries is 0");
			return;
		}
		
		PrintSimpleSeparator(" ╔", "═", "╗", width);
		PrintSeparator(name, color, " ║", " ", "║", width);
		PrintSimpleSeparator(" ╟", "─", "╢", width);
		
		for (long unsigned int i = 0; i < Vname.size(); i++)
		{
			PrintEdgedLine(Vname[i], Ventry[i], " ║", "║", width);
		}
		
		PrintSimpleSeparator(" ╚", "═", "╝", width);

		Vname.clear();
		Ventry.clear();
	}
};

#endif
