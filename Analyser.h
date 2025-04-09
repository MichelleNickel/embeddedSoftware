#ifndef EMBEDDED_SOFTWARE_ANALYSER_H
#define EMBEDDED_SOFTWARE_ANALYSER_H

#include <algorithm>
#include <array>
#include <optional>

#include "config.h"

using std::array;

struct Result {
    bool foundBit;
    unsigned int delta;
};

class Analyser {
public:
    static std::optional<Result> getBit(const array<int, 1023> &signal, const array<int, 1023> &chipSequence);

private:
    static int multiply(const array<int, 1023> &arr1, const array<int, 1023> &arr2);
};


#endif//EMBEDDED_SOFTWARE_ANALYSER_H
