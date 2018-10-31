//
// Created by heimdall on 31.10.18.
//

#ifndef BigUint_PROJECT_BIGUNSIGNED_H
#define BigUint_PROJECT_BIGUNSIGNED_H

#include <vector>
#include <string>

typedef unsigned uint;
using namespace std;
class BigUint {
public:
    static const uint base = 10;
    std::vector<uint> data;

    BigUint() : BigUint(0) {}

    BigUint(const std::string &s);

    BigUint(int num) : BigUint(std::to_string(num)) {}

    BigUint(long long num) : BigUint(std::to_string(num)) {}

    bool isZero() const;

    void removeZeros();

    std::string to_string();

    friend void divModData(BigUint lhs, BigUint rhs, BigUint &div, BigUint &mod);

    friend BigUint pow(BigUint base, BigUint power);

    BigUint sqrt();

public:
    friend int compare(const BigUint &lhs, const BigUint &rhs);

    friend BigUint operator+(const BigUint &lhs, const BigUint &rhs);

    friend BigUint operator-(const BigUint &lhs, const BigUint &rhs);

    friend BigUint operator*(const BigUint &lhs, const BigUint &rhs);

    friend BigUint operator/(const BigUint &lhs, const BigUint &rhs);

    friend BigUint operator%(const BigUint &lhs, const BigUint &rhs);

    friend bool operator==(const BigUint &lhs, const BigUint &rhs);

    friend bool operator<(const BigUint &lhs, const BigUint &rhs);

    friend bool operator>(const BigUint &lhs, const BigUint &rhs);

    friend bool operator<=(const BigUint &lhs, const BigUint &rhs);

    friend bool operator>=(const BigUint &lhs, const BigUint &rhs);

    friend bool operator!=(const BigUint &lhs, const BigUint &rhs);

    BigUint &operator<<=(int size);

    BigUint &operator>>=(int size);

    friend void PrintTo(const BigUint &num, std::ostream *os);
};


#endif //BigUint_PROJECT_BIGUNSIGNED_H
