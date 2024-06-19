#include <BitArray.h>
#include <iostream>
#include <cmath>

// Обменивает значения двух битовых массивов.
void BitArray::swap(BitArray &b)
{
    int size1 = _num_bits;
    int size2 = b._num_bits;
    if (_num_bits > b._num_bits) {
        b.resize(_num_bits);
    }
    else {
        (*this).resize(b._num_bits);
    }
    std::swap(bitarr, b.bitarr);
    b.resize(size1);
    (*this).resize(size2);
}

BitArray &BitArray::operator=(const BitArray &b)
{
    if (b == *this){
        return *this;
    }
    _num_bits = b._num_bits;
    for (int i = 0; i < _num_bits; i++)
    {
        bitarr[i] = b.bitarr[i];
    }
    return *this;
}

// Изменяет размер массива. В случае расширения, новые элементы
// инициализируются значением value.
void BitArray::resize(int num_bits, bool value)
{
    if (_num_bits == num_bits)
    {
        return;
    }

    if (_num_bits > num_bits)
    {
        _num_bits = num_bits;
        bitarr = (char*)realloc(bitarr, num_bits*sizeof(char*));
    }
    else
    {
        _num_bits = num_bits;
        bitarr = (char*)realloc(bitarr, num_bits*sizeof(char*));
        bitarr[num_bits - 1] = value ? 255 : 0;
    }
}
// Очищает массив.
void BitArray::clear()
{
    (*this).resize(0, 0);
}

// Добавляет новый бит в конец массива. В случае необходимости
// происходит перераспределение памяти.

void BitArray::push_back(bool bit)
{
    if ((*this)[_num_bits * 8 - 1]) { (*this).resize(_num_bits + 1); }
    for (int i = _num_bits * 8 - 1; i > 0; i--) {
        (*this).set(i, (*this)[i - 1]);
    }
    (*this).set(0, bit);
}

// //Битовые операции над массивами.
// //Работают только на массивах одинакового размера.
// //Обоснование реакции на параметр неверного размера входит в задачу.

BitArray &BitArray::operator&=(const BitArray &b)
{
    if (_num_bits != b._num_bits) {
        return *this;
    }
    for (int i = 0; i < _num_bits * 8; i++) {
        (*this).set(i, (*this)[i] && b[i]);
    }
    return *this;
}

BitArray &BitArray::operator|=(const BitArray &b)
{
    if (_num_bits != b._num_bits) {
        return *this;
    }
    for (int i = 0; i < _num_bits * 8; i++) {
        (*this).set(i, (*this)[i] || b[i]);
    }
    return *this;
}

BitArray &BitArray::operator^=(const BitArray &b)
{
    if (_num_bits != b._num_bits) {
        return *this;
    }
    for (int i = 0; i < _num_bits * 8; i++) {
        (*this).set(i, (*this)[i] ^ b[i]);
    }
    return *this;
}

// Битовый сдвиг с заполнением нулями.

BitArray &BitArray::operator<<=(int n)
{
    for (int j = 0; j < n; j++) {
        for (int i = _num_bits * 8 - 1; i > 0; i--) {
            (*this).set(i, (*this)[i - 1]);
        }
        (*this).set(0, 0);
    }
    return *this;
}

BitArray &BitArray::operator>>=(int n)
{
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < _num_bits * 8 - 1; i++) {
            (*this).set(i, (*this)[i + 1]);
        }
        (*this).set(_num_bits * 8 - 1, 0);
    }
    return *this;
}

BitArray BitArray::operator<<(int n) const
{
    BitArray temp(*this);
    temp <<= n;
    return temp;
}

BitArray BitArray::operator>>(int n) const
{
    BitArray temp(*this);
    temp >>= n;
    return temp;
}

// Устанавливает бит с индексом n в значение val.
void BitArray::set(int n, bool val)
{
    if (n < _num_bits * 8 || n < 0) {
        int byteindex = n / 8;
        int bitindex = n % 8;
        if (val){
            bitarr[byteindex] |= (1 << bitindex);
        }
        else{
            bitarr[byteindex] &= ~(1 << bitindex);
        }
    }
}

// Заполняет массив истиной.
BitArray &BitArray::set()
{
    for (int i = 0; i < _num_bits; i++)
    {
        bitarr[i] = 255;
    }
    return *this;
}

// Устанавливает бит с индексом n в значение false.
void BitArray::reset(int n)
{
    set(n, false);
}

// Заполняет массив ложью.
BitArray &BitArray::reset()
{
    for (int i = 0; i < _num_bits; i++) {
        bitarr[i] = 0;
    }
    return *this;
}

// true, если массив содержит истинный бит.
bool BitArray::any() const
{
    int k = 0;
    for (int i = 0; i < _num_bits * 8; i++) {
        if ((*this)[i]) { k++; }
    }
    return k != 0;
}
// true, если все биты массива ложны.
bool BitArray::none() const
{
    int k = 0;
    for (int i = 0; i < _num_bits * 8; i++) {
        if ((*this)[i]) { k++; }
    }
    return k == 0;
}
// Битовая инверсия

BitArray BitArray::operator~() const
{
    BitArray res(*this);
    for (int i = 0; i < _num_bits * 8; i++) {
        res.set(i, !res[i]);
    }
    return res;
}

// Подсчитывает количество единичных бит.
int BitArray::count() const
{
    int k = 0;
    for (int i = 0; i < _num_bits * 8; i++) {
        if ((*this)[i]) { k++; }
    }
    return k;
}

// //Возвращает значение бита по индексу i.
bool BitArray::operator[](int i) const {
    return bitarr[i / 8] & (int)pow(2, i % 8);
}

// Возвращает количество байт в массиве.
int BitArray::size() const
{
    return _num_bits;
}

bool BitArray::empty() const
{
    return _num_bits == 0;
}

// Возвращает строковое представление массива.
std::string BitArray::to_string() const
{
    std::string result = "";
    for (int i = size() * 8 - 1; i >= 0; i--) {
        result += (*this)[i] ? "1" : "0";
    }
    return result;
}

bool BitArray::operator==(const BitArray &b) const
{
    return (*this).to_string() == b.to_string();
}

bool BitArray::operator!=(const BitArray &b) const
{
    return (*this).to_string() != b.to_string();
}

BitArray BitArray::operator&(const BitArray &b) const
{
    BitArray c(*this);
    c &= b;
    return c;
}
BitArray BitArray::operator|(const BitArray &b) const
{
    BitArray c(*this);
    c |= b;
    return c;
}
BitArray BitArray::operator^(const BitArray &b) const
{
    BitArray c(*this);
    c ^= b;
    return c;
}