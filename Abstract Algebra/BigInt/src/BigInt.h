//
// Created by heimdall on 18.10.18.
//

#ifndef BIGINT_BIGINT_H
#define BIGINT_BIGINT_H

#include<vector>
#include<string>
#include <algorithm>


typedef unsigned uint;

class BigInt {
    static const uint base = 10;
    int sign;
    std::vector<uint> data;

    BigInt() : sign(0) {
    }

    explicit BigInt(std::string s);

    int compare(const BigInt &lhs, const BigInt &rhs);
    BigInt addData(const BigInt &lhs, const BigInt &rhs);
    BigInt substractData(const BigInt &lhs, const BigInt &rhs);
    BigInt multiplyData(const BigInt &lhs, const BigInt &rhs);

    void removeZeros();
    friend BigInt operator+(const BigInt &lhs, const BigInt &rhs);


};





#endif //LABS_BIGINT_H
