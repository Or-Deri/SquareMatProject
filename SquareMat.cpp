// orderi429@gmail.com

#include "SquareMat.h"
#include <stdexcept>
#include <iostream>



namespace project2 {


    SquareMat::SquareMat(int size){
        this->size = size;

        if (size <= 0){
            throw std::invalid_argument("size must be bigger than 0");
        }
        
        // Initializes all matrix elements to 0
        this->arr = new double [size*size]();  
    }

    SquareMat::SquareMat(const SquareMat& m){
        size = m.size;

        // Copies the values ​​of the matrix
        arr = new double [size*size];
        for (int i = 0; i < size*size; i++){
            arr[i] = m.arr[i];
        }
    }
    
    SquareMat& SquareMat::operator=(const SquareMat& m) {

        // Checks that the operator does not work on the same matrix
        if (this != &m){
            delete[] this->arr;
            this->size = m.size;
            this->arr = new double[size*size];
            // Copies the values ​​of the matrix
            for (int i = 0; i < size*size; i++){
                this->arr[i] = m.arr[i];
            }
        }
        return *this;
    }

    SquareMat::~SquareMat() {
        delete[] arr;
    }


    int SquareMat::getSize() const{
        return this->size;
    }

    SquareMat SquareMat::operator+(const SquareMat& m) const{

        if(this->size != m.size){
            throw std::invalid_argument("The size of the matrix mast to be the same");
        }
        // Creates a new matrix
        SquareMat ans(this->size);
        
        // Connects the values of the matrices
        for (int i = 0; i < size*size; i++){
            ans.arr[i] = this->arr[i] + m.arr[i];
        }
        return ans;
    }

    SquareMat SquareMat::operator-(const SquareMat& m) const{

        if(this->size != m.size){
            throw std::invalid_argument("The size of the matrix mast to be the same");
        }
        // Creates a new matrix
        SquareMat ans(size);
        
        // Connects the values of the matrices
        for (int i = 0; i < size*size; i++){
            ans.arr[i] = this->arr[i] - m.arr[i];
        }
        return ans;
    }

    
    SquareMat SquareMat::operator-() const{
    
        // Creates a new matrix
        SquareMat ans(this->size);

        // Reverses the sign of the values
        for (int i = 0; i < this->size*this->size; i++){
            ans.arr[i] = - this->arr[i];
        }
        return ans;
    }

    SquareMat SquareMat::operator*(const SquareMat& m) const {

        if(this->size != m.size){
            throw std::invalid_argument("The size of the matrix mast to be the same");
        }

        // Creates a new matrix
        SquareMat ans(size);
    
        // Multiplies the row i with a column j
        for (int i = 0; i < m.size; i++){
            for(int j = 0; j < m.size; j++){
                double sum = 0;
                for(int k = 0; k < m.size; k++){
                    //      A[i][k] * B[k][j]
                    sum += this->arr[i*m.size + k] * m.arr[k*m.size + j];
                }
                ans.arr[i*m.size + j] = sum;
            }
        }
        return ans;
    }

    SquareMat SquareMat::operator*(double s) const{
        // Creates a new matrix
        SquareMat ans(size);

        // Multiplies each term in the matrix by a s
        for (int i = 0; i < this->size*this->size; i++){
            ans.arr[i] = this->arr[i] * s;
        }
        return ans;
    }


    SquareMat operator*(double s, const SquareMat& m){

        // Creates a new matrix
        SquareMat ans(m.size);

        // Multiplies each term in the matrix by a s
        for (int i = 0; i < m.size*m.size; i++){
            ans.arr[i] = m.arr[i] * s;
        }
        return ans;
    }

    SquareMat SquareMat::operator%(const SquareMat& m) const{
        if(this->size != m.size){
            throw std::invalid_argument("The size of the matrix mast to be the same");
        }

        // Creates a new matrix
        SquareMat ans(m.size);

        // Multiply each term by the corresponding term
        for (int i = 0; i < m.size*m.size; i++){
            ans.arr[i] = m.arr[i] * this->arr[i];
        }
        return ans;
    }

    SquareMat SquareMat::operator%(int s) const {
        
        if (s == 0){
            throw std::invalid_argument("There is no modulo 0");
        }

        // Creates a new matrix
        SquareMat ans(this->size);

        // Performs modulo on each element in the matrix
        for (int i = 0; i < size * size; i++) {
            ans.arr[i] = (int)this->arr[i] % s;
        }
        return ans;
    }

    SquareMat SquareMat::operator/(double s) const{
        if (s == 0){
            throw std::invalid_argument("No division by 0");
        }
        
        // Creates a new matrix
        SquareMat ans(size);

        // Division each term in the matrix by a s
        for (int i = 0; i < size*size; i++){
            ans.arr[i] = this->arr[i] / s;
        }
        return ans;
    }

    SquareMat SquareMat::operator^(int s) const{

        // Creates a new matrix
        SquareMat ans(size);

        if(s < 0){ 
            throw std::invalid_argument("negative exponent not supported");
        }
        // Everything is 0 and only on the diagonal is there a 1
        if (s == 0){
            for (int i = 0; i < size; i++){
                ans.arr[i*size + i] = 1;
            }
        }
        // Multiplies itself S-1 times
        else{
            ans = *this;
            for (int i = 0; i < s-1; i++){
                ans *= *this;                
            }
        }  
        return ans;
    }

    SquareMat& SquareMat::operator++(){         // add 1 for each element in the matrix before returning
        
        for (int i = 0; i < size*size; i++){
            arr[i]++;
        }
        return *this;
    }

    SquareMat& SquareMat::operator--(){      // subtracting 1 for each element in the matrix before returning
        
        for (int i = 0; i < size*size; i++){
            arr[i]--;
        }
        return *this;
    }

    SquareMat SquareMat::operator++(int){      // add 1 for each element in the matrix after returning
        
        SquareMat temp = *this;

        for (int i = 0; i < size*size; i++){
            arr[i]++;
        }
        return temp;
    }

    SquareMat SquareMat::operator--(int){     // subtracting 1 for each element in the matrix after returning

        SquareMat temp = *this;

        for (int i = 0; i < size*size; i++){
            arr[i]--;
        }
        return temp;
    }

    SquareMat SquareMat::operator~() const{

        // Creates a new matrix
        SquareMat ans(size);

        //Switches between rows and columns
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                ans.arr[i*size + j] = arr[j*size + i];
            }
        }
        return ans;
    }

    double* SquareMat::operator[](int r){
        
        //If the r index is not valid
        if (r < 0 || r >= size) {
            throw std::invalid_argument("Index out of bounds");
        }

        return &arr[r * size];
    }

    const double* SquareMat::operator[](int r) const{
        
        //If the r index is not valid
        if (r < 0 || r >= size) {
            throw std::invalid_argument( " Index out of bounds");
        }

        return &arr[r * size];
    }

    // Help function for operators == and !=
    //The function returns the sum of the elements of a matrix
    double sum(const SquareMat& m){
        double ans = 0;
        for (int i = 0; i < m.size*m.size; i++){
            ans += m.arr[i];
        }
        return ans;
    }

    bool SquareMat::operator==(const SquareMat& m) const{
        // Returns true if the sum of the matrix elements is equal
        if(sum(*this) == sum(m)){
            return true;
        }
        return false; 
    }

    bool SquareMat::operator!=(const SquareMat& m) const{
        // Returns true if the sum of the matrix elements is not equal
        if(sum(*this) != sum(m)){
            return true;
        }
        return false; 
    }


    bool SquareMat::operator<(const SquareMat& m) const{    
        // Returns true if the sum of the elements of the first matrix is ​smaller than the second matrix
        if(sum(*this) < sum(m)){
            return true;
        }
        return false; 
    }
    bool SquareMat::operator<=(const SquareMat& m) const{
        // Returns true if the sum of the elements of the first matrix is ​smaller or equal than the second matrix
        if(sum(*this) <= sum(m)){
            return true;
        }
        return false; 
    }
    bool SquareMat::operator>(const SquareMat& m) const{
        // Returns true if the sum of the elements of the first matrix is bigger than the second matrix
        if(sum(*this) > sum(m)){
            return true;
        }
        return false; 

    }
    bool SquareMat::operator>=(const SquareMat& m) const{
        // Returns true if the sum of the elements of the first matrix is bigger or equal than the second matrix
        if(sum(*this) >= sum(m)){
            return true;
        }
        return false; 
    }

    SquareMat SquareMat::minor( int r, int c)const{
        // Creates a new matrix whit size-1
        SquareMat ans(this->size-1);

        int indexOfNewArr = 0;

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                // Copies all matrix elements except row i and column j
                if(i != r  && j != c ){

                    ans.arr[indexOfNewArr] = this->arr[i*size + j];
                    indexOfNewArr++;
                }
            }
        }
        return ans;
    }

    double SquareMat::operator!(){
        
        if(size == 1){
            return arr[0];
        }
        else if(size == 2){
            // return ad - bc
            return (arr[0]*arr[3]) - (arr[1]*arr[2]); 
        }
        else{
            // Calculating determinant by first row
            double sum = 0.0;
            for (int i = 0; i < size; i++){
                //      (-1)^i 
                sum += (i % 2 == 0 ? 1 : -1) * arr[i] * !this->minor(0,i) ;
            }
            return sum;
        }
    }

    SquareMat& SquareMat::operator+=(const SquareMat& m) {
        
        if(this->size != m.size){
            throw std::invalid_argument("The size of the matrix mast to be the same");
        }

        for (int i = 0; i < size*size; i++) {
            arr[i] += m.arr[i];
        }
        return *this;
    }

    SquareMat& SquareMat::operator-=(const SquareMat& m) {
        if(this->size != m.size){
            throw std::invalid_argument("The size of the matrix mast to be the same");
        }

        for (int i = 0; i < size*size; i++) {
            arr[i] -= m.arr[i];
        }
        return *this;
    }

    SquareMat& SquareMat::operator*=(const SquareMat& m){
        if(this->size != m.size){
            throw std::invalid_argument("The size of the matrix mast to be the same");
        }


        // Creates a new matrix
        SquareMat ans(m.size);

        // Multiplies the row i with a column j
        for (int i = 0; i < m.size; i++){
            for(int j = 0; j < m.size; j++){
                double sum = 0;
                for(int k = 0; k < m.size; k++){
                    //      A[i][k] * B[k][j]
                    sum += arr[i*m.size + k] * m.arr[k*m.size + j];
                }
                ans.arr[i*m.size + j] = sum;
            }
        }

        *this = ans;
        return *this;
    }
    
    SquareMat& SquareMat::operator*=(double s){
        // Multiplies each element in the matrix by s
        for (int i = 0; i < size * size; ++i) {
            arr[i] *= s;
        }

        return *this;
    }
    SquareMat& SquareMat::operator/=(double s){

        if (s == 0){
            throw std::invalid_argument("No division by 0");
        }

        // Divides each element in the matrix by s
        for (int i = 0; i < size * size; ++i) {
            arr[i] /= s;
        }

        return *this;
    }

    SquareMat& SquareMat::operator%=(const SquareMat& m){
        if(size != m.size){
            throw std::invalid_argument("The size of the matrix mast to be the same");
        }

        // Multiply each term by the corresponding term
        for (int i = 0; i < m.size*m.size; i++){
            arr[i] *= m.arr[i];
        }

        return *this;
    }

    SquareMat& SquareMat::operator%=(int s){
        if (s == 0){
            throw std::invalid_argument("There is no modulo 0");
        }

        // Performs modulo on each element in the matrix
        for (int i = 0; i < size * size; i++) {
            arr[i] = (int)arr[i] % s;
        }

        return *this;
    }



    std::ostream& operator<<(std::ostream& os, const SquareMat& m){

        for (int i = 0; i < m.size; i++){
            for (int j = 0; j < m.size; j++){
            
                // Print the element (i,j) 
                os << m.arr[i*m.size + j] << " "; 
            }
            // New line
            os << "\n" ;
        }

        return os;
    }




































































}
    


