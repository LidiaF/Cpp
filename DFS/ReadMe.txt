#Depth-First Search algorithm
This code performs the Depth-First Search algorithm (DFS) on a tree data structure. While traversing the tree, each vertex name is compared to a given string. The number of vertices, having their name equal (case-insensitive) to the string, is returned as output. 

Reference:
DFS algorithm: https://brilliant.org/wiki/depth-first-search-dfs/

#-----------------------------------------------------------------------------------------------------------------
Please, initialize the tree data structure using nested braces syntax {} in "main.cpp" before compiling the code.

Example (see image Example_Tree.jpg):
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

#-----------------------------------------------------------------------------------------------------------------
#To compile
make

#To run
./DFS

