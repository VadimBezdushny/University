//
// Created by heimdall on 24.10.18.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "BigInt/BigInt.h"

using testing::Eq;

TEST(BigIntInit, 1) {
    BigUint num("123");
    ASSERT_THAT(num.data, ::testing::ElementsAre(123));
}

TEST(BigIntInit, 2) {
    BigInt num("123857363");
    ASSERT_EQ(num.sign, 1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(123857363));
}
TEST(BigIntInit, 3) {
    BigInt num("123857 363456789");
    ASSERT_EQ(num.sign, 1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(363456789, 123857));
}

TEST(BigIntInit, 4) {
    BigInt num("-143");
    ASSERT_EQ(num.sign, -1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(143));
}

TEST(BigIntInit, 5) {
    BigInt num("0");
    ASSERT_EQ(num.sign, 1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(0));
}

TEST(BigIntInit, 6) {
    BigInt num("-0");
    ASSERT_EQ(num.sign, 1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(0));
}

TEST(BigIntInit, 7) {
    BigInt num("+0");
    ASSERT_EQ(num.sign, 1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(0));
}

TEST(BigIntInit, 8) {
    BigInt num("+000");
    ASSERT_EQ(num.sign, 1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(0));
}

TEST(BigIntInit, 9) {
    BigInt num("-000");
    ASSERT_EQ(num.sign, 1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(0));
}


//
//TEST_F(BigIntTest, TO_STRING_0){
//    num->sign = 0;
//    num->data = {0};
//    EXPECT_EQ(num->to_string(), "0");
//}
//
//TEST_F(BigIntTest, TO_STRING_mBig){
//    num->sign = -1;
//    num->data = {2,1,6};
//    EXPECT_EQ(num->to_string(), "-612");
//}

//TEST_F(BigInt, ZERO_ON_INIT){
//
//}