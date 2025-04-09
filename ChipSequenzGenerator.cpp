#include "ChipSequenzGenerator.h"

#include <numeric>


ChipSequenzGenerator::ChipSequenzGenerator(const unsigned int firstExtractPoint, const unsigned int secondExtractPoint) : firstExtractPoint(firstExtractPoint), secondExtractPoint(secondExtractPoint) {
    std::ranges::fill(register1, true);
    std::ranges::fill(register2, true);
}

bool ChipSequenzGenerator::getNext() {
    const bool extractedValue1 = register2.at(this->firstExtractPoint - 1);
    const bool extractedValue2 = register2.at(this->secondExtractPoint - 1);
    const bool valueReg1 = register1.at(REG_SIZE - 1);

    const bool finishedValue = valueReg1 ^ extractedValue1 ^ extractedValue2;

    this->nextRegister1();
    this->nextRegister2();

    return finishedValue;
}


void ChipSequenzGenerator::nextRegister1() {
    constexpr unsigned int extractPoint = 2;

    const bool extractedValue = register1.at(extractPoint);
    const bool lastValue = register1.at(REG_SIZE - 1);

    const bool newValue = lastValue ^ extractedValue;

    std::ranges::rotate(register1, register1.end() - 1);
    register1.at(0) = newValue;
}

void ChipSequenzGenerator::nextRegister2() {
    const array<unsigned int, 5> fixedExtractionPoints = {1, 2, 5, 7, 8};
    array<bool, 5> fixedValues = {};

    for (int i = 0; i < fixedExtractionPoints.size(); ++i) {
        fixedValues.at(i) = register2.at(fixedExtractionPoints.at(i));
    }

    const bool lastValue = register2.at(REG_SIZE - 1);
    const bool fixedValue = std::accumulate(fixedValues.begin(), fixedValues.end(), false, [](bool a, bool b) { return a ^ b; });

    const bool newValue = lastValue ^ fixedValue;

    std::ranges::rotate(register2, register2.end() - 1);
    register2.at(0) = newValue;
}
