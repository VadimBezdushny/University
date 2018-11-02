//
// Created by heimdall on 02.11.18.
//

#ifndef BIGINT_PROJECT_RING_H
#define BIGINT_PROJECT_RING_H


#include <BigInt/BigInt.h>

class Ring {
public:
    BigInt mod;
    Ring(BigInt mod):mod(mod){}

    BigInt norm(BigInt num){
        if(num >= 0){
            return num % mod;
        }else{
            return (num % mod + mod) % mod;
        }
    }
    BigInt add(BigInt lhs, BigInt rhs){
        return norm(norm(lhs) + norm(rhs));
    }
    BigInt sub(BigInt lhs, BigInt rhs){
        return norm(norm(lhs) - norm(rhs));
    }
    BigInt mul(BigInt lhs, BigInt rhs){
        return norm(norm(lhs) * norm(rhs));
    }
    BigInt div(BigInt lhs, BigInt rhs){
        return norm(norm(lhs) * inverse(norm(rhs)));
    }
    BigInt pow(BigInt base, BigInt power){
        BigInt res = 1;
        while(power > 0){
            if(power % 2 == 1){
                res = mul(res, base);
            }
            base = mul(base, base);
            power = power / 2;
        }
        return res;
    }
    BigInt gcdex(BigInt a, BigInt b, BigInt &x, BigInt &y) {
        if (a == 0) {
            x = 0;
            y = 1;
            return b;
        }
        BigInt x1, y1, d;
        d = gcdex(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }

    BigInt inverse(BigInt num) {
        BigInt x, y, g;
        g = gcdex(num, mod, x, y);
        if(g != 1){
            throw;
        }
        return norm(x);
    }
};


#endif //BIGINT_PROJECT_RING_H
