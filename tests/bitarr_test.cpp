#include <gtest/gtest.h>
#include <BitArray.h>

TEST(bitarr_test, string) {
    BitArray a(5, 24351324868);
    EXPECT_EQ(a.to_string(), "0000010110101011011100111011101011000100");
}

TEST(bitarr_test, equal) {
    BitArray a(1, 33);
    BitArray b(1, 33);
    BitArray c(2, 33);
    BitArray d(1, 30);
    EXPECT_EQ((a == b), true);
    EXPECT_EQ((a == c), false);
    EXPECT_EQ((a == d), false);
    EXPECT_EQ((a != b), false);
    EXPECT_EQ((a != c), true);
    EXPECT_EQ((a != d), true);
}

TEST(bitarr_test, swap) {
    BitArray a(3, 4324);
    BitArray b(1, 43);
    BitArray c(a);
    BitArray d(b);

    a.swap(b);
    EXPECT_EQ(a, d);
    EXPECT_EQ(b, c);
}

TEST(bitarr_test, resize) {
    BitArray a(3, 9491);
    a.resize(4);
    BitArray b(4, 9491);
    EXPECT_EQ(a, b);
    a.resize(2);
    BitArray c(2, 9491);
    EXPECT_EQ(a, c);
}

TEST(bitarr_test, clear) {
    BitArray a(5, 13254);
    a.clear();
    BitArray b;
    EXPECT_EQ(a, b);
}

TEST(bitarr_test, push_back) {
    BitArray a(1, 255);
    a.push_back(1);
    BitArray b(2, 511);
    EXPECT_EQ(a, b);
}

TEST(bitarr_test, oper_and) {
    BitArray a(2, 389); // 0000000110000101
    BitArray b(2, 424); // 0000000110101000
    BitArray c(3, 652); // 000000000000001010001100
    BitArray d(3, 593); // 000000000000001001010001
    a &= b;
    EXPECT_EQ(a.to_string(), "0000000110000000");
    a &= c;
    EXPECT_EQ(a.to_string(), "0000000110000000");
    BitArray e = c & d;
    EXPECT_EQ(e.to_string(), "000000000000001000000000");
}

TEST(bitarr_test, oper_or) {
    BitArray a(2, 389); // 0000000110000101
    BitArray b(2, 424); // 0000000110101000
    BitArray c(3, 652); // 000000000000001010001100
    BitArray d(3, 593); // 000000000000001001010001
    a |= b;
    EXPECT_EQ(a.to_string(), "0000000110101101");
    a |= c;
    EXPECT_EQ(a.to_string(), "0000000110101101");
    BitArray e = c | d;
    EXPECT_EQ(e.to_string(), "000000000000001011011101");
}

TEST(bitarr_test, oper_xor) {
    BitArray a(2, 389); // 0000000110000101
    BitArray b(2, 424); // 0000000110101000
    BitArray c(3, 652); // 000000000000001010001100
    BitArray d(3, 593); // 000000000000001001010001
    a ^= b;
    EXPECT_EQ(a.to_string(), "0000000000101101");
    a ^= c;
    EXPECT_EQ(a.to_string(), "0000000000101101");
    BitArray e = c ^ d;
    EXPECT_EQ(e.to_string(), "000000000000000011011101");
}

TEST(bitarr_test, oper_move_bit) {
    BitArray a(1, 55); // 00110111
    a = a >> 1;
    EXPECT_EQ(a.to_string(), "00011011");
    a <<= 2;
    EXPECT_EQ(a.to_string(), "01101100");
    a = a << 5;
    EXPECT_EQ(a.to_string(), "10000000");
    a >>= 7;
    EXPECT_EQ(a.to_string(), "00000001");
}

TEST(bitarr_test, set) {
    BitArray a(2); // 0000000000000000
    a.set(3);
    a.set(5);
    EXPECT_EQ(a.to_string(), "0000000000101000");
    a.set(5, 0);
    EXPECT_EQ(a.to_string(), "0000000000001000");
    a.set();
    EXPECT_EQ(a.to_string(), "1111111111111111");
}

TEST(bitarr_test, reset) {
    BitArray a(2); // 0000000000000000
    a.set();
    a.reset(3);
    a.reset(5);
    EXPECT_EQ(a.to_string(), "1111111111010111");
    a.reset();
    EXPECT_EQ(a.to_string(), "0000000000000000");
}

TEST(bitarr_test, any) {
    BitArray a(1); // 00000000
    EXPECT_EQ(a.any(), false);
    a.set(7);
    EXPECT_EQ(a.any(), true);
}

TEST(bitarr_test, none) {
    BitArray a(1); // 00000000
    EXPECT_EQ(a.none(), true);
    a.set(7);
    EXPECT_EQ(a.none(), false);
}

TEST(bitarr_test, inversion) {
    BitArray a(1); // 00000000
    a = ~a;
    EXPECT_EQ(a.to_string(), "11111111");
    BitArray b(1, 33);
    b = ~b;
    EXPECT_EQ(b.to_string(), "11011110");
}

TEST(bitarr_test, count) {
    BitArray a(1); // 00000000
    EXPECT_EQ(a.count(), 0);
    a.set();
    EXPECT_EQ(a.count(), 8);
    a.reset(3);
    a.reset(7);
    EXPECT_EQ(a.count(), 6);
}

TEST(bitarr_test, oper_get_bit) {
    BitArray a(1, 55); // 00110111
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[7], 0);
}

TEST(bitarr_test, empty) {
    BitArray a;
    BitArray b(1);
    EXPECT_EQ(a.empty(), true);
    EXPECT_EQ(b.empty(), false);
}

