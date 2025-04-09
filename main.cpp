#include <array>
#include <fstream>
#include <iostream>
#include <vector>

#include "ChipSequenzGenerator.h"
#include "config.h"

using std::array;

array<array<bool, 1023>, 24> generateChipSequences() {
    array<array<bool, 1023>, 24> chipSequences = {};
    for (int i = 0; auto points: extractPoints) {
        array<bool, 1023> chipSequenz = {};
        ChipSequenzGenerator generator(points.at(0), points.at(1));

        for (bool &chip: chipSequenz) {
            chip = generator.getNext();
        }

        chipSequences.at(i) = chipSequenz;
        i++;
    }
    return chipSequences;
}

std::vector<int> readSignal(const std::string &filename) {
    std::ifstream file(filename);
    std::vector<int> signal;
    int bit;
    while (file >> bit) {
        signal.push_back(bit);
    }
    return signal;
}

int main(int argc, char **argv) {
    // Sicherstellen, dass ein Parameter angegeben wurde (Dateiname)
    if (argc < 2) {
        std::cerr << "Error! Filename of signal missing." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <signal-file>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::vector<int> signal = readSignal(filename);

    const array<array<bool, 1023>, 24> chipSequences = generateChipSequences();

    return 0;
}