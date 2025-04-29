// orderi429@gmail.com

#include <ostream>


namespace project2 {

    class SquareMat {
    
        private:
            double* arr;
            int size;

            SquareMat minor(int row, int col) const;
        public: 
            SquareMat(int size);
            SquareMat (const SquareMat& m);
            ~SquareMat();
            SquareMat& operator=(const SquareMat& m); 
            

            int getSize() const;
            SquareMat operator+(const SquareMat& m) const;
            SquareMat operator-(const SquareMat& m) const;
            SquareMat operator-()const;
            SquareMat operator*(const SquareMat& m) const;
            SquareMat operator*(double s) const;
            friend SquareMat operator*(double s, const SquareMat& m);
            SquareMat operator%(const SquareMat& m) const;
            SquareMat operator%(int s) const;
            SquareMat operator/(double s) const;
            SquareMat operator^(int s) const;
            SquareMat& operator++();
            SquareMat& operator--();
            SquareMat operator++(int);
            SquareMat operator--(int);
            SquareMat operator~() const;
            double* operator[](int r);
            const double* operator[](int r) const;
            friend double sum(const SquareMat& m);
            bool operator==(const SquareMat& m) const;
            bool operator!=(const SquareMat& m) const;
            bool operator<(const SquareMat& m) const;
            bool operator<=(const SquareMat& m) const;
            bool operator>(const SquareMat& m) const;
            bool operator>=(const SquareMat& m) const;
            double operator!();
            SquareMat& operator+=(const SquareMat& m);
            SquareMat& operator-=(const SquareMat& m);
            SquareMat& operator*=(const SquareMat& m);
            SquareMat& operator*=(double s);
            SquareMat& operator/=(double s);
            SquareMat& operator%=(const SquareMat& m);
            SquareMat& operator%=(int s);
            friend std::ostream& operator<<(std::ostream& os, const SquareMat& m);

    };
}