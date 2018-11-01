//
// Created by heimdall on 01.11.18.
//

//
// Created by heimdall on 25.10.18.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Algorithms/Chineese.h"

using testing::Eq;

TEST(NormMod, NormMod_1_Test){
    Ring r = Ring(BigInt(7));
    for(int i = 0; i < 20; i++){
        BigInt x,y, d;
        d = r.gcdex(84, 33, x,y);
        ASSERT_EQ(84*x + 33*y, d);
    }
}

TEST(NormMod, NormMod_2_Test){
    Ring r = Ring(BigInt(226339651));
    ASSERT_EQ(r.inverse(34795381), BigInt(38572232));
}

TEST(Chineese, Chineese_Chineese1_Test){
    vector<pair<BigInt, BigInt>> v = {{134972356,226339651},{122670865,226336049},
                                      {187543924341,316767252433}, {1311433,2801863},
                                      {1561821,1632523}};
    BigInt ans = Algorithms::chineese(v);
    vector<BigInt> x(v.size());
    vector<BigInt> y(v.size());
    for(int i = 0 ; i < x.size(); i++){
        x[i] = ans % v[i].second;
        y[i] = v[i].first;
    }
    ASSERT_EQ(x, y);
}
TEST(Chineese, Chineese_Chineese4_Test){
    vector<pair<BigInt, BigInt>> v = {{134972356,226339651},{122670865,226336049}};
    BigInt ans = Algorithms::chineese(v);
    vector<BigInt> x(v.size());
    vector<BigInt> y(v.size());
    for(int i = 0 ; i < x.size(); i++){
        x[i] = ans % v[i].second;
        y[i] = v[i].first;
    }
    ASSERT_EQ(x, y);
}


TEST(Chineese, Chineese_Chineese2_Test){
    vector<pair<BigInt, BigInt>> v = {{3,5},{2,7},{2,3}};
    BigInt ans = Algorithms::chineese(v);
    vector<BigInt> x(v.size());
    vector<BigInt> y(v.size());
    for(int i = 0 ; i < x.size(); i++){
        x[i] = ans % v[i].second;
        y[i] = v[i].first;
    }
    ASSERT_EQ(x, y);
}

TEST(Chineese, Chineese_Chineese3_Test){
    vector<pair<BigInt, BigInt>> v = {{2,5},{3,7}};
    BigInt tens("17");
    ASSERT_EQ(tens, Algorithms::chineese(v));
}