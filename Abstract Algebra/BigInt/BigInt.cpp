//
// Created by heimdall on 18.10.18.
//

#include <cassert>
#include "BigInt.h"

BigInt operator+(const BigInt &lhs, const BigInt &rhs) {

}

BigInt::BigInt(std::string s) {
    if (s.empty()) {
        throw; // TODO
    }
    sign = 0;
    std::string::iterator head = s.begin();
    if (isdigit(*head)) { // TODO : check isdigit for char
        if (s[0] == '-')
            sign = -1;
        else if (s[0] == '+')
            sign = 1;
        else
            throw; // TODO
        head++;
    }
    std::reverse(head, s.end());

    data.reserve(static_cast<unsigned long>(std::distance(head, s.end())));

    while (head != s.end()) {
        if (isdigit(*head)) {
            data.push_back((uint) (*head - '0')); // TODO: create char_to_digit
        }
        head++;
    }
}

BigInt BigInt::addData(const BigInt &lhs, const BigInt &rhs) {
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

BigInt BigInt::substractData(const BigInt &lhs, const BigInt &rhs) {
    /*
     * Substract two numbers ignoring sign, lhs >= rhs
     *
     */
    // TODO: add sign
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


int BigInt::compare(const BigInt &lhs, const BigInt &rhs) {
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

    bool inverted_answer = (lhs.sign == -1);
    if (lhs.data.size() != rhs.data.size()) {
        return (lhs.data.size() > rhs.data.size() ^ inverted_answer ? 1 : -1);
    }
    auto lhs_iter = lhs.data.rbegin(), rhs_iter = rhs.data.rbegin();
    while (lhs_iter != lhs.data.rend() && rhs_iter != rhs.data.rend()) {
        if (*lhs_iter != *rhs_iter) {
            return (*lhs_iter > *rhs_iter ^ inverted_answer ? 1 : -1);
        }
        lhs_iter++;
        rhs_iter++;
    }
    return 0;
}

