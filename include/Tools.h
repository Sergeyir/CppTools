#pragma once

template <typename... Ts> 
double Maximum(Ts... args)
{
	constexpr int size = sizeof...(args);
	double entries[size] = {static_cast<double>(args)...};
	double result = entries[0];
	for (double val : entries) if (val > result) result = val;
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

template <typename... Ts> 
double Average(Ts... args)
{
	constexpr int size = sizeof...(args);
	double entries[size] = {static_cast<double>(args)...};
	double result = 0.;
	for (double val : entries) result += val/static_cast<double>(size);
	return result;
}

//uncertainty propagation
template<typename... Ts>
double ErrPropagation(Ts... args)
{
	constexpr int size = sizeof...(args);
	double entries[size] = {static_cast<double>(args)...};
	double prop = 0;
	for (double var : entries) prop += var*var;
	return sqrt(prop);
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

template <typename... Ts> 
double AtLeast1Prob(Ts... args)
{
	constexpr int size = sizeof...(args);
	double entries[size] = {static_cast<double>(args)...};
	double prod = 1.;
	for (double val : entries) prod *= 1. - val;
	return 1. - prod;
}
