#include <iostream>
#include <cstring>

class BitArray
{
private:
    int _num_bits;
    char *bitarr;

public:
    BitArray() : _num_bits(0), bitarr(nullptr){};
    ~BitArray()
    {
        delete bitarr;
    };

    // Конструирует массив, хранящий заданное количество бит.
    // Первые sizeof(long) бит можно инициализровать с помощью параметра value.
    explicit BitArray(int num_bits, unsigned long long value = 0) : _num_bits(num_bits)
    {
        bitarr = new char[64];

        for (int i = 0; i < 8 * _num_bits; i++){
            if (value % 2) {
                set(i, true);
            }
            else {
                set(i, false);
            }
            value >>= 1;
        }
    };

    BitArray(const BitArray &b) : _num_bits(b._num_bits)
    {
        bitarr = new char[_num_bits / 8 + 1];
        for (int i = 0; i < _num_bits; ++i)
            bitarr[i] = b.bitarr[i];
    };

    // Обменивает значения двух битовых массивов.
    void swap(BitArray &b);

    BitArray &operator=(const BitArray &b);

    // Изменяет размер массива. В случае расширения, новые элементы
    // инициализируются значением value.
    void resize(int num_bits, bool value = false);

    // Очищает массив.
    void clear();

    // Добавляет новый бит в конец массива. В случае необходимости
    // происходит перераспределение памяти.

    void push_back(bool bit);

    // //Битовые операции над массивами.
    // //Работают только на массивах одинакового размера.
    // //Обоснование реакции на параметр неверного размера входит в задачу.

    BitArray &operator&=(const BitArray &b);

    BitArray &operator|=(const BitArray &b);

    BitArray &operator^=(const BitArray &b);

    // Битовый сдвиг с заполнением нулями.

    BitArray &operator<<=(int n);

    BitArray &operator>>=(int n);

    BitArray operator<<(int n) const;

    BitArray operator>>(int n) const;

    // Устанавливает бит с индексом n в значение val.
    void set(int n, bool val = true); /*BitArray &*/

    // Заполняет массив истиной.
    BitArray &set();

    // Устанавливает бит с индексом n в значение false.
    void reset(int n);

    // Заполняет массив ложью.
    BitArray &reset();

    // true, если массив содержит истинный бит.

    bool any() const;

    // true, если все биты массива ложны.

    bool none() const;

    // Битовая инверсия

    BitArray operator~() const;

    // Подсчитывает количество единичных бит.
    int count() const;

    // //Возвращает значение бита по индексу i.
    bool operator[](int i) const;

    int size() const;
    bool empty() const;

    // Возвращает строковое представление массива.
    std::string to_string() const;

    bool operator==(const BitArray &b) const;
    bool operator!=(const BitArray &b) const;
    BitArray operator&(const BitArray &b) const;
    BitArray operator|(const BitArray &b) const;
    BitArray operator^(const BitArray &b) const;
};