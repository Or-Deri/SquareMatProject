// orderi429@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "SquareMat.h"
#include "doctest.h"

using namespace project2;

TEST_CASE("Constructor"){
    
    SquareMat m(2);

    m[1][1] = 8;

    CHECK(m.getSize() == 2);
    CHECK(m[1][1] == 8);
}


TEST_CASE("Copy constructor"){
    
    SquareMat m(2);
    m[0][0] = 8;

    SquareMat m2(m);

    CHECK(m2.getSize() == 2);
    CHECK(m2[0][0] == 8);
}

TEST_CASE("Constructor receives input that is not positive") {
    CHECK_THROWS_AS(SquareMat(0), std::invalid_argument);
    CHECK_THROWS_AS(SquareMat(-7), std::invalid_argument);
}


TEST_CASE(" Copy assignment operator "){
    
    SquareMat m(2);
    m[0][0] = 8;

    SquareMat m2(3);
    m2 = m;

    CHECK(m2.getSize() == 2);
    CHECK(m2[0][0] == 8);
}

TEST_CASE(" getSize() test"){
    SquareMat m(2);
    
    CHECK(m.getSize() == 2);
}

TEST_CASE("Operator + "){

    SquareMat m1(2);
    m1[0][0] = 4;

    SquareMat m2(2);
    m2[0][0] = 3;

    CHECK((m1+m2)[0][0] == 7);
    CHECK((m1+m2)[0][1] == 0);
}
TEST_CASE("Operator + with matrices that are not the same size") {
    SquareMat m1(2);
    SquareMat m2(3);
    
    //The matrices are not the same size
    CHECK_THROWS_AS((m1 + m2), std::invalid_argument);
}


TEST_CASE("Operator - "){

    SquareMat m1(2);
    m1[0][0] = 4;

    SquareMat m2(2);
    m2[0][0] = 3;

    CHECK((m1-m2)[0][0] == 1);
    CHECK((m1-m2)[0][1] == 0);
}
TEST_CASE("Operator - with matrices that are not the same size") {
    SquareMat m1(2);
    SquareMat m2(3);
    
    //The matrices are not the same size
    CHECK_THROWS_AS((m1 - m2), std::invalid_argument);
}


TEST_CASE("Operator * "){

    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;

    SquareMat m2(2);
    m2[0][0] = 1;
    m2[0][1] = 2;                  // (1 2) * (1 2)  = (5 2)
    m2[1][0] = 2;                  // (0 0)   (2 0)    (0 0)
                                    
    CHECK((m1*m2)[0][0] == 5);
    CHECK((m1*m2)[0][1] == 2);
    CHECK((m1*m2)[1][0] == 0);
    CHECK((m1*m2)[1][1] == 0);
}
TEST_CASE("Operator * with matrices that are not the same size") {
    SquareMat m1(2);
    SquareMat m2(3);
    
    // The matrices are not the same size
    CHECK_THROWS_AS((m1 * m2), std::invalid_argument);
}



TEST_CASE("Operator * with scalar "){

    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;

    CHECK((m1*3)[0][0] == 3);
    CHECK((3*m1)[0][1] == 6);
    CHECK((m1*2)[0][0] == 2);
    CHECK((2*m1)[0][1] == 4);
}

TEST_CASE("Operator % "){

    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;

    SquareMat m2(2);
    m2[0][0] = 1;
    m2[0][1] = 2;                  // (1 2) % (1 2)  = (1 4)
    m2[1][0] = 2;                  // (0 0)   (2 0)    (0 0)
                                    
    CHECK((m1%m2)[0][0] == 1);
    CHECK((m1%m2)[0][1] == 4);
    CHECK((m1%m2)[1][0] == 0);
    CHECK((m1%m2)[1][1] == 0);
}
TEST_CASE("Operator % with matrices that are not the same size") {
    SquareMat m1(2);
    SquareMat m2(3);
    
    CHECK_THROWS_AS((m1 % m2), std::invalid_argument);
}



TEST_CASE("Operator % with scalar "){

    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;

    CHECK((m1 % 3)[0][0] == 1);
    CHECK((m1 % 3)[0][1] == 2);
    CHECK((m1 % 2)[0][0] == 1);
    CHECK((m1 % 2)[0][1] == 0);
}
TEST_CASE("Operator % with 0 ") {
    SquareMat m1(2);
    
    // No division by 0
    CHECK_THROWS_AS((m1 % 0 ), std::invalid_argument);
}


TEST_CASE("Operator / with scalar "){

    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;

    CHECK((m1 / 3)[0][0] == 1.0/3);
    CHECK((m1 / 3)[0][1] == 2.0/3);
    CHECK((m1 / 2)[0][0] == 1.0/2);
    CHECK((m1 / 2)[0][1] == 1);
}
TEST_CASE("Operator / with 0") {
    SquareMat m1(2);
    
    CHECK_THROWS_AS((m1 / 0), std::invalid_argument);
}


TEST_CASE("Operator ^ with scalar "){

    SquareMat m1(2);
    m1[0][0] = 1;                      // (1 2) ^ 2 = (5 2)
    m1[0][1] = 2;                      // (2 0)       (2 4)
    m1[1][0] = 2;

    CHECK((m1^2)[0][0] == 5);
    CHECK((m1^2)[0][1] == 2);
    CHECK((m1^2)[1][0] == 2);
    CHECK((m1^2)[1][1] == 4);
}
TEST_CASE("Operator ^ with 0 ") {
    SquareMat m1(2);
    m1[0][0] = 1;                     
    m1[0][1] = 2;                      
    m1[1][0] = 3;
    m1[1][1] = 4;
    
    // Should become the identity matrix
    CHECK((m1 ^ 0)[0][0] == 1);
    CHECK((m1 ^ 0)[0][1] == 0);
    CHECK((m1 ^ 0)[1][0] == 0);
    CHECK((m1 ^ 0)[1][1] == 1);
}
TEST_CASE("Operator ^ with negative scalar") {
    SquareMat m1(2);
    
    CHECK_THROWS_AS((m1 ^ -2), std::invalid_argument);
}

TEST_CASE("Operator ++ before returning"){

    SquareMat m1(2);
    m1[0][0] = 1;              
    m1[0][1] = 2;                      
    m1[1][0] = 3;
    
    CHECK((++m1)[0][0] == 2);    //Adds 1 before returning
    CHECK((m1)[0][1] == 3);
    CHECK((m1)[1][0] == 4);
    CHECK((m1)[1][1] == 1);
}

TEST_CASE("Operator --  before returning"){

    SquareMat m1(2);
    m1[0][0] = 1;              
    m1[0][1] = 2;                      
    m1[1][0] = 3;

    CHECK((--m1)[0][0] == 0);    //Subtract 1 before returning
    CHECK((m1)[0][1] == 1);
    CHECK((m1)[1][0] == 2);
    CHECK((m1)[1][1] == -1);
}

TEST_CASE("Operator ++ after returning"){

    SquareMat m1(2);
    m1[0][0] = 1;              
    m1[0][1] = 2;                      
    m1[1][0] = 3;
    
    CHECK((m1++)[0][0] == 1);   // Does not change , adds 1 after the return
    CHECK((m1)[0][1] == 3);
    CHECK((m1)[1][0] == 4);
    CHECK((m1)[1][1] == 1);
}

TEST_CASE("Operator -- after returning"){

    SquareMat m1(2);
    m1[0][0] = 1;              
    m1[0][1] = 2;                      
    m1[1][0] = 3;
    
    CHECK((m1--)[0][0] == 1);   // Does not change , subtract 1 after the return
    CHECK((m1)[0][1] == 1);
    CHECK((m1)[1][0] == 2);
    CHECK((m1)[1][1] == -1);
}


TEST_CASE("Operator ~"){

    SquareMat m1(2);
    m1[0][0] = 1;      // (1 2)t  ----> (1 3)
    m1[0][1] = 2;      // (3 0)         (2 0)  
    m1[1][0] = 3;
    
    CHECK((~m1)[0][0] == 1); 
    CHECK((~m1)[0][1] == 3);
    CHECK((~m1)[1][0] == 2);
    CHECK((~m1)[1][1] == 0);
}


TEST_CASE("Operator []"){

    SquareMat m1(2);
    m1[0][0] = 1;      
    m1[0][1] = 2;       
    m1[1][0] = 3;
    
    CHECK(m1[0][0] == 1); 
    CHECK(m1[0][1] == 2); 
    CHECK(m1[1][0] == 3); 
    CHECK(m1[1][1] == 0); 
}

TEST_CASE("Operator [] with invalid input"){

    SquareMat m1(2);
    m1[0][0] = 1;      
    
    CHECK_THROWS_AS((m1[-1][0]), std::invalid_argument);
    CHECK_THROWS_AS((m1[3][0]), std::invalid_argument);
}

TEST_CASE("Sum test"){

    SquareMat m1(2);
    m1[0][0] = 1;      
    m1[0][1] = 2;       
    m1[1][0] = 3;      
    
    CHECK((sum(m1)) == 6);
    CHECK_FALSE(sum(m1) == 5);
}

TEST_CASE("Operator =="){

    SquareMat m1(2);
    m1[0][0] = 1;      
    m1[0][1] = 2;       
    m1[1][0] = 3;
    
    SquareMat m2(1);
    m2[0][0] = 6;      
    
    SquareMat m3(2);
    m3[0][0] = 3;      
    
    CHECK(m1 == m2);
    CHECK_FALSE(m1 == m3);
}

TEST_CASE("Operator !="){

    SquareMat m1(2);
    m1[0][0] = 1;      
    m1[0][1] = 2;       
    m1[1][0] = 3;
    
    SquareMat m2(2);
    m2[0][0] = 5;      
    
    SquareMat m3(2);
    m3[0][0] = 6;      
    
    CHECK(m1 != m2);
    CHECK_FALSE(m1 != m3);
}

TEST_CASE("Operator <"){

    SquareMat m1(2);
    m1[0][0] = 1;      
    m1[0][1] = 2;       
    m1[1][0] = 3;
    
    SquareMat m2(2);
    m2[0][0] = 5;      
    
    CHECK(m2 < m1);  
    CHECK_FALSE(m1 < m2); 
}

TEST_CASE("Operator >"){

    SquareMat m1(2);
    m1[0][0] = 1;      
    m1[0][1] = 2;       
    m1[1][0] = 3;
    
    SquareMat m2(2);
    m2[0][0] = 7;      
    
    CHECK(m2 > m1);  
    CHECK_FALSE(m1 > m2);  
}

TEST_CASE("Operator <= "){

    SquareMat m1(2);
    m1[0][0] = 1;      
    m1[0][1] = 2;       
    m1[1][0] = 3;
    
    SquareMat m2(2);
    m2[0][0] = 6;      

    SquareMat m3(2);
    m3[0][0] = 8;      
    
    SquareMat m4(2);
    m4[0][0] = 2;      
    
    
    CHECK(m1 <= m2);
    CHECK(m1 <= m3);
    CHECK_FALSE(m1 <= m4);  
}


TEST_CASE("Operator >= "){

    SquareMat m1(2);
    m1[0][0] = 1;      
    m1[0][1] = 2;       
    m1[1][0] = 3;
    
    SquareMat m2(2);
    m2[0][0] = 6;      

    SquareMat m3(2);
    m3[0][0] = 2;      
    
    SquareMat m4(2);
    m4[0][0] = 8;      
    

    CHECK(m1 >= m2);
    CHECK(m1 >= m3);
    CHECK_FALSE(m1 >= m4);  
}


TEST_CASE("Operator ! "){

    SquareMat m1(3);        //  (1  0  0)
    m1[0][0] = 1;           //  (7 -4  3)
    m1[0][1] = 0;           //  (4  9 -7)
    m1[0][2] = 0;
    
    m1[1][0] = 7;      
    m1[1][1] = -4;       
    m1[1][2] = 3;
    
    m1[2][0] = 4;      
    m1[2][1] = 9;       
    m1[2][2] = -7;

    // Calculate by row 0
    // !m1 =  (-1)^2 * 1 * [(-4 * -7) - (3 * 9)] = 1 
    
    CHECK(!m1 == 1);
    CHECK_FALSE(!m1 == 6);  
}


TEST_CASE("Operator += "){

    SquareMat m1(2);
    m1[0][0] = 4;

    SquareMat m2(2);
    m2[0][0] = 3;

    m1 += m2;
    CHECK(m1[0][0] == 7);
    CHECK(m1[0][1] == 0);
}
TEST_CASE("Operator += with matrices that are not the same size") {
    SquareMat m1(2);
    SquareMat m2(3);
    
    // The matrices are not the same size
    CHECK_THROWS_AS((m1 += m2), std::invalid_argument);
}


TEST_CASE("Operator -= "){

    SquareMat m1(2);
    m1[0][0] = 4;

    SquareMat m2(2);
    m2[0][0] = 3;

    m1 -= m2;
    CHECK(m1[0][0] == 1);
    CHECK(m1[0][1] == 0);
}
TEST_CASE("Operator -= with matrices that are not the same size") {
    SquareMat m1(2);
    SquareMat m2(3);
    
    // The matrices are not the same size
    CHECK_THROWS_AS((m1 -= m2), std::invalid_argument);
}


TEST_CASE("Operator *= "){

    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;

    SquareMat m2(2);
    m2[0][0] = 1;
    m2[0][1] = 2;                  // (1 2) * (1 2)  = (5 2)
    m2[1][0] = 2;                  // (0 0)   (2 0)    (0 0)
                      
    m1 *= m2;
    CHECK((m1)[0][0] == 5);
    CHECK((m1)[0][1] == 2);
    CHECK((m1)[1][0] == 0);
    CHECK((m1)[1][1] == 0);
}
TEST_CASE("Operator *= with matrices that are not the same size") {
    SquareMat m1(2);
    SquareMat m2(3);
    
    // The matrices are not the same size
    CHECK_THROWS_AS((m1 *= m2), std::invalid_argument);
}

TEST_CASE("Operator *= with scalar "){

    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;

    m1 *= 2;
    CHECK((m1)[0][0] == 2);
    CHECK((m1)[0][1] == 4);
    CHECK((m1)[1][0] == 0);
}


TEST_CASE("Operator /= with scalar "){

    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;

    m1 /= 2.0;
    CHECK((m1)[0][0] == 0.5);
    CHECK((m1)[0][1] == 1);
    CHECK((m1)[1][0] == 0);
}

TEST_CASE("Operator /= with 0"){

    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;

    CHECK_THROWS_AS((m1 / 0), std::invalid_argument);
}


TEST_CASE("Operator %= "){

    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;

    SquareMat m2(2);
    m2[0][0] = 1;
    m2[0][1] = 2;                  // (1 2) % (1 2)  = (1 4)
    m2[1][0] = 2;                  // (0 0)   (2 0)    (0 0)
                      
    m1 %= m2;
    CHECK((m1)[0][0] == 1);
    CHECK((m1)[0][1] == 4);
    CHECK((m1)[1][0] == 0);
    CHECK((m1)[1][1] == 0);
}
TEST_CASE("Operator %= with matrices that are not the same size") {
    SquareMat m1(2);
    SquareMat m2(3);
    
    // The matrices are not the same size
    CHECK_THROWS_AS((m1 %= m2), std::invalid_argument);
}

TEST_CASE("Operator %= with scalar "){

    SquareMat m1(2);
    m1[0][0] = 5;
    m1[0][1] = 8;

    m1 %= 2;

    CHECK((m1)[0][0] == 1);
    CHECK((m1)[0][1] == 0);
    CHECK((m1)[1][0] == 0);
}

TEST_CASE("Operator %= with 0"){

    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;


    CHECK_THROWS_AS((m1 %= 0), std::invalid_argument);
}

