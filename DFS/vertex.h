#ifndef _VERTEX_H_
#define _VERTEX_H_

class Vertex {
private:
	//Vertex name
	std::string m_name;
	//Vertex children
	std::vector<Vertex> m_children;

public:
	//Default Constructor - modified to accept user provided values
	//Vertex v; // means Vertex(" ", {})
	//Vertex v("root"); // means Vertex("root", {})
	//Vertex v("root", {{"vertex1"}, {"vertex2"}})
	Vertex(std::string name = " ", std::vector<Vertex> children = {}): m_name(name), m_children(children) { }
	
	//-----------------------------------------------------------------------------------------------------
	//Friend function declaration 
    friend int countVerticesIncludingString(const Vertex& , const std::string&); 
};


#endif