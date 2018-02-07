#include <iostream>
#include <string>
#include <unordered_set>

/* Given two strings "str" and "rm", the code removes every occurrence of characters found in 
"rm" from "str".
*/

//----------------------------------------------------------------------------------
//Remove characters from a string
std::string rmCharacters (std::string &str, const std::unordered_set<char>& rm){

	std::unordered_set<char>::const_iterator it;

	for ( it = rm.begin(); it != rm.end(); it++ )
	{
		//Return value of std::string::find()
		//size_t is an unsigned integral type
		std::size_t pos {};	
		//Loop to check the whole string
		do {
			//std::string::find() returns the position of the first match
			//If no match is found, it returns std::string::npos
			//Complexity: Unspecified. Typically, linear in length
			pos = str.find(*it, pos);

			if ( pos != std::string::npos )
				//Erases the character at position pos
				//Complexity: Unspecified. Typically, up to linear in length
				str.erase(pos, 1);

		} while ( pos != std::string::npos );
	}

	return str;
}

//----------------------------------------------------------------------------------
//main.cpp
int main(){

    std::string str = "C++ is fast, scalable and efficient.";
    std::string rm = "+eea";
    
    //Remove duplicates from rm
    std::unordered_set<char> set_rm;

    for ( char i: rm )
    	set_rm.insert(i);

    std::cout << "The string to modify is \"" << str << "\"\n";
    std::cout << "The modified string is \"" << rmCharacters(str, set_rm) << "\"\n";

    return 0;
}