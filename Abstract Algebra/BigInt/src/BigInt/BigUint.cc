//
// Created by heimdall on 31.10.18.
//

#include <algorithm>
#include <iterator>
#include "BigUint.h"
#include <iostream>

BigUint::BigUint(const std::string &s) {
    string temp(base_len, '0');
    for (auto ch:s)
        if (isdigit(ch))
            temp.push_back(ch);
    for(int i = temp.size()-base_len; i >= 0; i -= base_len){
        data.push_back(std::stoi(temp.substr(i,base_len)));
    }
    removeZeros();
}


void BigUint::removeZeros() {
    if (data.empty()) {
        data.push_back(0); // TODO
    }
    while (data.size() > 1 && data.back() == 0)
        data.pop_back();
}

std::string BigUint::to_string() const {
    std::string result;
    for (auto it = data.rbegin(); it != data.rend(); it++) {
        std::string limb = std::to_string(*it);
        result.append(std::string(base_len - limb.length(), '0').append(limb));
    }
    return result;
}

bool operator==(const BigUint &lhs, const BigUint &rhs) {
    return lhs.compareTo(rhs) == 0;
}

bool operator<(const BigUint &lhs, const BigUint &rhs) {
    return lhs.compareTo(rhs) < 0;
}

bool operator>(const BigUint &lhs, const BigUint &rhs) {
    return lhs.compareTo(rhs) > 0;
}

bool operator<=(const BigUint &lhs, const BigUint &rhs) {
    return lhs.compareTo(rhs) <= 0;
}

bool operator>=(const BigUint &lhs, const BigUint &rhs) {
    return lhs.compareTo(rhs) >= 0;
}

bool operator!=(const BigUint &lhs, const BigUint &rhs) {
    return lhs.compareTo(rhs) != 0;
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


int BigUint::compareTo(const BigUint &other) const{
    if (data.size() != other.data.size()) {
        return (data.size() > other.data.size() ? 1 : -1);
    }

    for (auto lhs_iter = data.rbegin(), rhs_iter = other.data.rbegin();
         lhs_iter != data.rend() && rhs_iter != other.data.rend();
         lhs_iter++, rhs_iter++) {
        if (*lhs_iter != *rhs_iter) {
            return (*lhs_iter > *rhs_iter ? 1 : -1);
        }
    }
    return 0;
}





void divMod(BigUint lhs, BigUint rhs, BigUint &div, BigUint &mod) {
    if(rhs == 0){
        throw exception();
    }
    BigUint z = 1;
    int k = 0;
    while(lhs >= rhs){
        rhs <<= 1;
        z <<= 1;
        k++;
    }

    while(k > 0){
        rhs >>= 1;
        z >>= 1;
        k--;

        limb_t l = 0, r = BigUint::base, x = 0;
        while(l <= r){
            limb_t m = l + (r-l)/2;
            if(lhs >= rhs*m){
                x = m;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        lhs = lhs - rhs * x;
        div = div + z * x;
    }
    mod = lhs;
}

BigUint operator/(const BigUint &lhs, const BigUint &rhs) {
    BigUint div, mod;
    divMod(lhs, rhs, div, mod);
    return div;
}

BigUint operator%(const BigUint &lhs, const BigUint &rhs) {
    BigUint div, mod;
    divMod(lhs, rhs, div, mod);
    return mod;
}

void BigUint::add(const BigUint &lhs, const BigUint &rhs) {
    data.resize(std::max(lhs.data.size(), rhs.data.size()) + 1);
    auto lhs_iter = lhs.data.begin(), rhs_iter = rhs.data.begin();
    limb_t carry = 0;
    size_t tail = 0;
    while (carry > 0 || lhs_iter != lhs.data.end() || rhs_iter != rhs.data.end()) {
        limb_t digit_sum = (lhs_iter != lhs.data.end() ? *lhs_iter : 0) +
                         (rhs_iter != rhs.data.end() ? *rhs_iter : 0) +
                         carry;

        data[tail++] = digit_sum % BigUint::base;
        carry = digit_sum / BigUint::base;

        if (lhs_iter != lhs.data.end())lhs_iter++;
        if (rhs_iter != rhs.data.end())rhs_iter++;
    }
    removeZeros();
}

void BigUint::substract(const BigUint &lhs, const BigUint &rhs) {
    if (lhs < rhs) {
        BigUint(0);
    }
    data.clear();
    auto lhs_iter = lhs.data.begin(), rhs_iter = rhs.data.begin();
    limb_t need = 0;
    while (lhs_iter != lhs.data.end()) {
        auto rhs_digit = (rhs_iter != rhs.data.end() ? *rhs_iter : 0);

        limb_t next_need = static_cast<limb_t>(*lhs_iter < rhs_digit + need);
        limb_t next_digit = BigUint::base * next_need + *lhs_iter - rhs_digit - need;
        data.push_back(next_digit);

        need = next_need;

        lhs_iter++;
        if (rhs_iter != rhs.data.end()) {
            rhs_iter++;
        }
    }
    removeZeros();
}

void BigUint::multiply(const BigUint &lhs, const BigUint &rhs) {
    data.resize(lhs.data.size() + rhs.data.size());
    for (std::size_t i = 0; i < lhs.data.size(); i++) {
        limb_t carry = 0;
        for (std::size_t j = 0; carry || j < rhs.data.size(); j++) {
            limb_t cur = data[i + j] + carry + lhs.data[i] * (j < rhs.data.size() ? rhs.data[j] : 0);
            data[i + j] = cur % BigUint::base;
            carry = cur / BigUint::base;
        }
    }
    removeZeros();
}

BigUint operator*(const BigUint &lhs, const BigUint &rhs) {
    BigUint ans;
    ans.multiply(lhs, rhs);
    return ans;
}

BigUint operator+(const BigUint &lhs, const BigUint &rhs) {
    BigUint ans;
    ans.add(lhs, rhs);
    return ans;
}

BigUint operator-(const BigUint &lhs, const BigUint &rhs) {
    BigUint ans;
    ans.substract(lhs, rhs);
    return ans;
}

std::ostream &operator<<(std::ostream &os, const BigUint &num) {
    std::copy(num.data.rbegin(), num.data.rend(), std::ostream_iterator<limb_t>(os, ""));
}

bool BigUint::isZero() const {
    return data.size() == 1 && data.front() == 0;
}

