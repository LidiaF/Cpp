#Matrix Multiplication
This code performs the matrix multiplication.
Matrices are generated as random floating points values, uniformly distributed on the interval [l,u).
Matrices are stored as row-major arrays.

References:
Matrix Multiplication: http://mathworld.wolfram.com/MatrixMultiplication.html
std::uniform_real_distribution: http://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
Row-major array: http://www.plantation-productions.com/Webster/www.artofasm.com/Linux/HTML/Arraysa2.html

#-------------------------------------------------------------------------------------------------------
Please, set the template type of class "Matrix" in "main.cpp" before compiling the code.
Supported types categories: floating point and integer.

Example:
Matrix <int> a;

#-------------------------------------------------------------------------------------------------------
#To compile
make

#To run
./mm
