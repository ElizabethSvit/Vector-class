#include <iostream>
#include <assert.h>
#include <cmath>

class Vector {
    
    friend Vector operator + (const Vector&, const Vector&);
    friend Vector operator - (const Vector&, const Vector&);
    friend Vector operator * (const double, const Vector&);
    friend Vector operator / (const double, const Vector&);
    friend const bool operator == (const Vector&, const Vector&);
    friend const bool operator != (const Vector&, const Vector&);
    friend const double GetNorm(const Vector&);
    friend Vector Normalize(const Vector&);
    
private:
    size_t size_;
    int* data_;
    double x_;
    double y_;
public:
    Vector() {
        x_ = 0;
        y_ = 0;
    }
    
    Vector(double x, double y) {
        x_ = x;
        y_ = y;
    }
    
    // constructor
    Vector(int s) {
        assert(s > 0);
        
        std::cout << "Vector()" << std::endl;
        size_ = s;
        data_ = new int[size_];
        
        for (int i = 0; i < size_; ++i) {
            data_[i] = 0;
        }
    }
    
    // destructor
    ~Vector() {
        std::cout << "~Vector()" << std::endl;
        delete [] data_;
        // to enable nullptr, compile with --std=c++0x
        data_ = nullptr;
        // if previous does not work, use this:
        // data_ = NULL;
    }
    
    // copy constructor
    Vector(const Vector& other) {
        size_ = other.size_;
        data_ = new int[size_];
        x_ = other.x_;
        y_ = other.y_;
        
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    
    // assignment operator
    Vector& operator = (const Vector& other) {
        if (this == &other) {
            return *this;
        }
        
        x_ = other.x_;
        y_ = other.y_;
        
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
    
    Vector& operator += (const Vector& other) {
        *this = *this + other;
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

const double GetNorm(const Vector& v) {
    return sqrt(pow(v.x_, 2) + pow(v.y_, 2));
}

Vector Normalize(const Vector& v) {
    return Vector(v.x_ / GetNorm(v), v.y_ / GetNorm(v));
}

Vector operator + (const Vector& v1, const Vector& v2) {
    return Vector(v1.x_ + v2.x_, v1.y_ + v2.y_);
}
Vector operator - (const Vector& v1, const Vector& v2) {
    return Vector(v1.x_ - v2.x_, v1.y_ * v2.y_);
}

Vector operator * (const double k, const Vector& v) {
    return Vector(k * v.x_, k * v.y_);
}

Vector operator / (const double k, const Vector& v) {
    return Vector(v.x_ / k, v.y_ / k);
}

const bool operator == (const Vector &v1, const Vector& v2) {
    return v1.x_ == v2.x_ && v1.y_ == v2.y_;
}
const bool operator != (const Vector &v1, const Vector& v2) {
    return !(v1 == v2);
}


int main() {
    std::cout << "Before " << std::endl;
    Vector my_vector(20);
    
    std::cout << "After " << std::endl;
    
    Vector one(5);
    Vector two(5);
    5 * one;
    one.output();
    
    return 0;
}
