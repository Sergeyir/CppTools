/** 
 *  @file   InputParser.hpp 
 *  @brief  Contains declaration of class InputParser
 *
 *  This file is a part of a project CppTools (https://github.com/Sergeyir/CppTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef CPP_TOOLS_INPUT_PARSER_HPP
#define CPP_TOOLS_INPUT_PARSER_HPP

#include <string>
#include <vector>

#include "ErrorHandler.hpp"

/// @namespace CppTools
namespace CppTools
{
   /*! @class InputParser
    * @brief Class InputParsercan be used to parse input
    */
   class InputParser
   {
      public:
      ///@brief Default constructor
      InputParser();
      /*! @brief Adds entry to the list of fields 
       * @param[in] entry parser field entry
       */
      void AddField(const std::string& entry);
      /*! @brief Checks if the argument can be associated with any of the added fields
       * @param[in] argument argument to check 
       *
       * Returns the index of the field the argument can be associated with; returns -1 if no fields can be associated with the argument
       */
      int CheckEntry(const std::string& argument);
      {
         if (argument[0] == '-')
         {
            // position of the argument
            int startPos = 1;
            if (argument[1] == '-') startPos++;

            const std::string entry = argument.substr(startPos);
            for (int i = 0; i < static_cast<int>(parserFields.size()); i++)
            {
               if (entry == parserFields[i]) return i;
            }
         }
         return -1;
      }
      ///@brief Default desctuctor
      virtual ~InputParser();

      private:
      /// contains all fields for the current parser
      std::vector<std::string> parserFields;
   }
}
#endif /* CPP_TOOLS_INPUT_PARSER_HPP */
