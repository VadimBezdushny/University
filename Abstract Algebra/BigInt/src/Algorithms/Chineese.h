//
// Created by heimdall on 01.11.18.
//

#ifndef BIGINT_PROJECT_CHINEESE_H
#define BIGINT_PROJECT_CHINEESE_H

#include "BigInt/BigInt.h"
#include "Ring.h"
namespace Algorithms {
    BigInt sqrt(BigInt num) {
        if(num == 0) return BigInt(0);

        BigInt curr = BigInt(1), next;
        curr <<= (num.mag.data.size() + 1/2);// TODO: FIX
        int k = 0;
        while(true){
            next = (curr + num/curr) / 2;
            if(next >= curr){
                return curr;
            }
            curr = next;
        }
    }

    BigInt pow(BigInt base, BigInt power) {
        BigInt res = 1;
        while(power > 0){
            if(power % 2 == 1){
                res = res * base;
            }
            base = base * base;
            power = power / 2;
        }
        return res;
    }

    BigInt chineese(vector<pair<BigInt, BigInt>> nums) {
        size_t n = nums.size();

        vector<vector<BigInt>> rev(n, vector<BigInt> (n, BigInt(0)));
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                rev[i][j] = Ring(nums[j].second).inverse(nums[i].second);
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
