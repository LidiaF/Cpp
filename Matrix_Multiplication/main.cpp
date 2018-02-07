#include <iostream>
#include <random>
#include "matrix.h"

//This code performs the matrix multiplication.

//----------------------------------------------------------------------------------------------
//Matrices array size
//It contains: 
//pos 0: matrix A row size
//pos 1: matrix A col size (matrix B row size)
//pos 2: matrix B col size 
const int SIZE {3};

//----------------------------------------------------------------------------------------------
//Get and check input data
int getInput() 
{
	int var;
	do 
	{		
		std::cout << "Please, insert a non-negative integer:\n";
		std::cin >> var;

		//In case non-integer values are entered
		if (std::cin.fail())
		{
			//Reset error flags
			std::cin.clear();
			//Ignore remaining characters, if any, in the input buffer 
			std::cin.ignore(32767, '\n');
			var = -1;

			continue;
		}	

	} while (var < 0); 

	return var;
}

//----------------------------------------------------------------------------------------------
//Populate the row-major array "m_data" in class "Matrix"
template <typename T>
void generateRowMajorArray(Matrix<T> & m, const int l, const int u)
{   
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(l,u);

    for (int i = 0; i < (m.get_rows() * m.get_cols()); i++) 
   		m.m_data[i] = dis(gen);
}

//----------------------------------------------------------------------------------------------
//Perform the matrix multiplication
template <typename T> 
void smm(const Matrix<T>& a, const Matrix<T>& b, Matrix<T>& c) 
{
	//Matrix "c" is created in the main without any information on rows, columns and matrix values
	c.create_matrix(a.get_rows(), b.get_cols());
	//Get the number of elements of matrix "c"
	int c_size {a.get_rows() * b.get_cols()};

	//Fill matrix "c" stored as a row-major array
	//a_shift and b_shift are used, respectively, to navigate matrix "a" and "b" both stored as a row-major arrays 
	int a_shift {};
	int b_shift {};
    
	for (int i = 0; i < c_size; i++) 
	{		
		T el {};
		for (int j = 0; j < a.get_cols(); j++)  
			el += a.get_data()[j + a_shift] * b.get_data()[j * ( b.get_cols() ) + b_shift];
		c.set_data(i, el);

		if (( i + 1 ) % b.get_cols() == 0) 
		{
			b_shift = 0;
			a_shift += a.get_cols();
		}
		else
			b_shift += 1;
	}
 }

//----------------------------------------------------------------------------------------------
//main
int main() 
{
	//Insert matrices rows and  columns
	int arr[SIZE] {};
	std::cout << "\nStandard Matrix Multiplication between matrix A (m x n) and matrix B (n x p). Values for m, n and p must be provided!\n";
	for (int i = 0; i < SIZE; i++) 
		arr[i] = getInput();

	//Invoke constructors
	Matrix<double> a(arr[0], arr[1]);
	Matrix<double> b(arr[1], arr[2]);
	Matrix<double> c;

	//Generate matrix A and matrix B as random floating points values, uniformly diatributed on the interval [l,u)
    //Matrices are stored as row-major arrays
	int l {};
	int u {6};

	generateRowMajorArray(a, l, u);
	generateRowMajorArray(b, l, u);

	//Print matrix A
	std::cout<<"\nMatrix A:\n";
	a.print();

	//Print matrix B
	std::cout<<"\nMatrix B:\n";
	b.print();

	smm(a,b,c);
	std::cout<<"\nMatrix C (result from standard matrix multiplication):\n";
	c.print();

	return 0;
}
	
