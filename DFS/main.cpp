#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include "vertex.h"

/*This code performs the Depth-First Search algorithm (DFS) on a tree data structure.
  While traversing the tree, each vertex name is compared to a given string.
  The number of vertices, having their name equal (case-insensitive) to the string,
  is returned as output. 
*/

//-----------------------------------------------------------------------
//Return a case-insensitive string
std::string getCaseInsensitive(std::string str) 
{
        int i = 0;

        while (str[i]) {
             if (isupper(str[i]))
                str[i] = static_cast<char>(tolower(str[i]));
            i++;
        }

        return str;
    }

//------------------------------------------------------------------------ 
//Perform the search and check while traversing the tree   
 int countVerticesIncludingString(const Vertex& v, const std::string& str) 
{
	static int count {};
	std::string check = v.m_name;

  //Comparison
	if ( getCaseInsensitive(check) == str ) 
		count++;

	std::vector<Vertex>::const_iterator it;

	for ( it = v.m_children.begin(); it != v.m_children.end(); it++ ) 
    //Recursion to traverse the tree
		countVerticesIncludingString(*it, str); 	

	return count;
}

//----------------------------------------------------------------------------------------------
//main
int main() 
{	
   Vertex v("C++",{
   	{"iS",{
   		{"c++"},
   		{"IS"}
   	}},
   	{"fAst",{
   		{"scaLABle", { 
   			{"C++", {
   				{"Is"},
   				 {"EFFICIENT"}
   				}}
   			}}
   		}}
   });

   std::string str = "Is";

   std::cout << "The number of vertices containing the string \"" << str << "\" (case-insensitive) is: " << countVerticesIncludingString(v, getCaseInsensitive(str)) << "\n";

	return 0;
}
