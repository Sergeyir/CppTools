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
T VecMaximum(std::vector<T> args)
{
   T result = args[0];
   for (T val : args) if (val > result) result = val;
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
T VecMinimum(std::vector<T> args)
{
   T result = args[0];
   for (T val : args) if (val < result) result = val;
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
double StandardError(Ts... args)
{
   constexpr int size = sizeof...(args);
   double entries[size] = {static_cast<double>(args)...};
   double result = 0.;
   for (int i = 1; i < size; i++)
   {
      result += (entries[i] - entries[0])*(entries[i] - entries[0]);
   }
   return result/sqrt(static_cast<double>(size*(size-1)));
}

template <typename T> 
double VecAverage(std::vector<T> entries)
{
   double result = 0.;
   for (T val : entries) result += static_cast<double>(val);
   return result/static_cast<double>(entries.size());
}

template <typename T> 
double VecStandardError(std::vector<T> entries, const double average)
{
   double result = 0.;
   for (T val : entries) result += 
      (average - static_cast<double>(val))*(average - static_cast<double>(val));
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
double VecErrPropagation(std::vector<T> args)
{
   double prod = 0; //product
   for (T var : args) prod += static_cast<double>(var)*static_cast<double>(var);
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
double VecProduct(std::vector<T> args)
{
   double result = 1.;
   for (T val : args) result *= static_cast<double>(val);
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

template<typename... Ts>
double RMS(Ts... args)
{
	constexpr int size = sizeof...(args);
	double entries[size] = {static_cast<double>(args)...};
	double rms = 0;
	for (double var : entries) rms += var*var;
	return sqrt(rms/static_cast<double>(size));
}

double RMSv(std::vector<double> vec)
{
	double rms = 0.;
	for (double var : vec) rms += var*var;
	return sqrt(rms/static_cast<double>(vec.size()));
}

#endif /*MATH_TOOLS_HPP*/
