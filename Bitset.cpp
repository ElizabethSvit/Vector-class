#include <iostream>
#include <assert.h>
#include <cmath>

class Bitset {
    
private:
    int limit_ = 1024;
    int size_;
    int* set_;
public:
    
    // constructor
    Bitset(int s) {
        assert(s > 0 && s < limit_ / (8 * 4));
        
        size_ = s;
        set_ = new int[size_];
        
        for (int i = 0; i < s; ++i) {
            set_[i] |= (1 << 0);
        }
    }
    
    // copy constructor
    Bitset(const Bitset& other) {
        limit_ = other.limit_;
        set_ = new int[size_];
        
        for (int i = 0; i < size_; ++i) {
            set_[i] = other.set_[i];
        }
    }
    
    // destructor
    ~Bitset() {
        delete [] set_;
        set_ = nullptr;
    }
    
    bool Test(int x) {
        assert(x >= 0 && x <= limit_);
        if (*this->set_ & (1 << x) != 0) {
            return true;
        } else {
            return false;
        }
    }
    
    void Set(int x) {
        *this->set_ |= (1 << x);
    }
    
    bool Empty() {
        if (sizeof(*this->set_) != 0) {
            return true;
        } else {
            return false;
        }
    }
    
    Bitset Union(const Bitset& other) {
        size_ += other.size_;
        for (int i = size_; i < size_ + other.size_; ++i) {
            Set(other.set_[i - size_]);
        }
        return *this;
    }
    
    Bitset Intersection(const Bitset& other) {
        int sum_size_ = 0;
        for (int i = 0; i < size_; ++i) {
            if (Test(other.set_[i])) {
                Set(set_[i]);
                sum_size_++;
            }
        }
        size_ = sum_size_;
        return *this;
    }
    
    Bitset Difference(const Bitset& other) {
        int sum_size_ = 0;
        for (int i = 0; i < size_; ++i) {
            if (!Test(other.set_[i])) {
                Set(set_[i]);
                sum_size_++;
            }
        }
        size_ = sum_size_;
        return *this;
    }
    
    void readFromInput() {
        for (int i = 0; i < size_; ++i) {
            std::cin >> set_[i];
        }
    }
    
    void output() {
        for (int i = 0; i < size_; ++i) {
            std::cout << set_[i] << " ";
        }
        std::cout << std::endl;
    }
    
    size_t size() {
        return size_;
    }
};


int main() {
    Bitset one(5);
    Bitset two(5);
    
    std::cout << "Before" << std::endl;
    one.readFromInput();
    
    std::cout << "After" << std::endl;
    one.Union(two);
    two.output();
    one.output();
    
    return 0;
}

// some changes