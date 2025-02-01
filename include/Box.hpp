/** 
 *  @file   Box.hpp 
 *  @brief  Contains declaration of class Box
 *
 *  In order to use Box class libraries libErrorHandler.so, libIOTools.so, libStrTools.so, libBox.so must be loaded
 *
 *  This file is a part of a project CppTools (https://github.com/Sergeyir/CppTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef CPP_TOOLS_BOX_HPP
#define CPP_TOOLS_BOX_HPP

#include "OutputColor.hpp"
#include "ErrorHandler.hpp"
#include "IOTools.hpp"
#include "StrTools.hpp"

/// @namespace CppTools CppTools namespace
namespace CppTools
{
   /*! @class Box
    * @brief Class Box can be used used to print values and their name in the box
    *
    * Example:
      @code
      CppTools::Box box("text", 20);
      box.AddEntry("value1", 1);
      box.AddEntry("value2", true);
      box.AddEntry("value3", 0.4, 2);
      box.AddEntry("value4", "some text");
      box.Print()
      @endcode
      Result:
      \verbatim
       ╔════════════════╗
       ║      text      ║
       ╟────────────────╢
       ║ value1       1 ║
       ║ value2    true ║
       ║ value3    0.40 ║
       ║ value4    true ║
       ╚════════════════╝
      \endverbatim
    *  In order to use Box class libErrorHandler.so, libIOTools.so, libStrTools.so, libBox.so must be loaded
    */
   class Box
   {
      public:

      ///@brief Default constructor
      Box();
      /*! @brief Constructor with parameters
       * @param[in] boxName text to be printed in the head of the box
       * @param[in] width width of the box (negative value will result for the box to be printed with the width of a terminal)
       */
      Box(const std::string& boxName, const int width = -1);
      /*! @brief Set box name
       * @param[in] boxName text to be printed in the head of the box
       */
      void SetName(const std::string& boxName);
      /*! @brief Set box width
       * @param[in] width width of the box (negative value will result in a box to be printed with the width of a terminal)
       */
      void SetWidth(const int width);
      /*! @brief Add double-precision floating type value to the box with the set precision
       * @param[in] name value's name
       * @param[in] value 
       * @param[in] precision floating point precision
       */
      void AddEntry(const std::string& name, const double value, 
                    const unsigned int precision = 2);
      /*! @brief Add int type value to the box
       * @param[in] name value's name
       * @param[in] value 
       */
      void AddEntry(const std::string& name, const int value);
      /*! @brief Add short type value to the box
       * @param[in] name value's name
       * @param[in] value 
       */
      void AddEntry(const std::string& name, const short value);
      /*! @brief Add long type value to the box
       * @param[in] name value's name
       * @param[in] value 
       */
      void AddEntry(const std::string& name, const long value);
      /*! @brief Add unsigned int type value to the box
       * @param[in] name value's name
       * @param[in] value 
       */
      void AddEntry(const std::string& name, const unsigned int value);
      /*! @brief Add unsigned short type value to the box
       * @param[in] name value's name
       * @param[in] value 
       */
      void AddEntry(const std::string& name, const unsigned short value);
      /*! @brief Add unsigned long type value to the box
       * @param[in] name value's name
       * @param[in] value 
       */
      void AddEntry(const std::string& name, const unsigned long value);
      /*! @brief Add std::string type value to the box
       * @param[in] name value's name
       * @param[in] value 
       */
      void AddEntry(const std::string& name, const std::string& value);
      /*! @brief Add bool type value to the box
       * @param[in] name value's name
       * @param[in] value it will converted into std::string and printed as either "true" or "false"
       */
      void AddEntry(const std::string& name, const bool value);
      /*! @brief Add double-precision floating type values to the box with the set precision
       * @param[in] name values names
       * @param[in] values
       * @param[in] precision floating point precision
       */
      void AddEntry(const std::string& name, const std::vector<double>& values,
                    const unsigned int precision = 2);
      /*! @brief Add int type values to the box
       * @param[in] name values names
       * @param[in] values
       */
      void AddEntry(const std::string& name, const std::vector<int>& values);
      /*! @brief Add short type values to the box
       * @param[in] name values names
       * @param[in] values
       */
      void AddEntry(const std::string& name, const std::vector<short>& values);
      /*! @brief Add long type values to the box
       * @param[in] name values names
       * @param[in] values
       */
      void AddEntry(const std::string& name, const std::vector<long>& values);
      /*! @brief Add unsigned int type values to the box
       * @param[in] name values names
       * @param[in] values
       */
      void AddEntry(const std::string& name, const std::vector<unsigned int>& values);
      /*! @brief Add unsigned short type values to the box
       * @param[in] name values names
       * @param[in] values
       */
      void AddEntry(const std::string& name, const std::vector<unsigned short>& values);
      /*! @brief Add unsigned long type values to the box
       * @param[in] name values names
       * @param[in] values
       */
      void AddEntry(const std::string& name, const std::vector<unsigned long>& values);
      /*! @brief Add std::string type values to the box
       * @param[in] name values names
       * @param[in] values
       */
      void AddEntry(const std::string& name, const std::vector<std::string>& values);
      /*! @brief Add bool type values to the box
       * @param[in] name values names
       * @param[in] value each value will converted into std::string and printed as either "true" or "false"
       */
      void AddEntry(const std::string& name, const std::vector<bool>& values);
      /*! @brief Print the box
       * @param[in] titleColor color of the text in the head of the box
       */
      void Print(const std::string& titleColor = COLOR_GREEN);
      /*! @brief Remove box entries
       */
      void Clear();
      
      /*! @brief Descructor
       */
      virtual ~Box();
      
      protected:
      
      /// width of the box
      int boxWidth = -1;
      /// text in the head of the box
      std::string name; 
      /// containers with values and their names
      std::vector<std::string> entryNames, entryValues;
   };
}
#endif /* CPP_TOOLS_BOX_HPP */
