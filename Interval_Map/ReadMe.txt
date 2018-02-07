#Interval Map
This code populates an interval map data structure that stores values of type V mapped to key intervals
[keyLower, keyUpper) of type K.

#-------------------------------------------------------------------------------------------------------
Please, set the alias for key and value data types in "main.cpp" before compiling the code.
Supported types categories: floating point, integer and character (only char).

Example:
typedef unsigned short imkey_t;
typedef char imvalue_t;

Please, set the desired data types also in "interval_map.cpp" before compiling the code.

Example:
template class Interval_Map <unsigned short, char>;

#-------------------------------------------------------------------------------------------------------
Please, decrease the upper numeric limit in

const T populateIntervalMap(gen_t& gen);

used to generate keys or values to populate the interval map
numeric limit set to std::numeric_limits<T>::max(), if needed.

#-------------------------------------------------------------------------------------------------------
#To compile
make

#To run
./im
