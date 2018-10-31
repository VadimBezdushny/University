//
// Created by heimdall on 31.10.18.
//

#include <algorithm>
#include <iterator>
#include "BigUint.h"

BigUint::BigUint(const std::string &s) {
    data.reserve(s.size());
    for (auto ch:s)
        if (isdigit(ch))
            data.push_back((uint) (ch - '0'));

    std::reverse(data.begin(), data.end());
    removeZeros();
}

bool BigUint::isZero() const {
    return data.size() == 1 && data.front() == 0;
}

void BigUint::removeZeros() {
    if (data.empty()) {
        this->data.push_back(0); // TODO
    }
    while (data.size() > 1 && data.back() == 0)
        data.pop_back();
}

std::string BigUint::to_string() {
    std::string result;
    for (auto it = data.rbegin(); it != data.rend(); it++) {
        result.append(std::to_string(*it));
    }
    return result;
}

void PrintTo(const BigUint &num, std::ostream *os) {
    std::copy(num.data.rbegin(), num.data.rend(), std::ostream_iterator<uint>(*os, ""));
}

bool operator==(const BigUint &lhs, const BigUint &rhs) {
    return compare(lhs, rhs) == 0;
}

bool operator<(const BigUint &lhs, const BigUint &rhs) {
    return compare(lhs, rhs) < 0;
}

bool operator>(const BigUint &lhs, const BigUint &rhs) {
    return compare(lhs, rhs) > 0;
}

bool operator<=(const BigUint &lhs, const BigUint &rhs) {
    return compare(lhs, rhs) <= 0;
}

bool operator>=(const BigUint &lhs, const BigUint &rhs) {
    return compare(lhs, rhs) >= 0;
}

bool operator!=(const BigUint &lhs, const BigUint &rhs) {
    return compare(lhs, rhs) != 0;
}


BigUint &BigUint::operator<<=(int size) {
    size_t initial_size = data.size();
    data.resize(initial_size + size);
    std::copy(data.begin(), data.begin() + initial_size, data.begin() + size);
    std::fill(data.begin(), data.begin() + size, 0);
    return *this;
}

BigUint &BigUint::operator>>=(int size) {
    std::copy(data.begin() + size, data.end(), data.begin());
    data.resize(data.size() - size);
    removeZeros();
    return *this;
}


int compare(const BigUint &lhs, const BigUint &rhs) {
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

BigUint operator+(const BigUint &lhs, const BigUint &rhs) {
    /*
     * Add two numbers ignoring sign
     */

    BigUint result;

    result.data.resize(std::max(lhs.data.size(), rhs.data.size()) + 1);
    auto lhs_iter = lhs.data.begin(), rhs_iter = rhs.data.begin();

    uint carry = 0;
    size_t tail = 0;
    while (carry > 0 || lhs_iter != lhs.data.end() || rhs_iter != rhs.data.end()) {
        uint digit_sum = (lhs_iter != lhs.data.end() ? *lhs_iter : 0) +
                         (rhs_iter != rhs.data.end() ? *rhs_iter : 0) +
                         carry;

        result.data[tail++] = digit_sum % BigUint::base;
        carry = digit_sum / BigUint::base;

        if (lhs_iter != lhs.data.end())lhs_iter++;
        if (rhs_iter != rhs.data.end())rhs_iter++;
    }
    result.removeZeros();
    return result;
}

BigUint operator-(const BigUint &lhs, const BigUint &rhs) {
    if (lhs < rhs) {
        return BigUint(0);
    }
    BigUint result;
    result.data.clear();
    auto lhs_iter = lhs.data.begin(), rhs_iter = rhs.data.begin();
    uint need = 0;
    while (lhs_iter != lhs.data.end()) {
        auto rhs_digit = (rhs_iter != rhs.data.end() ? *rhs_iter : 0);

        uint next_need = static_cast<uint>(*lhs_iter < rhs_digit + need);
        uint next_digit = BigUint::base * next_need + *lhs_iter - rhs_digit - need;
        result.data.push_back(next_digit);

        need = next_need;

        lhs_iter++;
        if (rhs_iter != rhs.data.end()) {
            rhs_iter++;
        }
    }
    result.removeZeros();
    return result;
}

BigUint operator*(const BigUint &lhs, const BigUint &rhs) {
    BigUint result;
    result.data.resize(lhs.data.size() + rhs.data.size());
    for (std::size_t i = 0; i < lhs.data.size(); i++) {
        uint carry = 0;
        for (std::size_t j = 0; carry || j < rhs.data.size(); j++) {
            uint cur = result.data[i + j] + carry + lhs.data[i] * (j < rhs.data.size() ? rhs.data[j] : 0);
            result.data[i + j] = cur % BigUint::base;
            carry = cur / BigUint::base;
        }
    }
    result.removeZeros();
    return result;
}

void divModData(BigUint lhs, BigUint rhs, BigUint &div, BigUint &mod) {
    BigUint z = 1;
    int k = 0;
    while (lhs >= rhs) {
        rhs <<= 1;
        z <<= 1;
        k++;
    }
    while (k > 0) {
        rhs >>= 1;
        z >>= 1;
        k--;
        while (lhs >= rhs) {
            lhs = lhs - rhs;
            div = div + z;
        }
    }
    mod = lhs;
}

BigUint operator/(const BigUint &lhs, const BigUint &rhs) {
    BigUint div, mod;
    divModData(BigUint(lhs), BigUint(rhs), div, mod);
    return div;
}

BigUint operator%(const BigUint &lhs, const BigUint &rhs) {
    BigUint div, mod;
    divModData(BigUint(lhs), BigUint(rhs), div, mod);
    return mod;
}

BigUint pow(BigUint base, BigUint power) {
    BigUint res = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            res = res * base;
        }
        base = base * base;
        power = power / 2;
    }
    return res;
}

BigUint BigUint::sqrt() {
    if (*this == 0) return BigUint(0);

    BigUint curr = 1, next;
    curr <<= (this->data.size() + 1 / 2);
    int k = 0;
    while (true) {
        next = (curr + *this / curr) / 2;
        if (next >= curr) {
            return curr;
        }
        curr = next;
    }
}
