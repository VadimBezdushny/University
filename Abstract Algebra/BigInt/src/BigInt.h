//
// Created by heimdall on 18.10.18.
//

#ifndef BIGINT_BIGINT_H
#define BIGINT_BIGINT_H

#include <vector>
#include <string>
#include <algorithm>
#include <ostream>
#include <iterator>
#include <iostream>
#include "BigUint.h"


class BigInt : public BigUint{
    friend class BigIntTest;

public:
    static const uint base = 10;
    int sign;
    std::vector<uint> data;

    BigInt() : BigInt(0) {}

    BigInt(const std::string &s);

    BigInt(int num) : BigInt(std::to_string(num)) {}

    BigInt(long long num) : BigInt(std::to_string(num)) {}

    bool isZero() const;

    void removeZeros();

    std::string to_string();

    friend int compareData(const BigInt &lhs, const BigInt &rhs);

    friend BigInt pow(BigInt base, BigInt power);

    BigInt sqrt();

public:
    friend int compare(const BigInt &lhs, const BigInt &rhs);

    friend BigInt operator+(const BigInt &lhs, const BigInt &rhs);

    friend BigInt operator-(const BigInt &lhs, const BigInt &rhs);

    friend BigInt operator*(const BigInt &lhs, const BigInt &rhs);

    friend BigInt operator/(const BigInt &lhs, const BigInt &rhs);

    friend BigInt operator%(const BigInt &lhs, const BigInt &rhs);

    friend bool operator==(const BigInt &lhs, const BigInt &rhs);

    friend bool operator<(const BigInt &lhs, const BigInt &rhs);

    friend bool operator>(const BigInt &lhs, const BigInt &rhs);

    friend bool operator<=(const BigInt &lhs, const BigInt &rhs);

    friend bool operator>=(const BigInt &lhs, const BigInt &rhs);

    friend bool operator!=(const BigInt &lhs, const BigInt &rhs);

    BigInt &operator<<=(int size);

    BigInt &operator>>=(int size);

    BigInt &setSign(int new_sign);

    int getSign();

    friend void PrintTo(const BigInt &num, std::ostream *os);
};


#endif //LABS_BIGINT_H