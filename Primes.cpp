#include "Primes.h"
#include <iostream>
#include <vector>
#include <cmath>

Primes::Primes(uint32_t max) : iter(this) {
    for (int i = 2; i < max; i++) {
        int mod = 0, half = (int) sqrt(i);
        while (half > 0) {
            if (i % half == 0) mod++;
            half--;
        }
        if (mod == 1) primes.push_back(i);
    }
    isLimited = true;
}

Primes::Primes() : iter(this) {
    isLimited = false;
}

uint32_t Primes::size() const {
    return primes.size();
}

Primes::Iterator Primes::begin() {
    this->iter.m_position = 0;
    return iter;
}

Primes::Iterator Primes::end() {
    if (this->isLimited) {
        this->iter.m_position = -1;
    } else {
        if (this->size() == 0) {
            this->iter.m_position = 0;
        } else {
            this->iter.m_position = -1;
        }
    }
    return iter;
}

uint32_t Primes::operator[](uint32_t index) {
    if (this->isLimited) {
        if (index >= this->size()) throw std::runtime_error("Index is out of range");
        return primes[index];
    } else {
        if (index < this->size()) {
            return primes[index];
        }
        uint32_t prevVal;
        (this->primes.empty()) ? prevVal = 2 : prevVal = this->primes[primes.size() - 1] + 1;
        while (this->primes.size() != index + 1) {
            int mod = 0, half = (int) sqrt(prevVal);
            while (half > 0) {
                if (prevVal % half == 0) mod++;
                half--;
            }
            if (mod == 1) {
                this->primes.push_back(prevVal);
            }
            prevVal++;
        }
        return primes[index];
    }
}


Primes::Iterator &Primes::Iterator::operator++() {
    if (this->m_primesPointer->isLimited) {
        if (this->m_position != this->m_primesPointer->primes.size() - 1) {
            this->m_position++;
        } else {
            this->m_position = -1;
        }
        return *this;
    } else {
        uint32_t prevVal;
        (this->m_primesPointer->primes.empty()) ? prevVal = 2 : prevVal = this->m_primesPointer->primes[m_primesPointer->primes.size() - 1] + 1;
        uint32_t prevSize = m_primesPointer->primes.size();
        while (this->m_primesPointer->primes.size() != prevSize + 1) {
            int mod = 0, half = (int) sqrt(prevVal);
            while (half > 0) {
                if (prevVal % half == 0) mod++;
                half--;
            }
            if (mod == 1) {
                this->m_primesPointer->primes.push_back(prevVal);
            }
            prevVal++;
        }
        this->m_position++;
        return *this;
    }
}

const Primes::Iterator Primes::Iterator::operator++(int) {
    Primes::Iterator tmp(*this);
    operator++();
    return tmp;
}

Primes::Iterator::Iterator(Primes::Iterator &iterator) : m_position(iterator.m_position),
                                                         m_primesPointer(iterator.m_primesPointer) {

}

Primes::Iterator::Iterator(Primes *primesPointer) : m_position(0), m_primesPointer(primesPointer) {
}

Primes::Iterator::Iterator(Primes::Iterator &&iterator) : m_position(iterator.m_position),
                                                          m_primesPointer(iterator.m_primesPointer) {
    iterator.m_position = 0;
    iterator.m_primesPointer = nullptr;
}

bool Primes::Iterator::operator!=(Primes::Iterator iterator) const {
    return (&m_primesPointer->primes[this->m_position] != &m_primesPointer->primes[iterator.m_position]) ||
           (this->m_position != iterator.m_position);
}

uint32_t Primes::Iterator::operator*() const {
    return m_primesPointer->primes[m_position];
}
