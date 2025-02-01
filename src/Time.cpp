/** 
 *  @file   Time.cpp 
 *  @brief  Contains useful set of functions to print current time, time duration 
 *  
 *  In order to use these functions libTime.so must be loaded
 *
 *  This file is a part of a project CppTools (https://github.com/Sergeyir/CppTools).
 *
 *  @author Sergei Antsupov (antsupov0124@gmail.com)
 **/
#ifndef CPP_TOOLS_TIME_CPP
#define CPP_TOOLS_TIME_CPP

#include "../include/Time.hpp"

chrono_t CppTools::GetCurrentTime()
{
   return std::chrono::high_resolution_clock::now();
}

void CppTools::PrintCurrentTime()
{
   const std::time_t currentTime = std::time(nullptr);
   std::cout << std::asctime(std::localtime(&currentTime));
}

void CppTools::PrintTimeDuration(const std::chrono::_V2::system_clock::time_point start, 
                                 const std::chrono::_V2::system_clock::time_point stop)
{
   const unsigned int duration = (unsigned int) 
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
   
   std::cout << duration/3600000000000 << "h " << 
                (duration % 3600000000)/60000000000 << "m " << 
                (duration % 60000000)/1000000 << "s " << 
                (duration % 1000000)/1000 << "ms " << 
                duration % 1000 << "μs" << std::endl;
}

#endif /* CPP_TOOLS_TIME_CPP */
