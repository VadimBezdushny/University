//
// Created by heimdall on 24.10.18.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "BigInt/BigInt.h"

using testing::Eq;

TEST(BigIntTest, CONSTRUCTOR_TEST_POS1) {
    BigUint num("123");
    ASSERT_THAT(num.data, ::testing::ElementsAre(3, 2, 1));
}

TEST(BigIntTest, CONSTRUCTOR_TEST_POS2) {
    BigInt num("123857363");
    ASSERT_EQ(num.sign, 1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(3, 6, 3, 7, 5, 8, 3, 2, 1));
}

TEST(BigIntTest, CONSTRUCTOR_TEST_NEG) {
    BigInt num("-143");
    ASSERT_EQ(num.sign, -1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(3, 4, 1));
}

TEST(BigIntTest, CONSTRUCTOR_TEST_ZERO1) {
    BigInt num("0");
    ASSERT_EQ(num.sign, 1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(0));
}

TEST(BigIntTest, CONSTRUCTOR_TEST_ZERO2) {
    BigInt num("-0");
    ASSERT_EQ(num.sign, 1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(0));
}

TEST(BigIntTest, CONSTRUCTOR_TEST_ZERO3) {
    BigInt num("+0");
    ASSERT_EQ(num.sign, 1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(0));
}

TEST(BigIntTest, CONSTRUCTOR_TEST_ZERO4) {
    BigInt num("+000");
    ASSERT_EQ(num.sign, 1);
    ASSERT_THAT(num.mag.data, ::testing::ElementsAre(0));
}

TEST(BigIntTest, CONSTRUCTOR_TEST_ZERO5) {
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