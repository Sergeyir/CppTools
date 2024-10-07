// $HEADER$
//------------------------------------------------------------------------------------------------
//                                       Useful math functions
//------------------------------------------------------------------------------------------------
// MathTools
//
// ** Free and open code for anyone to use **
//
// Author: Sergei Antsupov
// Email: antsupov0124@gmail.com
//
/**
 * Basic set of variadic functions for simple math calculations
 **/
//------------------------------------------------------------------------------------------------

#ifndef MATH_TOOLS_HPP
#define MATH_TOOLS_HPP

#include <vector>
#include <cmath>

template <typename... Ts> 
double Maximum(Ts... args)
{
   constexpr int size = sizeof...(args);
   double entries[size] = {static_cast<double>(args)...};
   double result = entries[0];
   for (double val : entries) if (val > result) result = val;
   return result;
}

template <typename T> 
T Maximum(std::vector<T> args)
{
   double result = args[0];
   for (double val : args) if (val > result) result = val;
   return result;
}

template <typename... Ts> 
double Minimum(Ts... args)
{
   constexpr int size = sizeof...(args);
   double entries[size] = {static_cast<double>(args)...};
   double result = entries[0];
   for (double val : entries) if (val < result) result = val;
   return result;
}

template <typename T> 
T Minimum(std::vector<T> args)
{
   double result = args[0];
   for (double val : args) if (val < result) result = val;
   return result;
}

template <typename... Ts> 
double Average(Ts... args)
{
   constexpr int size = sizeof...(args);
   double entries[size] = {static_cast<double>(args)...};
   double result = 0.;
   for (double val : entries) result += val;
   return result/static_cast<double>(size);
}

template <typename... Ts> 
double AverageAndStandardError(Ts... args, double &error)
{
   constexpr int size = sizeof...(args);
   double entries[size] = {static_cast<double>(args)...};
   double result = 0.;
   for (double val : entries) result += val;
   for (double val : entries) error += (val - average)*(val - average);
   error /= sqrt(static_cast<double>(size*(size-1)))
   return result/static_cast<double>(size);
}

template <typename... Ts> 
double StandardError(Ts... args)
{
   constexpr int size = sizeof...(args);
   double entries[size] = {static_cast<double>(args)...};
   double result = 0.;
   const double average = Average(args);
   for (double val : entries) result += (val - average)*(val - average);
   return result/sqrt(static_cast<double>(size*(size-1)));
}

template <typename T> 
double Average(std::vector<T> entries)
{
   double result = 0.;

   for (val : entries) result += static_cast<double>(val);
   return result/static_cast<double>(entries.size());
}

template <typename T> 
double StandardError(std::vector<T> entries, const T average)
{
   double result = 0.;
   for (val : entries) result += static_cast<double>((averate - val)*(averate - val));
   return result/sqrt(static_cast<double>(entries.size()*(entries.size() - 1)));
}

//uncertainty propagation
template<typename... Ts>
double ErrPropagation(Ts... args)
{
   constexpr int size = sizeof...(args);
   double entries[size] = {static_cast<double>(args)...};
   double prod = 0;
   for (double var : entries) prod += var*var;
   return sqrt(prod);
}

template<typename T>
double ErrPropagation(std::vector<T> args)
{
   double prod = 0; //product
   for (double var : args) prod += var*var;
   return sqrt(prod);
}

template <typename... Ts> 
double Product(Ts... args)
{
   constexpr int size = sizeof...(args);
   double entries[size] = {static_cast<double>(args)...};
   double result = 1.;
   for (double val : entries) result *= val;
   return result;
}

template <typename T> 
double Product(std::vector<T> args)
{
   double result = 1.;
   for (double val : args) result *= val;
   return result;
}

template <typename... Ts> 
double AtLeast1Prob(Ts... args)
{
   constexpr int size = sizeof...(args);
   double entries[size] = {static_cast<double>(args)...};
   double prod = 1.;
   for (double val : entries) prod *= 1. - val;
   return 1. - prod;
}

#endif /*MATH_TOOLS_HPP*/
