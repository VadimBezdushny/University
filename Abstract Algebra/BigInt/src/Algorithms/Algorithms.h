//
// Created by heimdall on 08.11.18.
//

#ifndef BIGINT_PROJECT_ALGORITHMS_H
#define BIGINT_PROJECT_ALGORITHMS_H


#include "BigInt/BigInt.h"


namespace Algo {
    BigInt inverseMod(BigInt num, BigInt mod);

    BigInt powMod(BigInt base, BigInt power, BigInt mod);

    BigInt normMod(BigInt num, BigInt mod);

    BigInt addMod(BigInt lhs, BigInt rhs, BigInt mod);

    BigInt subMod(BigInt lhs, BigInt rhs, BigInt mod);

    BigInt mulMod(BigInt lhs, BigInt rhs, BigInt mod);

    BigInt divMod(BigInt lhs, BigInt rhs, BigInt mod);


    BigInt sqrt(BigInt num);

    BigInt pow(BigInt base, BigInt power);

    BigInt chineese(vector<pair<BigInt, BigInt>> nums);

    BigInt gcd(BigInt a, BigInt b);

    BigInt gcdex(BigInt a, BigInt b, BigInt &x, BigInt &y);

    void sieve(int num, std::vector<int> &primes, std::vector<int> &least_prime);

    BigInt abs(BigInt num);

    int legendre_symbol(BigInt a, BigInt p);

    int Jacobi_symbol(BigInt a, BigInt b);

    bool isPrimeFermat(BigInt num, int num_rounds);
    bool isPrimeMillerRabin(BigInt num, int num_rounds);

    BigInt _pollardRhoNextNum(BigInt num);

    BigInt pollardRhoIteration(BigInt num);

    std::vector<std::pair<BigInt, int>> factorize(BigInt num, int max_dummy_div = 0);
}


#endif //BIGINT_PROJECT_ALGORITHMS_H