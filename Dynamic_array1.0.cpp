#include <iostream>
#include <assert.h>
#include <cmath>

class Vector {
    
private:
    size_t size_;
    int* data_;
public:
    
    // constructor
    Vector(int s) {
        assert(s > 0);
        
        //std::cout << "Vector()" << std::endl;
        size_ = s;
        data_ = new int[size_];
        
        for (int i = 0; i < size_; ++i) {
            data_[i] = 1;
        }
    }
    
    // destructor
    ~Vector() {
        //std::cout << "~Vector()" << std::endl;
        delete [] data_;
        data_ = nullptr;
    }
    
    // copy constructor
    Vector(const Vector& other) {
        size_ = other.size_;
        data_ = new int[size_];
        
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    
    // assignment operator
    Vector& operator = (const Vector& other) {
        if (this == &other) {
            return *this;
        }

        delete [] data_;
        data_ = nullptr;
        
        size_ = other.size_;
        data_ = new int[size_];
        
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
        
        return *this;
    }
    
    Vector operator + (Vector second) {
        Vector sum = *this;
        assert(size_ == second.size_);
        
        for (int i = 0; i < size_; ++i) {
            sum.data_[i] += second.data_[i];
        }
        
        return *this;
    }
    
    double GetNorm() {
        int norm = 0;
        for (int i = 0; i < size_; ++i) {
            norm += pow(data_[i], 2);
        }
        return sqrt(norm);
    }
    
    Vector Normalize() {
        for (int i = 0; i < size_; ++i) {
            data_[i] /= GetNorm();
        }
        return *this;
    }
    void readFromInput() {
        for (int i = 0; i < size_; ++i) {
            std::cin >> data_[i];
        }
    }
    
    void output() {
        for (int i = 0; i < size_; ++i) {
            std::cout << data_[i] << " ";
        }
        std::cout << std::endl;
    }
    
    size_t size() {
        return size_;
    }
};


int main() {
    Vector one(4);
    Vector two(4);
    std::cout << "Before " << std::endl;
    one.readFromInput();
    
    std::cout << "After " << std::endl;
    // one.Normalize();
    one.operator+(two);
    one.output();
    
    return 0;
}
