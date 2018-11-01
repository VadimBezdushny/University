//
// Created by heimdall on 01.11.18.
//

#ifndef BIGINT_PROJECT_CHINEESE_H
#define BIGINT_PROJECT_CHINEESE_H

#include "BigInt/BigInt.h"

class Ring {
public:
    BigInt mod;
    Ring(BigInt mod):mod(mod){}

    BigInt norm(BigInt num){
        if(num >= 0){
            return num % mod;
        }else{
            return (num + (-num/mod + 2) * mod) % mod;
        }
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
namespace Algorithms {
    BigInt chineese(vector<pair<BigInt, BigInt>> nums) {
        size_t n = nums.size();

        vector<vector<BigInt>> rev(n, vector<BigInt> (n, BigInt(0)));
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                rev[i][j] = Ring(nums[j].second).inverse(nums[i].second);
                std::cout << rev[i][j] << " " <<
                nums[i].second << " " << nums[j].second << std::endl;
            }
        }
        vector<BigInt> x(n);
        BigInt ans;
        BigInt coef = 1;
        for(int i = 0; i < n; i++){
            Ring p(nums[i].second);
            x[i] = nums[i].first;
            for(int j = 0; j < i; j++){
                x[i] = rev[j][i] * (x[i] - x[j]);
                x[i] = p.norm(x[i]);
            }
        }
        for(int i = 0; i < n; i++){
            ans = ans + x[i]*coef;
            coef = coef * nums[i].second;
        }
        ans = Ring(coef).norm(ans);
        return ans;
    }
}


#endif //BIGINT_PROJECT_CHINEESE_H
