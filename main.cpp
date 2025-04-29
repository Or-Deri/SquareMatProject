// orderi429@gmail.com
#include <iostream>
#include "SquareMat.h"

int main(){
    
    project2::SquareMat m(2);            // Build first matrix                             
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    std::cout << "matrix m\n" << m << "\n";

    project2::SquareMat m2(2);           // build second matrix
    m2[0][0] = 4;
    m2[0][1] = 8;
    m2[1][0] = 7;
    m2[1][1] = 5;
    std::cout << "matrix m2\n" << m2 << "\n";

    project2::SquareMat m3(m2);                  //Copy-ctor and assignment
    std::cout << "matrix m3\n" << m3 << "\n";
    m3 = m;
    std::cout << "matrix m3\n" << m3 << "\n";

    std::cout << "matrix m+m2\n" << m+m2 << "\n";     // Addition and subtraction operators
    std::cout << "matrix m-m2\n" << m-m2 << "\n";
    
    std::cout << "matrix -m\n" << -m << "\n";     // Unary minus operator

    std::cout << "matrix m*m2\n" << m*m2 << "\n";    // Multiplication operator

    std::cout << "matrix m*2\n" << m*2 << "\n";     // Scalar multiplication operator
    std::cout << "matrix 2*m\n" << 2*m << "\n";

    std::cout << "matrix m%m2\n" << m%m2 << "\n";    // Multiplies each element in one matrix by the corresponding element in the other matrix
    std::cout << "matrix m%3\n" << m%3 << "\n";    //Modulo with a scalar

    
    std::cout << "matrix m/3\n" << m/3 << "\n";    // Scalar division

    std::cout << "matrix m^2\n" << (m^2) << "\n";    //// Power operator

    // Increment and decrement operators by 1
    std::cout << "matrix m++\n" << m++ << "\n";
    std::cout << "matrix --m\n" << --m << "\n";
    std::cout << "matrix ++m\n" << ++m << "\n";
    std::cout << "matrix m--\n" << m-- << "\n";

    // Transpose 
    std::cout << "matrix ~m\n" << ~m << "\n";


    std::cout << "matrix m[0][0]: " << m[0][0] << "\n";
    std::cout << "matrix m[0][1]: " << m[0][1] << "\n";
    std::cout << "matrix m[1][0]: " << m[1][0] << "\n";
    std::cout << "matrix m[1][1]: " << m[1][1] << "\n\n";

    // Comparison operators
    if (m == m3){
        std::cout << "m == m3" << "\n";
    }
    if (m != m2){
        std::cout << "m != m2" << "\n";
    }
    if (m < m2){
        std::cout << "m < m2" << "\n";
    }
    if (m2 > m){
        std::cout << "m2 > m" << "\n";
    }
    if (m <= m2){
        std::cout << "m <= m2" << "\n";
    }
    if (m2 >= m){
        std::cout << "m2 >= m" << "\n\n";
    }

    // determinant
    std::cout << "The determinant of the matrix m is: " << !m << "\n";
    std::cout << "The determinant of the matrix m2 is: " << !m2 << "\n";


    // compound assignment operators
    std::cout << "m += m2 :\n" << (m+=m2) << "\n";
    std::cout << "m -= m2 :\n" << (m-=m2) << "\n";

    std::cout << "m *= 2 :\n" << (m*=2) << "\n";
    std::cout << "m /= 2 :\n" << (m/=2) << "\n";

    std::cout << "m3 *= m2 :\n" << (m3*=m2) << "\n";

    std::cout << "m3 %= m2 :\n" <<(m3 %= m2) << "\n";
    std::cout << "m3 %= 5 :\n" << (m3 %= 5) << "\n";

}

