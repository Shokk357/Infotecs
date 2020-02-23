#include <iostream>

#include "Primes.h"

int main() {
    Primes a(100);
//    auto begin = a.begin();
//    auto end = a.end();
//    for (int i = 0; i < a.size(); i++) {
//        begin++;
//        std::cout << a[i] << ' ';
//    }
//    std::cout << std::endl;
    for (Primes::Iterator i = a.begin(); i != a.end(); i++) {
        std::cout << *i << ' ';
    }
    std::cout << std::endl;
//    Primes a;
//    for (int i = 0; i < 25; i++) {
//        a.begin()++;
//        std::cout << a[i] <<' ';
//    }
    return 0;
}