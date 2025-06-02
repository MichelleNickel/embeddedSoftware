#include <array>
#include <format>
#include <fstream>
#include <iostream>
#include <vector>


#include "run.h"

int main(int argc, char **argv) {
    // Sicherstellen, dass ein Parameter angegeben wurde (Dateiname)
    if (argc < 2) {
        std::cerr << "Error! Filename of signal missing." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <signal-file>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    array<int, 1023> signal = readSignal(filename);

    const array<array<int, 1023>, 24> chipSequences = generateChipSequences();

    for (int i = 0; i < chipSequences.size(); i++) {
        const auto calcResult = Analyser::getBit(signal, chipSequences.at(i));

        if (!calcResult.has_value())
            continue;

        const Result result = calcResult.value();
        std::cout << std::format("Satellite {} has sent bit {} (delta = {})", i + 1, result.foundBit ? 1 : 0, result.delta) << std::endl;
    }

    return 0;
}

using std::array;