//
// Created by heimdall on 01.11.18.
//

//
// Created by heimdall on 25.10.18.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Algorithms/Algorithms.h"
#include "BigInt/BigInt.h"

using testing::Eq;

TEST(NormMod, NormMod_1_Test) {
    for (int i = 0; i < 20; i++) {
        BigInt x, y, d;
        d = Algo::gcdex(84, 33, x, y);
        ASSERT_EQ(84 * x + 33 * y, d);
    }
}

TEST(NormMod, NormMod_2_Test) {
    ASSERT_EQ(Algo::inverseMod(34795381, 226339651), BigInt(38572232));
}

TEST(Chineese, Chineese_Chineese1_Test) {
    vector<pair<BigInt, BigInt>> v = {{134972356,    226339651},
                                      {122670865,    226336049},
                                      {187543924341, 316767252433},
                                      {1311433,      2801863},
                                      {1561821,      1632523}};
    BigInt ans = Algo::chineese(v);
    vector<BigInt> x(v.size());
    vector<BigInt> y(v.size());
    for (int i = 0; i < x.size(); i++) {
        x[i] = ans % v[i].second;
        y[i] = v[i].first;
    }
    ASSERT_EQ(x, y);
}

TEST(Chineese, Chineese_Chineese4_Test) {
    vector<pair<BigInt, BigInt>> v = {{134972356, 226339651},
                                      {122670865, 226336049}};
    BigInt ans = Algo::chineese(v);
    vector<BigInt> x(v.size());
    vector<BigInt> y(v.size());
    for (int i = 0; i < x.size(); i++) {
        x[i] = ans % v[i].second;
        y[i] = v[i].first;
    }
    ASSERT_EQ(x, y);
}


TEST(Chineese, Chineese_Chineese2_Test) {
    vector<pair<BigInt, BigInt>> v = {{3, 5},
                                      {2, 7},
                                      {2, 3}};
    BigInt ans = Algo::chineese(v);
    vector<BigInt> x(v.size());
    vector<BigInt> y(v.size());
    for (int i = 0; i < x.size(); i++) {
        x[i] = ans % v[i].second;
        y[i] = v[i].first;
    }
    ASSERT_EQ(x, y);
}

TEST(Chineese, Chineese_Chineese3_Test) {
    vector<pair<BigInt, BigInt>> v = {{2, 5},
                                      {3, 7}};
    BigInt tens("17");
    ASSERT_EQ(tens, Algo::chineese(v));
}


TEST(Legendre, Legendre_test_1) {
    ASSERT_EQ(Algo::legendre_symbol(18, 31), 1);
    ASSERT_EQ(Algo::legendre_symbol(83, 17), 1);

    ASSERT_EQ(Algo::legendre_symbol(8, 61), -1);
    ASSERT_EQ(Algo::legendre_symbol(20, 107), -1);

    ASSERT_EQ(Algo::legendre_symbol(25, 5), 0);
}


TEST(IsPrimeFermat, FERMAT_1) {
    ASSERT_TRUE(Algo::isPrimeFermat(1023949, 5));
    ASSERT_TRUE(Algo::isPrimeFermat(846739, 10));

    ASSERT_FALSE(Algo::isPrimeFermat(867017552311, 5));
    ASSERT_FALSE(Algo::isPrimeFermat(867017552311, 20));

    const int MAX = 10000;
    vector<int> pr, lp;
    Algo::sieve(MAX, pr, lp);
    for (int i = MAX - 100; i < MAX; i++) {
        EXPECT_EQ(lp[i] == i, Algo::isPrimeFermat(i, 10)) << " num:" << i;
    }
    ASSERT_TRUE(Algo::isPrimeFermat(BigInt("340561"), 5)); // CARMICHAEL
}

TEST(IsPrimeMillerRabin, MILLER_RABIN_1) {
    ASSERT_TRUE(Algo::isPrimeMillerRabin(1023949, 5));
    ASSERT_TRUE(Algo::isPrimeMillerRabin(846739, 10));

    ASSERT_FALSE(Algo::isPrimeMillerRabin(867017552311, 5));
    ASSERT_FALSE(Algo::isPrimeMillerRabin(867017552311, 20));

    const int MAX = 10000;
    vector<int> pr, lp;
    Algo::sieve(MAX, pr, lp);
    for (int i = MAX - 100; i < MAX; i++) {
        EXPECT_EQ(lp[i] == i, Algo::isPrimeMillerRabin(i, 10)) << " num:" << i;
    }

    ASSERT_TRUE(Algo::isPrimeFermat(BigInt("340561"), 5)); // CARMICHAEL
}

TEST(IsPrime, 1) {
    const int MAX = 1'000'000;
    vector<int> pr, lp;
    Algo::sieve(MAX, pr, lp);
    for (int i = MAX - 100; i < MAX; i++) {
        ASSERT_EQ(lp[i] == i, Algo::isPrime(i)) << " num:" << i;
    }
}

TEST(logMod, 1) {
    BigInt base = 3, ans = 13, mod = 17;
    ASSERT_EQ(ans, Algo::powMod(base, Algo::logMod(base, ans, mod), mod));
}

TEST(logMod, 2) {
    BigInt base = 5, ans = 34, mod = 91;
    ASSERT_EQ(ans, Algo::powMod(base, Algo::logMod(base, ans, mod), mod));
}


TEST(factorize, 1){
    BigInt num("210"), res = 1;
    map<BigInt, int> f = Algo::factorize(num);
    string str;
    for(auto it:f) res = res * Algo::pow(it.first, it.second), str += it.first.to_string() + ":" + std::to_string(it.second) + " ";
    ASSERT_EQ(num, res) << res;
}

TEST(factorize, 2){
    BigInt num("155861"), res = 1;
    map<BigInt, int> f = Algo::factorize(num);
    string str;
    for(auto it:f) res = res * Algo::pow(it.first, it.second), str += it.first.to_string() + ":" + std::to_string(it.second) + " ";
    ASSERT_EQ(num, res) << res;
}
TEST(factorize, 3){
    BigInt num("299486755639"), res = 1;
    map<BigInt, int> f = Algo::factorize(num);
    string str;
    for(auto it:f) res = res * Algo::pow(it.first, it.second), str += it.first.to_string() + ":" + std::to_string(it.second) + " ";
    ASSERT_EQ(num, res) << res;
}

TEST(factorize, 4){
    BigInt num = BigInt("38696309") * BigInt("65039389"), res = 1;
    map<BigInt, int> f = Algo::factorize(num);
    string str;
    for(auto it:f) res = res * Algo::pow(it.first, it.second), str += it.first.to_string() + ":" + std::to_string(it.second) + " ";
    ASSERT_EQ(num, res) << res;
}


TEST(factorize, 5){
    BigInt num = BigInt("144883") * BigInt("2949377") * BigInt("17") * BigInt("19"), res = 1;
    map<BigInt, int> f = Algo::factorize(num);
    string str;
    for(auto it:f) res = res * Algo::pow(it.first, it.second), str += it.first.to_string() + ":" + std::to_string(it.second) + " ";
    ASSERT_EQ(num, res) << res;
}


TEST(factorize, 6){
    BigInt num = BigInt("224287411") * BigInt("224287411") * BigInt("226013497") * BigInt("31"), res = 1;
    map<BigInt, int> f = Algo::factorize(num);
    string str;
    for(auto it:f) res = res * Algo::pow(it.first, it.second), str += it.first.to_string() + ":" + std::to_string(it.second) + " ";
    ASSERT_EQ(num, res) << res;
}

