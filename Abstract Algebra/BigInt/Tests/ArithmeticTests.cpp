//
// Created by heimdall on 25.10.18.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "BigInt.h"

using testing::Eq;

TEST(BigIntAdd, ADD_TEST_1){
    BigInt a(4), b(998), res(1002);
    ASSERT_THAT(res, a+b);
}

TEST(BigIntAdd, ADD_TEST_2){
    ASSERT_THAT(
            BigInt("1378428734234174513415267865") +
            BigInt("16843385785723684354957368763458293"),
            BigInt("16843387164152418589131882178726158"));
}

TEST(BigIntAdd, ADD_TEST_3){
    ASSERT_THAT(
            BigInt("1831") +
            BigInt("-142"),
            BigInt("1689"));
}
TEST(BigIntAdd, ADD_TEST_4){
    ASSERT_THAT(
            BigInt("-1831") +
            BigInt("142"),
            BigInt("-1689"));
}

TEST(BigIntAdd, ADD_TEST_5){
    ASSERT_THAT(
            BigInt("-1831") +
            BigInt("-142"),
            BigInt("-1973"));
}

TEST(BigIntAdd, ADD_TEST_6){
    ASSERT_THAT(
            BigInt("-142") +
            BigInt("1831"),
            BigInt("1689"));
}

TEST(BigIntCompare, COMPARE_TEST_1){
    ASSERT_THAT(compare(BigInt(123), BigInt(422)), -1);
}
TEST(BigIntCompare, COMPARE_TEST_2){
    ASSERT_THAT(compare(BigInt(92934283), BigInt(92934283)), 0);
}

TEST(BigIntCompare, COMPARE_TEST_3){
    ASSERT_THAT(compare(BigInt(92934284), BigInt(92934283)), 1);
}

TEST(BigIntCompare, COMPARE_TEST_4){
    ASSERT_THAT(compare(BigInt(314), BigInt(-314)), 1);
}

TEST(BigIntCompare, COMPARE_TEST_5){
    ASSERT_THAT(compare(BigInt(314), BigInt(314)), 0);
}

TEST(BigIntCompare, COMPARE_TEST_6){
    ASSERT_THAT(compare(BigInt(-314), BigInt(314)), -1);
}

TEST(BigIntCompare, COMPARE_TEST_7){
    ASSERT_THAT(compare(BigInt(0), BigInt(0)), 0);
}