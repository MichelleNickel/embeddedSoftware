#ifndef RUN_H
#define RUN_H

#include <array>
#include <format>
#include <fstream>
#include <iostream>
#include <vector>


#include "Analyser.h"
#include "ChipSequenzGenerator.h"
#include "config.h"
#include "utils.h"

using std::array;

array<int, 1023> readSignal(std::string fileName);

array<array<int, 1023>, 24> generateChipSequences();

#endif //RUN_H
