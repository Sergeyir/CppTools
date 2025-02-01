/** 
 *  @file   MathTools.hpp 
 *  @brief  Useful set of math functions.
 *
 *  @author Sergei Antsupov
 **/
#ifndef CPP_TOOLS_MATH_TOOLS_HPP
#define CPP_TOOLS_MATH_TOOLS_HPP

#include <vector>
#include <cmath>

/// @namespace CppTools CppTools namespace
namespace CppTools
{
   /*! @brief Returns maximum value from C array
    *
    * Can be used with std::vector or std::array as such: MaximumFromCArray(&some_vector[0], some_vector.size())
    *
    * @param[in] entries C array
    * @param[in] n Size of C array
    * @param[out] result Maximum value
    */
   template <typename T> 
   T MaximumFromCArray(const T *entries, const unsigned long n)
   {
      T result = entries[0];
      for (unsigned long i = 1; i < n; i++)
      {
         if (entries[i] > result) result = entries[i];
      }
      return result;
   }

   /*! @brief Returns maximum value from parameter pack
    *
    * @param[in] args Parameter pack
    * @param[out] result Maximum value
    */
   template <typename... Ts> 
   double Maximum(Ts... args)
   {
      constexpr unsigned long size = sizeof...(args);
      double entries[size] = {static_cast<double>(args)...};
      return MaximumFromCArray(entries, size);
   }

   /*! @brief Returns minimum value from C array
    *
    * Can be used with std::vector or std::array as such: MinimumArray(&some_vector[0], some_vector.size())
    *
    * @param[in] entries C array
    * @param[in] n Size of C array
    * @param[out] result Minimum value
    */
   template <typename T> 
   T MinimumFromCArray(const T *entries, const unsigned long n)
   {
      T result = entries[0];
      for (unsigned long i = 1; i < n; i++)
      {
         if (entries[i] < result) result = entries[i];
      }
      return result;
   }

   /*! @brief Returns minimum value from parameter pack.
    *
    * @param[in] args Parameter pack
    * @param[out] result Minimum value
    */
   template <typename... Ts> 
   double Minimum(Ts... args)
   {
      constexpr unsigned long size = sizeof...(args);
      double entries[size] = {static_cast<double>(args)...};
      return MinimumFromCArray(entries, size);
   }

   /*! @brief Returns average value from C array
    *
    * Can be used with std::vector or std::array as such: AverageFromCArray(&some_vector[0], some_vector.size())
    *
    * @param[in] entries C array
    * @param[in] n Size of C array
    * @param[out] result Average value
    */
   template <typename T> 
   T AverageFromCArray(const T *entries, const unsigned long n)
   {
      T result = 0;
      for (unsigned long i = 0; i < n; i++)
      {
         result += entries[i];
      }
      return result/static_cast<T>(n);
   }

   /*! @brief Returns average value from parameter pack.
    *
    * @param[in] args Parameter pack
    * @param[out] result Average value
    */
   template <typename... Ts> 
   double Average(Ts... args)
   {
      constexpr unsigned long size = sizeof...(args);
      double entries[size] = {static_cast<double>(args)...};
      return AverageFromCArray(entries, size);
   }

   /*! @brief Returns standard error value from C array
    *
    * Can be used with std::vector or std::array as such: StandardErrorFromCArray(&some_vector[0], some_vector.size())
    *
    * @param[in] entries C array
    * @param[in] n Size of C array
    * @param[out] result Standard error value
    */
   template <typename T> 
   double StandardErrorFromCArray(const T *entries, const unsigned long n, const double average)
   {
      T result = 0;
      for (unsigned long i = 0; i < n; i++)
      {
         result += (average - static_cast<double>(entries[i]))*
                   (average - static_cast<double>(entries[i]));
      }
      return result/sqrt(static_cast<double>(n*(n - 1)));
   }

   /*! @brief Returns average value from parameter pack.
    *
    * @param[in] args Parameter pack
    * @param[in] average Average value from the parameter pack
    * @param[out] result Standard error value
    */
   template <typename... Ts> 
   double StandardError(Ts... args, const double average)
   {
      constexpr unsigned long size = sizeof...(args);
      double entries[size] = {static_cast<double>(args)...};
      return StandardErrorFromCArray(entries, size, average);
   }

   /*! @brief Returns uncertainty that is the propagated uncertainty from all uncertainties from C array
    *
    * Uncertainties are relative. Can be used with std::vector or std::array as such: StandardErrorFromCArray(&some_vector[0], some_vector.size())
    *
    * @param[in] entries C array (contains uncertainties)
    * @param[in] n Size of C array
    * @param[out] result Propagated uncertainty
    */
   template <typename T> 
   double UncertaintyPropFromCArray(const T *entries, const unsigned long n)
   {
      double result = 0;
      for (unsigned long i = 0; i < n; i++)
      {
         result += static_cast<double>(entries[i]*entries[i]);
      }
      return sqrt(result);
   }

   /*! @brief Returns uncertainty that is the propagated uncertainty from all uncertainties from parameter pack
    *
    * Uncertainties are relative.
    *
    * @param[in] args Parameter pack
    * @param[out] result Propagated uncertainty
    */
   template<typename... Ts>
   double UncertaintyProp(Ts... args)
   {
      constexpr unsigned long size = sizeof...(args);
      double entries[size] = {static_cast<double>(args)...};
      return UncertaintyPropFromCArray(entries, size);
   }

   /*! @brief Returns product of values from C array
    *
    * Can be used with std::vector or std::array as such: ProductFromCArray(&some_vector[0], some_vector.size())
    *
    * @param[in] entries C array
    * @param[in] n Size of C array
    * @param[out] result Product
    */
   template <typename T> 
   T ProductFromCArray(const T *entries, const unsigned long n)
   {
      T result = entries[0];
      for (unsigned long i = 1; i < n; i++)
      {
         result *= entries[i];
      }
      return result;
   }

   /*! @brief Returns product of values from parameter pack.
    *
    * @param[in] args Parameter pack
    * @param[out] result Product
    */
   template <typename... Ts> 
   double Product(Ts... args)
   {
      constexpr unsigned long size = sizeof...(args);
      double entries[size] = {static_cast<double>(args)...};
      return ProductFromCArray(entries, size);
   }

   /*! @brief Returns probability of at least 1 success from probabilities of different independent successes from C array
    *
    * Can be used with std::vector or std::array as such: AtLeast1ProbFromCArray(&some_vector[0], some_vector.size())
    *
    * @param[in] entries C array
    * @param[in] n Size of C array
    * @param[out] result Probability
    */
   template <typename T> 
   double AtLeast1ProbFromCArray(const T *entries, const unsigned long n)
   {
      double prod = 1.;
      for (unsigned long i = 0; i < n; i++)
      {
         prod *= 1. - static_cast<double>(entries[i]);
      }
      return 1. - prod;
   }

   /*! @brief Returns probability of at least 1 success from probabilities of different independent successes from parameter pack
    *
    * @param[in] args Parameter pack
    * @param[out] result Probability
    */
   template <typename... Ts> 
   double AtLeast1Prob(Ts... args)
   {
      constexpr unsigned long size = sizeof...(args);
      double entries[size] = {static_cast<double>(args)...};
      return AtLeast1ProbFromCArray(entries, size);
   }

   /*! @brief Returns root mean square (RMS) of values from C array
    *
    * Can be used with std::vector or std::array as such: RMSFromCarray(&some_vector[0], some_vector.size())
    *
    * @param[in] entries C array
    * @param[in] n Size of C array
    * @param[out] result RMS
    */
   template <typename T> 
   double RMSFromCArray(const T *entries, const unsigned long n)
   {
      double result = 0.;
      for (unsigned long i = 0; i < n; i++)
      {
         result += static_cast<double>(entries[i]*entries[i]);
      }
      return sqrt(result/static_cast<double>(n));
   }

   /*! @brief Returns root mean square (RMS) of values from parameter pack
    *
    * @param[in] args Parameter pack
    * @param[out] result RMS
    */
   template<typename... Ts>
   double RMS(Ts... args)
   {
      constexpr unsigned long size = sizeof...(args);
      double entries[size] = {static_cast<double>(args)...};
      return RMSFromCArray(entries, size);
   }
}

#endif /*CPP_TOOLS_MATH_TOOLS_HPP*/
