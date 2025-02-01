/** 
 *  @file   Time.hpp 
 *  @brief  Useful set of functions to print current time, time duration 
 *  
 *  In order to use these functions libErrorHandler.so must be loaded
 *
 *  @author Sergei Antsupov
 **/

#ifndef CPP_TOOLS_TIME_HPP
#define CPP_TOOLS_TIME_HPP

#include <ctime>
#include <chrono>
#include <iostream>

typedef std::chrono::_V2::system_clock::time_point chrono_t;

/// @namespace CppTools CppTools namespace
namespace CppTools
{
   /*! @brief Returns current time as std::chrono::_V2::system_clock::time_point (or chrono_t)
    * @param[out] currentTime chrono_t variable
    */
   chrono_t GetCurrentTime();
   ///@brief Prints current time in format: Week Month Hour:Minute:Second Year
   void PrintCurrentTime();
   /*! @brief Prints the time duration converted from 2 chrono_t variables. 
    * These chrono_t variables can be acquired with the use of chrono_t CppTools::GetCurrentTime function. If the both variables were acquired as a current time measurement in 2 different points in time then the returned duration is the time duration between these 2 different points in time.
    * @param[in] start first chrono_t variable 
    * @param[in] stop second chrono_t variable 
    */
   void PrintTimeDuration(const std::chrono::_V2::system_clock::time_point start, 
                          const std::chrono::_V2::system_clock::time_point stop);
}

#endif /*CPP_TOOLS_TIME_HPP*/
