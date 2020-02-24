#include <iostream>
#include <fstream>
#include "Primes.h"
#include <set>

void superPrimeFile(Primes a, int border, std::ofstream &outFile) {
    if (a.size() == 0) {
        for (int i = 0; i < border; ++i) {
            outFile << a[a[i] - 1] << std::endl;
        }
    } else {
        int i = 0;
        while (a[i] - 1 < border) {
            outFile << a[a[i] - 1] << std::endl;
            i++;
        }
    }
}

void superPrime(Primes a, int border) {
    if (a.size() == 0) {
        for (int i = 0; i < border; ++i) {
            std::cout << a[a[i] - 1] << ' ';
        }
    } else {
        int i = 0;
        while (a[i] - 1 < border) {
            std::cout << a[a[i] - 1] << ' ';
            i++;
        }
    }
}

void SophieGermainFile(Primes a, int border, std::ofstream &outFile) {
    if (a.size() == 0) {
        std::set<uint32_t> primeContainer;
        std::set<uint32_t> answer;
        int ch = 0;
        while (answer.size() < border) {
            primeContainer.insert(a[ch]);
            ch++;
            if (primeContainer.count((a[ch] - 1) / 2)) {
                answer.insert((a[ch] - 1) / 2);
                outFile << (a[ch] - 1) / 2 << std::endl;
            }
        }
    } else {
        std::set<uint32_t> primeContainer;
        std::set<uint32_t> answer;
        for (int i = 0; i < border; i++) {
            primeContainer.insert(a[i]);
            if (primeContainer.count((a[i] - 1) / 2)) {
                answer.insert((a[i] - 1) / 2);
            }
        }
        for (auto x : answer) {
            outFile << x << std::endl;
        }
    }
}

void SophieGermain(Primes a, int border) {
    if (a.size() == 0) {
        std::set<uint32_t> primeContainer;
        std::set<uint32_t> answer;
        int ch = 0;
        while (answer.size() < border) {
            primeContainer.insert(a[ch]);
            ch++;
            if (primeContainer.count((a[ch] - 1) / 2)) {
                answer.insert((a[ch] - 1) / 2);
                std::cout << (a[ch] - 1) / 2 << ' ';
            }
        }
    } else {
        std::set<uint32_t> primeContainer;
        std::set<uint32_t> answer;
        for (int i = 0; i < (a[i] - 1) / 2; i++) {
            primeContainer.insert(a[i]);
            if (primeContainer.count((a[i] - 1) / 2)) {
                answer.insert((a[i] - 1) / 2);
            }
        }
        for (auto x : answer) {
            std::cout << x << ' ';
        }
    }
}


int main(int argc, char *argv[]) {
    std::vector<std::string> v;
    int pos = 1;
    for (int i = 0; i < argc; i++) {
        v.push_back(argv[i]);
    }
    if (v.size() == 1) {
        Primes a(100);
        {
            for (auto i = a.begin(); i != a.end(); i++) {
                std::cout << *i << ' ';
            }
        }
    } else {
        if (v[pos] == "--lessThen") {
            pos++;
            uint32_t size = stoi(v[pos]);
            Primes a(size);
            pos++;
            if (v[pos] == "--fileName") {
                pos++;
                std::ofstream outFile(v[pos], std::ios::trunc);
                pos++;
                if (v[pos] == "--superPrime") {
                    superPrimeFile(a, a.size(), outFile);
                } else if (v[pos] == "--SophieGermain") {
                    Primes b(2 * size + 1);
                    SophieGermainFile(b, b.size(), outFile);
                } else {
                    for (auto i = a.begin(); i != a.end(); i++) {
                        outFile << *i << std::endl;
                    }
                }
            } else {
                if (v[pos] == "--superPrime") {
                    superPrime(a, a.size());
                } else if (v[pos] == "--SophieGermain") {
                    Primes b(2 * size + 1);
                    SophieGermain(b, b.size());
                } else {
                    for (auto i = a.begin(); i != a.end(); i++) {
                        std::cout << *i << ' ';
                    }
                }
            }
        } else if (v[pos] == "--size") {
            pos++;
            Primes a;
            uint32_t size = stoi(v[pos]);
            pos++;
            if (v[pos] == "--fileName") {
                pos++;
                std::ofstream outFile(v[pos], std::ios::trunc);
                pos++;
                if (v[pos] == "--superPrime") {
                    superPrimeFile(a, size, outFile);
                } else if (v[pos] == "--SophieGermain") {
                    SophieGermainFile(a, size, outFile);
                } else {
                    for (auto i = 0; i < size; i++) {
                        outFile << a[i] << std::endl;
                    }
                }
            } else {
                if (v[pos] == "--superPrime") {
                    superPrime(a, size);
                } else if (v[pos] == "--SophieGermain") {
                    SophieGermain(a, size);
                } else {
                    for (auto i = 0; i < size; i++) {
                        std::cout << a[i] << ' ';
                    }
                }
            }
        } else {
            Primes a(100);
            if (v[pos] == "--fileName") {
                pos++;
                std::ofstream outFile(v[pos], std::ios::trunc);
                pos++;
                if (v[pos] == "--superPrime") {
                    superPrimeFile(a, a.size(), outFile);
                } else if (v[pos] == "--SophieGermain") {
                    Primes b(200);
                    SophieGermainFile(b, b.size(), outFile);
                } else {
                    for (auto i = 0; i < a.size(); i++) {
                        outFile << a[i] << std::endl;
                    }
                }
            } else {
                if (v[pos] == "--superPrime") {
                    superPrime(a, a.size());
                } else if (v[pos] == "--SophieGermain") {
                    Primes b(200);
                    SophieGermain(b, b.size());
                } else {
                    for (auto i = 0; i < a.size(); i++) {
                        std::cout << a[i] << std::endl;
                    }
                }
            }
        }
    }
    return 0;
}