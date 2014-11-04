#include <iostream>
#include <assert.h>
#include <cmath>

class Vector {
    
private:
    size_t size_;
    double* data_;
    double norm_;
public:
    
    // constructor
    Vector(int s) {
        assert(s > 0);
        
        //std::cout << "Vector()" << std::endl;
        size_ = s;
        data_ = new double[size_];
        
        for (int i = 0; i < size_; ++i) {
            data_[i] = 0;
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
        data_ = new double[size_];
        
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
        data_ = new double[size_];
        
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
        
        return *this;
    }
    
    Vector operator + (Vector second) {
        assert(size_ == second.size_);
        
        Vector sum(size_);
        for (int i = 0; i < size_; ++i) {
            sum.data_[i] = this->data_[i] + second.data_[i];
        }
        
        return sum;
    }
    
    Vector operator - (Vector second) {
        assert(size_ == second.size_);
        
        Vector sum(size_);
        for (int i = 0; i < size_; ++i) {
            sum.data_[i] = this->data_[i] - second.data_[i];
        }
        
        return sum;
    }
    
    Vector operator * (double k) {
        
        Vector sum(size_);
        for (int i = 0; i < size_; ++i) {
            sum.data_[i] = this->data_[i] * k;
        }
        
        return sum;
    }
    
    Vector operator / (double k) {
        Vector sum(size_);
        for (int i = 0; i < size_; ++i) {
            sum.data_[i] = this->data_[i] / k;
        }
        
        return sum;
    }
    
    bool operator == (Vector second) {
        assert(size_ == second.size_);
        int num_true = 0;
        for (int i = 0; i < size_; ++i) {
            if (this->data_[i] == second.data_[i]) {
                num_true ++;
            }
        }
        if (num_true == size_) {
            return true;
        } else {
            return false;
        }
    }
    
    bool operator != (Vector second) {
        assert(size_ == second.size_);
        int num_false = 0;
        for (int i = 0; i < size_; ++i) {
            if (this->data_[i] != second.data_[i]) {
                num_false ++;
            }
        }
        if (num_false == size_) {
            return true;
        } else {
            return false;
        }
    }
    
    double GetNorm() {
        norm_ = 0;
        for (int i = 0; i < size_; ++i) {
            norm_ += pow(data_[i], 2);
        }
        return sqrt(norm_);
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
    Vector one(5);
    Vector two(5);
    Vector sum(5);
    
    std::cout << "Before " << std::endl;
    one.readFromInput();
    two.readFromInput();
    
    std::cout << "After " << std::endl;
    sum = one + two;
    two.operator - (one);
    one.operator * (5);
    sum.output();
    //two.output();
    std::cout << one.GetNorm() << std::endl;
    std::cout << one.operator != (two) << std::endl;
    one.Normalize().output();
    
    return 0;
}
