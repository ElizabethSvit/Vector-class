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
    
    Vector(double x, double y) { // конструктор обычного вектора
        x_ = x;
        y_ = y;
    }
    
    double GetNorm() { // для обычного вектора
        return sqrt(pow(x_, 2) + pow(y_, 2));
    }
    
    Vector Normalize() {
        return Vector(x_ / GetNorm(), y_ / GetNorm());
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
    //one.readFromInput();
    
    std::cout << "After " << std::endl;
    //std::cout << one.GetNorm();
    
    return 0;
}
