#ifndef INFOTECS_PRIMES_H
#define INFOTECS_PRIMES_H


#include <cstdint>
#include <vector>
#include <memory>

class Primes {
public:
    Primes(uint32_t max); // контейнер простых чисел в диапазоне 1..max
    Primes(); // контейнер простых чисел без верхней границы
    class Iterator {
    public:
        Iterator(Primes *primesPointer);

        Iterator(Iterator &iterator);

        Iterator(Iterator &&iterator);

        Primes::Iterator &operator++();

        const Primes::Iterator operator++(int);

        bool operator!=(Primes::Iterator iterator);

        uint32_t operator*();

        bool isLimited;
    private:
        Primes *m_primesPointer;
        uint32_t m_position;
        friend class Primes;
    };

    Primes::Iterator begin();

    Primes::Iterator end(); // для контейнера без верхней границы end() достижим только в пустом контейнере
    uint32_t size();

    uint32_t operator[](uint32_t index);

private:
    std::vector<uint32_t> primes;
    Primes::Iterator iter;
};


#endif //INFOTECS_PRIMES_H
