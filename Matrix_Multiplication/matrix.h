#ifndef _MATRIX_H_
#define _MATRIX_H_

template <typename T>
class Matrix {
private:
	//Number of rows
	int m_rows;
	//Number of columns
	int m_cols;
	//Matrix stored as a row-major array 
	T* m_data;

public:
	//Default Constructor
	Matrix() { m_rows = 0; m_cols = 0; m_data = nullptr; };
	//Copy Construnctor
	//Dynamic memory allocation of m_data because the size of the array is known at runtime
	Matrix(int rows, int cols) { m_rows = rows; m_cols = cols; m_data = new T [m_rows * m_cols]; };
	//Destructor
	//Deallocate memory to retun to the os
	//Set the dangling pointer (a pointer pointing to deallocated memory) to nullptr to avoid undefined behaviour 	
	~Matrix() { if (m_data) { delete[] m_data; m_data = nullptr; } };
	//Update "m_rows", "m_cols" and "m_data"
	//It could be called after the default constructor to populate the matrix
	void create_matrix(const int rows, const int cols) { m_rows = rows; m_cols = cols; m_data = new T [m_rows * m_cols]; }
	//Set "m_data" to "el" at position "index"
	void set_data(const int index, const T el) { m_data[index] = el; }
	//Get "m_rows"
	int get_rows() const { return m_rows; }
	//Get "m_cols"
	int get_cols() const { return m_cols; }
	//Get "m_data"
	T* get_data() const { return m_data; }
	//Print matrix
	void print() const 
	{  
		int a_size {m_rows * m_cols};
        for (int i = 0; i < a_size; i++) 
        {
        	std::cout << m_data[i] << " ";

        	if (( i + 1 ) % m_cols == 0)
        		std::cout << "\n";
        }
	}
	//-----------------------------------------------------------------------------------------------------
	//Friend function declaration - U is used instead of T to avoid shadowed templates
	template <typename U>
	friend void generateRowMajorArray(Matrix <U>&, const int , const int );	 
};

#endif

