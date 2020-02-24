#pragma once
/// @brief Струтура класса контейнера простых чисел
/// @author Pavel Tsyganov
/// @date 2020

#ifndef INFOTECS_PRIMES_H
#define INFOTECS_PRIMES_H

#include <cstdint>
#include <vector>
#include <memory>


/// @brief Контейнер простых чисел
class Primes {
public:
    /// @brief Конструктор ограниченного контейнера
    /// @param[in] max - ограничение на значение простого числа
    Primes(uint32_t max);

    /// @brief Конструктор контейнера без верхней границы
    Primes();

    /// @brief Итератор по контейнеру
    class Iterator {
    public:

        /// @brief конструктор итератора
        /// @param primesPointer контейнер простых чисел
        Iterator(Primes *primesPointer);

        /// @brief конструктор копирования
        Iterator(Iterator &iterator);

        /// @brief конструктор перемещения
        Iterator(Iterator &&iterator);

        /// @brief оператор инкремента
        Primes::Iterator &operator++();

        /// @brief оператор инкремента
        const Primes::Iterator operator++(int);

        /// @brief оператор неравенства
        bool operator!=(Primes::Iterator iterator) const;

        /// @brief конструктор разыменования
        uint32_t operator*() const;

    private:
        Primes *m_primesPointer;
        uint32_t m_position;
        friend class Primes;
    };

    /// @brief Итератор на начало контейнера
    Primes::Iterator begin();

    /// @brief Итератор, определяющий конец контейнера
    Primes::Iterator end();

    /// @brief Возвращает текущий размер контейнера
    uint32_t size() const;

    /// @brief Оператор доступа к элементу контейнера по индексу
    uint32_t operator[](uint32_t index);

private:
    bool isLimited;
    std::vector<uint32_t> primes;
    Primes::Iterator iter;
};


#endif //INFOTECS_PRIMES_H
