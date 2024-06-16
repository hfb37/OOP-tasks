
class bigint {
private:
    static const long long base = 1e9;

    static const long long size = 10;

    long long digits[size]{};

public:
    bigint() {
        for (long long & digit : digits) {
            digit = 0;
        }
    }

    explicit bigint(long long x) {
        for (long long & digit : digits) {
            digit = 0;
        }

        int next = 0;
        while (x) {
            digits[next++] = x % base;
            x /= base;
        }
    }

    bigint(const bigint &other) {
        for (int i = 0; i < size; i++) {
            digits[i] = other.digits[i];
        }
    }

    void operator+=(const bigint& other);

    void operator+=(long long other);

    bigint operator+(const bigint& other);

    bigint operator+(long long other);

    bigint& operator++();

    void operator-=(const bigint& other);

    void operator-=(long long other);

    bigint operator-(const bigint& other);

    bigint operator-(long long other);

    bigint& operator--();

    bigint operator*(const bigint& other);

    bigint operator*(long long other);

    void operator*=(const bigint& other);

    void operator/=(long long x);

    bigint operator/(long long x);

    long long operator%(long long x);

    bool operator==(const bigint& number);

    bool operator==(long long number);

    bool operator!=(long long number1);

    bool operator!=(const bigint& number);

    bool operator>(long long number);

    bool operator<(long long number);

    bool operator>=(long long number);

    bool operator<=(long long number);
};
