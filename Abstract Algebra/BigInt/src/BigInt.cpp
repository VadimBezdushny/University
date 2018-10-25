//
// Created by heimdall on 18.10.18.
//

#include <cassert>
#include "BigInt.h"

BigInt::BigInt(const std::string &s) {
    sign = 1;
    if (s.empty())
        return;

    std::string::const_iterator head = s.begin();
    if (!isdigit(*head)) {
        if (s[0] == '-')
            sign = -1;
        head++;
    }

    data.reserve(static_cast<unsigned long>(std::distance(head, s.end())));

    while (head != s.end()) {
        if (isdigit(*head)) {
            data.push_back((uint) (*head - '0')); // TODO: create char_to_digit
        }
        head++;
    }
    std::reverse(data.begin(), data.end());
    removeZeros();
    if (data.size() == 1 || data.front() == 0)
        sign = 1;
}

BigInt addData(const BigInt &lhs, const BigInt &rhs) {
    /*
     * Add two numbers ignoring sign
     */

    BigInt result;

    result.data.reserve(std::max(lhs.data.size(), rhs.data.size()));
    auto lhs_iter = lhs.data.begin(), rhs_iter = rhs.data.begin();

    uint carry = 0;
    while (carry > 0 || lhs_iter != lhs.data.end() || rhs_iter != rhs.data.end()) {
        uint digit_sum = (lhs_iter != lhs.data.end() ? *lhs_iter : 0) +
                         (rhs_iter != rhs.data.end() ? *rhs_iter : 0) +
                         carry;

        result.data.push_back(digit_sum % BigInt::base);
        carry = digit_sum / BigInt::base;


        if (lhs_iter != lhs.data.end())lhs_iter++;
        if (rhs_iter != rhs.data.end())rhs_iter++;
    }
    return result;
}

BigInt substractData(const BigInt &lhs, const BigInt &rhs) {
    /*
     * Substract two numbers ignoring sign, lhs >= rhs
     *
     */
    BigInt result;
    auto lhs_iter = lhs.data.begin(), rhs_iter = rhs.data.begin();
    uint need = 0;
    while (lhs_iter != lhs.data.end()) {
        auto rhs_digit = (rhs_iter != rhs.data.end() ? *rhs_iter : 0);

        uint next_need = static_cast<uint>(*lhs_iter < rhs_digit + need);
        uint next_digit = BigInt::base * next_need + *lhs_iter - rhs_digit - need;
        result.data.push_back(next_digit);

        need = next_need;

        lhs_iter++;
        if (rhs_iter != rhs.data.end()) {
            rhs_iter++;
        }
    }
    return result;
}


int compare(const BigInt &lhs, const BigInt &rhs) {
    /*
     * takes two numbers
     *
     * returns 1 if lhs > rhs
     * returns 0 if lhs == rhs
     * return -1 if lhs < rhs
     *
     */
    if (lhs.sign != rhs.sign) {
        return (lhs.sign > rhs.sign ? 1 : -1);
    }
    return compareData(lhs, rhs) * lhs.sign;
}

int compareData(const BigInt &lhs, const BigInt &rhs) {
    if (lhs.data.size() != rhs.data.size()) {
        return (lhs.data.size() > rhs.data.size() ? 1 : -1);
    }

    for (auto lhs_iter = lhs.data.rbegin(), rhs_iter = rhs.data.rbegin();
         lhs_iter != lhs.data.rend() && rhs_iter != rhs.data.rend();
         lhs_iter++, rhs_iter++) {
        if (*lhs_iter != *rhs_iter) {
            return (*lhs_iter > *rhs_iter ? 1 : -1);
        }
    }
    return 0;
}


BigInt addOrSub(const BigInt &lhs, const BigInt &rhs, bool subs) {

}
BigInt operator+(const BigInt &lhs, const BigInt &rhs) {
    if (lhs.sign == rhs.sign)
        return addData(lhs, rhs).setSign(lhs.sign);

    if(compareData(lhs, rhs) >= 0){
        return substractData(lhs,rhs).setSign(lhs.sign);
    }else{
        return substractData(rhs, lhs).setSign(rhs.sign);
    }
}

BigInt operator-(const BigInt &lhs, const BigInt &rhs) {
    if(lhs.sign != rhs.sign)
        return addData(lhs,rhs).setSign(lhs.sign);

    if(compareData(lhs, rhs) >= 0){
        return substractData(lhs,rhs).setSign(lhs.sign);
    }else{
        return substractData(rhs, lhs).setSign(rhs.sign);
    }
}

BigInt multiplyData(const BigInt &lhs, const BigInt &rhs) {
    BigInt result;
    result.data.resize(lhs.data.size() + rhs.data.size());
    for (std::size_t i = 0; i < lhs.data.size(); i++) {
        uint carry = 0;
        for (std::size_t j = 0; carry || j < rhs.data.size(); j++) {
            uint cur = result.data[i + j] + carry + lhs.data[i] * (j < rhs.data.size() ? rhs.data[j] : 0);
            result.data[i + j] = cur % BigInt::base;
            carry = cur / BigInt::base;
        }
    }
    return result;
}

void BigInt::removeZeros() {
    while (data.size() > 1 && data.back() == 0)
        data.pop_back();
}

std::string BigInt::to_string() {
    std::string result;
    if (sign == -1) result += "-";
    for (auto it = data.rbegin(); it != data.rend(); it++) {
        result.append(std::to_string(*it));
    }
    return result;
}

bool operator==(const BigInt &lhs, const BigInt &rhs) {
    return lhs.sign == rhs.sign && lhs.data == rhs.data;
}

BigInt &BigInt::setSign(int new_sign) {
    this->sign = new_sign;
    return *this;
}

int BigInt::getSign() {
    return sign;
}

void PrintTo(const BigInt &num, std::ostream *os) {
    *os << num.sign << "*";
    std::copy(num.data.rbegin(), num.data.rend(), std::ostream_iterator<uint>(*os, ""));
}

bool operator<(const BigInt &lhs, const BigInt &rhs) {
    return compare(lhs, rhs) == -1;
}

bool operator>(const BigInt &lhs, const BigInt &rhs) {
    return compare(lhs, rhs) == 1;
}

bool operator<=(const BigInt &lhs, const BigInt &rhs) {
    return compare(lhs, rhs) <= 0;
}

bool operator>=(const BigInt &lhs, const BigInt &rhs) {
    return compare(lhs, rhs) >= 0;
}

bool operator!=(const BigInt &lhs, const BigInt &rhs) {
    return !(lhs == rhs);
}


