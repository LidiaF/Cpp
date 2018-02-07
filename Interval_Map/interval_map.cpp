#include <iostream>
#include <limits>
#include <map>
#include "interval_map.h"

//Copy Constructor
template <class K, class V>
Interval_Map <K, V>::Interval_Map(K key, V value) 
{
    //Insert a Key-Value pair with hint position (m_map.begin())
    //Complexity: amortized constant if a given hint for the optimal position is given
    //The optimal position follows the inserted element 
	m_map.insert(m_map.begin(), std::make_pair(key, value));
}

//---------------------------------------------------------------------------------------------
//Insert Key-Value into Interval Map
template <class K, class V>
void Interval_Map <K, V>::insertInterval(const K& keyLower, const K& keyUpper, const V& value) 
{
    //--------------
    //Print to validate the insertion process
    std::cout << "Key-Value pair -> keyLower: " << keyLower << ", keyUpper: " << keyUpper << ", value: " << value << "\n";
    std::cout << "Interval Map before the Key-Value pair insertion:\n";
    print();

    //--------------
    //Search for the key interval [it_min->first, it_max->first] containing keyLower and keyUpper
    typename std::map<K,V>::iterator it_min, it_max;
    //Find the lower limit of the key interval
    //upper_bound returns an iterator pointing to the first value that is greater than keyLower in m_map
    //Complexity: logarithmic in size
    it_min = --m_map.upper_bound(keyLower);

    //Find the upper limit of the key interval
    it_max = it_min;
    ++it_max;
       
    if ( it_max->second != m_map.end()->second ) 
    {
        bool found = false;
        do {
            if ( it_max->first <= keyUpper ) 
            {    
                ++it_max;
                if ( it_max->second == m_map.end()->second ) 
                    found = true;
            }
            else 
                found = true;
        } while ( !found );
    }

    //--------------
    //Store the value prior to it_max for later checks
    V it_max_prev = (--it_max)->second;
    ++it_max;

    //--------------
    //Remove Key-Value pair in m_map
    typename std::map<K,V>::iterator it_erase = it_min;
    ++it_erase;
            
    if ( it_erase != it_max )  
        //Erase the desired range [it_erase, it_max)
        //Complexity: linear in the distance between it_erase and it_max
        m_map.erase(it_erase, it_max);
    
    //--------------
    //Insert Key-Value pair in m_map with key keyLower 
    if ( it_min->first != keyLower ) 
    {
        //This check is needed to avoid inserting a Key-Value pair with the same value as it_min 
        if ( it_min->second != value ) 
            //Insert a Key-Value pair with hint position (it_max)
            //Complexity: amortized constant if a given hint for the optimal position is given
            //The optimal position follows the inserted element 
            m_map.insert(it_max, std::pair<K,V>(keyLower, value)); 
    }
    else 
    {
        if ( it_min->second != value ) 
        {
            //This check is needed to modify the value in it_min at the beginning of m_map
            if ( it_min == m_map.begin() ) 
                it_min->second = value;
            else 
            {
                //This check is needed to compare the new value to the one before it_min. If
                //the values are the same, the Key-Value pair inserted above is removed
                it_erase = it_min;
                --it_erase;
                if ( it_erase->second == value )
                    //Erase the desired element at position it_min
                    //Complexity: amortized constant
                    m_map.erase(it_min);    
                else
                    it_min->second = value;  
            }                 
        }
    }

    //--------------
    //Insert Key-Value pair with key interval [keyUpper, it_max->first) with corresponding 
    //value "it_max_prev" previously stored
    if ( it_max_prev != value ) 
        m_map.insert(it_max, std::pair<K,V>(keyUpper, it_max_prev)); 
    
    //--------------

    std::cout << "\n\n";
}

//---------------------------------------------------------------------------------------------
//Print Interval Map
template <class K, class V>
void Interval_Map <K, V>::print() 
{
    for (auto& it : m_map )
        std::cout << "(" << it.first << ", " << it.second << ")" << "\n";
}

//---------------------------------------------------------------------------------------------
//If not specified, the compiler is not able to provide specific support for the desired data 
//types. This is because there are both an ".h" and ".cpp" files for class "Interval Map"
template class Interval_Map <unsigned short, char>;