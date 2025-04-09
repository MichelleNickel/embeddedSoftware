#ifndef CHIPSEQUENZGENERATOR_H
#define CHIPSEQUENZGENERATOR_H

#include <algorithm>
#include <array>

using std::array;

class ChipSequenzGenerator {
public:
    ChipSequenzGenerator(unsigned int firstExtractPoint, unsigned int secondExtractPoint);

    bool getNext();

private:
    void nextRegister1();
    void nextRegister2();

    static constexpr unsigned int REG_SIZE = 10;

    const unsigned int firstExtractPoint;
    const unsigned int secondExtractPoint;

    array<bool, REG_SIZE> register1{};
    array<bool, REG_SIZE> register2{};
};


#endif//CHIPSEQUENZGENERATOR_H
