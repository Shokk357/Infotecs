#include <gtest/gtest.h>
#include "Primes.h"
#include <vector>

TEST(Primes, primes_limited_size_test) {
    Primes a(100);
    ASSERT_EQ(a.size(), 25);
}

TEST(Primes, primes_limited_begin_func_test) {
    Primes a(100);
    ASSERT_EQ(*a.begin(), 2);
}

TEST(Primes, primes_limited_pointer_test) {
    Primes a(100);
    std::vector<uint32_t> testVec = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
                                     83, 89, 97};
    int ch = 0;
    for (Primes::Iterator i = a.begin(); i != a.end(); i++) {
        EXPECT_EQ(*i, testVec[ch]);
        ch++;
    }
}

TEST(Primes, primes_limited_square_operator_test) {
    Primes a(100);
    std::vector<uint32_t> testVec = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
                                     83, 89, 97};
    int ch = 0;
    for (int i = 0; i < a.size(); i++) {
        EXPECT_EQ(a[i], testVec[ch]);
        ch++;
    }
}

TEST(Primes, primes_size_test) {
    Primes a;
    ASSERT_EQ(a.size(), 0);
}

TEST(Primes, primes_begin_func_test) {
    Primes a;
    ASSERT_EQ(*a.begin()++, 2);
}

TEST(Primes, primes_pointer_test) {
    Primes a;
    std::vector<uint32_t> testVec = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
                                     83, 89, 97};
    int ch = 0;
    Primes::Iterator iterator = a.begin();
    for (int i = 0; i < testVec.size(); i++) {
        EXPECT_EQ(*(iterator++), testVec[ch]);
        ch++;
    }
}

TEST(Primes, primes_square_operator_test) {
    Primes a;
    EXPECT_EQ(a[24], 97);
    EXPECT_EQ(a[3], 7);
}

TEST(Primes, primes_exception_test) {
    Primes a(100);
    EXPECT_ANY_THROW(a[25]);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}