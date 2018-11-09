//
// Created by heimdall on 08.11.18.
//

#include <cmath>
#include <set>
#include <map>
#include "Algorithms.h"

namespace Algo{
    BigInt sqrt(BigInt num) {
        if (num < 0) throw exception();
        if (num == 0) return BigInt(0);

        BigInt curr = BigInt(1), next;
        curr <<= (num.mag.data.size() + 1 / 2);// TODO: FIX
        int k = 0;
        while (true) {
            next = (curr + num / curr) / 2;
            if (next >= curr) {
                return curr;
            }
            curr = next;
        }
    }

    BigInt pow(BigInt base, BigInt power) {
        BigInt res = 1;
        while (power > 0) {
            if (power % 2 == 1) {
                res = res * base;
            }
            base = base * base;
            power = power / 2;
        }
        return res;
    }

    BigInt chineese(vector<pair<BigInt, BigInt>> nums) {
        size_t n = nums.size();

        vector<vector<BigInt>> rev(n, vector<BigInt>(n, BigInt(0)));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                rev[i][j] = inverseMod(nums[i].second, nums[j].second);
            }
        }
        vector<BigInt> x(n);
        BigInt ans;
        BigInt coef = 1;
        for (int i = 0; i < n; i++) {
            x[i] = nums[i].first;
            for (int j = 0; j < i; j++) {
                x[i] = rev[j][i] * (x[i] - x[j]);
                x[i] = normMod(x[i], nums[i].second);
            }
        }
        for (int i = 0; i < n; i++) {
            ans = ans + x[i] * coef;
            coef = coef * nums[i].second;
        }
        ans = normMod(ans, coef);
        return ans;
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

    void sieve(int num, std::vector<int> &primes, std::vector<int> &least_prime) {
        /*
         * least_prime[i] - least prime divisor of i
         * primes[i] - i-th prime number
         */

        least_prime.assign(num + 1, 0);
        primes.clear();

        for (int i = 2; i <= num; i++) {
            if (least_prime[i] == 0) {
                primes.push_back(i);
                least_prime[i] = i;
            }
            for (int j = 0; j < (int) primes.size() && primes[j] <= least_prime[i] && i * primes[j] <= num; j++) {
                least_prime[i * primes[j]] = primes[j];
            }
        }
    }

    vector<int> getFirstKprimes(int k){
        vector<int> pr, lp;
        sieve(static_cast<int>(2*k * (log(k) + 1)), pr, lp);
        pr.resize(k);
        return pr;
    }

    BigInt abs(BigInt num) {
        return ((num > 0) ? num : -num);
    }

    int Jacobi_symbol(BigInt a, BigInt b) {
        if (a <= 0 || b % 2 == 0) return 0;
        int ans = 1;
        if (a < 0) {
            a = -a;
            if (b % 4 == 3) {
                ans *= -1;
            }
        }
        do {
            do {
                a = a / 2;
                if (abs(b % 8 - 4) == 1)
                    ans *= -1;
            } while (a % 2 == 0);

            std::swap(a, b);
            if (a % 4 == 3 && b % 4 == 3) ans *= -1;
            a = a % b;
        } while (a != 0);
        if (b == 1)
            return ans;
        else
            return 0;
    }

    int legendre_symbol(BigInt a, BigInt p) {
        int ans = int(powMod(a, (p - 1) / 2, p));
        if(ans > 1) // ans == p - 1
            return -1;
        else
            return ans;
    }

    BigInt _pollardRhoNextNum(BigInt num, BigInt mod) {
        return BigInt();
    }

    BigInt pollardRhoIteration(BigInt num) {
        /*
         * returns prime dividor of num
         */
        BigInt walker = 2, runner = 2, div = 1;
        BigInt ring(num);
        while (div == 1) {
            walker = _pollardRhoNextNum(walker, ring);
            runner = _pollardRhoNextNum(_pollardRhoNextNum(runner, ring), ring);
            div = gcd(abs(walker - runner), num);
        }
        if (div == num) {
            return 1;
        } else {
            return div;
        }


    }

    vector<int> getFirstPrimesLessK(BigInt num);


    bool isPrimeDummy(BigInt num, int num_primes = -1){
        vector<int> primes, least_prime;

        if(num_primes > 0)
            primes = getFirstKprimes(num_primes);
        else
            sieve(int(sqrt(num)+1), primes, least_prime);

        for(auto prime_num:primes)
            if(num % prime_num == 0)
                return false;

        return true;
    }


    bool isPrimeFermat(BigInt num, int num_rounds) {
        vector<int> primes = getFirstKprimes(num_rounds);
        for(auto witness:primes){
            if(witness + 2 > num) break;
            if(powMod(witness, num - 1, num) != 1){
                return false;
            }
        }
        return true;
    }

    bool isPrimeMillerRabin(BigInt num, int num_rounds){
        int r = 0;
        BigInt d = num;
        while(d % 2 == 0){
            d = d / 2;
            r++;
        }
        vector<int> primes = getFirstKprimes(num_rounds);
        for(auto witness:primes){
            if(witness + 2 > num) break;
            BigInt x = powMod(witness, num-1, num);
            if(x == 1 || x == num - 1)
                continue;

            for(int i = 1; i < r; i++){
                x = mulMod(x,x,num);
                if(x + 1 == num)
                    continue;
            }
            return false;
        }
        return true;
    }

    std::vector<std::pair<BigInt, int>> factorize(BigInt num, int max_dummy_div) {
        vector<std::pair<BigInt, int>> ans;
        if (max_dummy_div > 0) {
            vector<int> primes, least_prime;
            sieve(max_dummy_div, primes, least_prime);
            for (const auto &prime:primes) {
                int cnt = 0;
                while (num % prime == 0) {
                    num = num / prime;
                    cnt++;
                }
                if (cnt > 0) {
                    ans.emplace_back(prime, cnt);
                }
            }
        }
    }

    BigInt gcd(BigInt a, BigInt b) {
        while (b != 0) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }

    BigInt inverseMod(BigInt num, BigInt mod) {
        BigInt x, y, g;
        g = gcdex(num, mod, x, y);
        if(g != 1){
            throw;
        }
        return normMod(x, mod);
    }

    BigInt powMod(BigInt base, BigInt power, BigInt mod) {
        BigInt res = 1;
        while(power > 0){
            if(power % 2 == 1){
                res = mulMod(res, base, mod);
            }
            base = mulMod(base, base, mod);
            power = power / 2;
        }
        return res;
    }
    BigInt logMod(BigInt base, BigInt ans, BigInt mod){
        // Baby step giant step

        if(gcd(base, mod) != 1) return -1;

        BigInt block_size = sqrt(mod) + 1;

        BigInt giant_step = powMod(base, block_size, mod);

        // Giant step
        std::map<BigInt, BigInt> giant_steps;
        BigInt curr = giant_step;
        for(BigInt i = block_size; i < mod; i = i + block_size){
            if(!giant_steps.count(curr))
                giant_steps[curr] = i;
            curr = mulMod(curr, giant_step, mod);
        }

        // Small step
        curr = ans;
        for(BigInt i = 0; i < block_size; i = i + 1){
            if(giant_steps.count(curr)){
                BigInt ans = giant_steps[curr] * block_size - i;
                if(ans < mod)
                    return ans;
            }
            curr = mulMod(curr, base, mod);
        }
        return -1;
    }
    BigInt normMod(BigInt num, BigInt mod) {
        if(num >= 0){
            return num % mod;
        }else{
            return (num % mod + mod) % mod;
        }
    }

    BigInt addMod(BigInt lhs, BigInt rhs, BigInt mod) {
        return normMod(normMod(lhs, mod) + normMod(rhs, mod), mod);
    }

    BigInt subMod(BigInt lhs, BigInt rhs, BigInt mod) {
        return normMod(normMod(lhs, mod) - normMod(rhs, mod), mod);
    }

    BigInt mulMod(BigInt lhs, BigInt rhs, BigInt mod) {
        return normMod(normMod(lhs, mod) * normMod(rhs, mod), mod);
    }

    BigInt divMod(BigInt lhs, BigInt rhs, BigInt mod) {
        return normMod(normMod(lhs, mod) * inverseMod(normMod(rhs, mod), mod), mod);
    }
}