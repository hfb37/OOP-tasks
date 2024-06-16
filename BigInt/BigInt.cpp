#include <BigInt.h>
#include <iostream>

void bigint::operator+=(const bigint &other) {
    for (int i = 0; i < size; i++) {
        digits[i] += other.digits[i];
    }

    for (int i = 0; i < size - 1; i++) {
        if (digits[i] >= base) {
            digits[i] -= base;
            digits[i + 1]++;
        }
    }
}

void bigint::operator+=(const long long int other) {
    *this += bigint(other);
}

bigint bigint::operator+(const bigint& other) {
    bigint n(*this);
    n += other;
    return n;
}

bigint bigint::operator+(const long long other) {
    return *this + bigint(other);
}

bigint &bigint::operator++() {
    *this += 1;
    return *this;
}

void bigint::operator-=(const bigint &other) {
    for (int i = 0; i < size; i++) {
        digits[i] -= other.digits[i];
    }

    for (int i = 0; i < size - 1; i++) {
        if (digits[i] < 0) {
            digits[i] += base;
            digits[i + 1]--;
        }
    }
}

void bigint::operator-=(const long long other) {
    *this -= bigint(other);
}

bigint bigint::operator-(const bigint &other) {
    bigint n(*this);
    n -= other;
    return n;
}

bigint bigint::operator-(const long long other) {
    return *this + bigint(other);
}

bigint &bigint::operator--() {
    *this -= 1;
    return *this;
}

bigint bigint::operator*(const bigint& other) {
    bigint result;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            result.digits[i + j] += digits[i] * other.digits[j];
        }
    }

    for (int i = 0; i < size - 1; i++) {
        result.digits[i + 1] += result.digits[i] / base;
        result.digits[i] %= base;
    }

    return result;
}

bigint bigint::operator*(const long long other) {
    return *this * bigint(other);
}

void bigint::operator*=(const bigint& other) {
    *this = *this * other;
}

void bigint::operator/=(long long x) {
    for (int i = size - 1; i >= 0; i--) {
        if (i) {
            digits[i - 1] += (digits[i] % x) * base;
        }

        digits[i] /= x;
    }
}

bigint bigint::operator/(long long x) {
    bigint n(*this);
    n /= x;
    return n;
}

long long bigint::operator%(long long x) {
    bigint n = *this - (*this / x) * x;
    return n.digits[0];
}

bool bigint::operator==(const bigint& number) {
    for (int i = 0; i < size; ++i) {
        if (digits[i] != number.digits[i]) return false;
    }
    return true;
}

bool bigint::operator==(const long long number) {
    return (*this == bigint(number));
}

bool bigint::operator!=(const bigint& number) {
    return !(*this == number);
}

bool bigint::operator!=(const long long number){
    return !(*this == number);
}

bool bigint::operator>(const long long number) {
    bigint x(number);
    if (!(*this == x)) {
        for (int i = size; i >= 0; --i) {
            if (digits[i] > x.digits[i]) return true;
        }
    }
    return false;
}

bool bigint::operator<(const long long number) {
    return !(*this == number) && !(*this > number);
}

bool bigint::operator>=(const long long number) {
    return *this > number || *this == number;
}

bool bigint::operator<=(const long long number) {
    return *this < number || *this == number;
}
