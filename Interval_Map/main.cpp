#include <iostream>
#include <random>
#include <limits>
#include <map>
#include "interval_map.h"

/*This code populates an interval map data structure that stores values of type V mapped to key 
intervals [keyLower, keyUpper) of type K.*/

//----------------------------------------------------------------------------------------------
//Alias for data types
typedef std::mt19937 gen_t;
typedef unsigned short imkey_t;
typedef char imvalue_t;

//----------------------------------------------------------------------------------------------
//Prototypes 
//Get lower value to initialize Interval_Map constructor
template <class T>
const T getLowerValue();
//Function template specialization for type unsigned char
template <>
const char getLowerValue();

//Generate key or value to populate Interval Map
template <class T>
const T populateIntervalMap(gen_t& gen); 

//Function template specialization for type unsigned char
template <>
const char populateIntervalMap<char>(gen_t& gen);

//----------------------------------------------------------------------------------------------
//main
int main() 
{
    //Create an instance of class "Interval_Map" with template types
    Interval_Map <imkey_t, imvalue_t> imap(getLowerValue<imkey_t>(), getLowerValue<imvalue_t>());

    //Number of Key-Value pairs to generate
    int num = 16;

    //Seed for the random number engine
    std::random_device rd; 
    //Mersenne Twister engine seeded with rd
    gen_t gen(rd());

    //To have a canonical form, subsequent Key-Value pairs must have different values
    imvalue_t old_value = getLowerValue<imvalue_t>();

    //Populate imap
    for ( int i = 0; i < num; i++ ) 
    {
        //Generate a lower key
        imkey_t keyLower = populateIntervalMap<imkey_t>(gen); 
        //Generate an upper key 
        imkey_t keyUpper = populateIntervalMap<imkey_t>(gen); 
        //Generate a corresponding value
        imvalue_t value =  populateIntervalMap<imvalue_t>(gen);
        //Validity checks: 
        //keyLower (lower limit) is less than keyUpper (upper limit) -> to define an interval
        //old_value must have different than value -> to have a canonical form
        if ( ( keyLower < keyUpper ) && ( value != old_value ) ) 
        {
            //Insert Key-Value pairs into imap
            imap.insertInterval(keyLower, keyUpper, value);
            old_value = value;
        }
    }  

    std::cout << "The final map interval structure is:\n";

    //Print imap
    imap.print();

    return 0;
}

//----------------------------------------------------------------------------------------------
//Get lower value to initialize Interval_Map constructor
template <class T>
const T getLowerValue() 
{
    return std::numeric_limits<T>::lowest();
}
//Function template specialization for type unsigned char
template <>
const char getLowerValue()
{
    return 'A';
}

//Generate key or value to populate Interval_Map
template <class T>
const T populateIntervalMap(gen_t& gen) 
{
    T max_nl = std::numeric_limits<T>::max();

    std::uniform_real_distribution<> dis(std::numeric_limits<T>::lowest(), max_nl);
    
    return dis(gen);
}
//Function template specialization for type unsigned char
template <>
const char populateIntervalMap<char>(gen_t& gen) 
{
    std::uniform_int_distribution<> dis(0, 25);

    return (static_cast <char> ('A'+ dis(gen)));
}

