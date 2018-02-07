#ifndef _INTERVAL_MAP_H
#define _INTERVAL_MAP_H

template <class K, class V>
class Interval_Map {
private:
	//Map - associative container
	std::map <K,V> m_map;

public:
	//Copy Constructor
	Interval_Map(K key, V value);
	//Insert Key-Value into Interval Map
	void insertInterval(const K& keyLower, const K& keyUpper, const V& value);
	//Print Interval Map
	void print();
};

#endif