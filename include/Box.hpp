// $HEADER$
//------------------------------------------------------------------------------------------------
//                                   Box class declaration
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

#include "OutputColor.hpp"
#include "ErrorHandler.hpp"
#include "IOTools.hpp"
#include "StrTools.hpp"

class Box
{
   public:

   Box();
   Box(const std::string& boxName);
   void SetName(const std::string& boxName);
   void AddEntry(const std::string& name, const double value, 
                 const unsigned int precision = 2);
   void AddEntry(const std::string& name, const int value);
   void AddEntry(const std::string& name, const short value);
   void AddEntry(const std::string& name, const long value);
   void AddEntry(const std::string& name, const unsigned int value);
   void AddEntry(const std::string& name, const unsigned short value);
   void AddEntry(const std::string& name, const unsigned long value);
   void AddEntry(const std::string& name, const std::string& value);
   void AddEntry(const std::string& name, const bool value);
   void AddEntry(const std::string& name, const std::vector<double>& values,
                 const unsigned int precision = 2);
   void AddEntry(const std::string& name, const std::vector<int>& values);
   void AddEntry(const std::string& name, const std::vector<short>& values);
   void AddEntry(const std::string& name, const std::vector<long>& values);
   void AddEntry(const std::string& name, const std::vector<unsigned int>& values);
   void AddEntry(const std::string& name, const std::vector<unsigned short>& values);
   void AddEntry(const std::string& name, const std::vector<unsigned long>& values);
   void AddEntry(const std::string& name, const std::vector<std::string>& values);
   void AddEntry(const std::string& name, const std::vector<bool>& values);
   void Print(const std::string& titleColor = OutputColor::GREEN);
   void Clear();
   
   virtual ~Box();
   
   protected:
   
   std::string name; 
   std::vector<std::string> entryNames, entryValues;
};

#endif /*BOX_HPP*/
