#include <BitArray.h>
#include <cmath>


int main()
{
//    BitArray a(3, 15);
//    BitArray b(2, 10);
//    std::cout << a.to_string() << ' ' << b.to_string() << std::endl;
//    a.swap(b);
//    std::cout << a.to_string() << ' ' << b.to_string() << std::endl;
//    a.resize(3);
//    std::cout << a.to_string() << ' ' << b.to_string() << std::endl;
//    a.push_back(1);
//    std::cout << a.to_string() << ' ' << b.to_string() << std::endl;
//    a = ~a;
//    std::cout << a.to_string() << std::endl;
//    a.reset(20);
//    std::cout << a.to_string() << std::endl;
    BitArray a(2, 389);
    BitArray b(2, 424);
    BitArray c(3, 652);
    BitArray d(3, 593);
    std::cout << a.to_string() << std::endl;
    std::cout << b.to_string() << std::endl;
    a ^= b;
    std::cout << a.to_string() << std::endl;
    a ^= c;
    std::cout << a.to_string() << std::endl;
    BitArray e = c ^ d;
    std::cout << c.to_string() << std::endl;
    std::cout << d.to_string() << std::endl;
    std::cout << e.to_string() << std::endl;

    BitArray f(1, 33);
    BitArray g(1, 33);
    std::cout << (f == g);

    return 1;
}