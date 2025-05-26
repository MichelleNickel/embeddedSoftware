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

array<array<int, 1023>, 24> generateChipSequences() {
    array<array<int, 1023>, 24> chipSequences = {};
    for (int i = 0; auto points: config::extractPoints) {
        array<int, 1023> chipSequenz = {};
        ChipSequenzGenerator generator(points.at(0), points.at(1));

        for (int &chip: chipSequenz) {
            chip = generator.getNext();
        }

        chipSequences.at(i) = chipSequenz;
        i++;
    }
    return chipSequences;
}

array<int, 1023> readSignal(std::string fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + fileName);
    }

    std::string text;
    std::getline(file, text);

    std::vector<std::string> t = split(text, " ");
    array<int, 1023> result{};

    if (t.size() < result.max_size())
        throw std::runtime_error("Invalid signal file");

    for (int i = 0; i < result.size(); i++) {
        result.at(i) = std::stoi(t.at(i));
    }

    return result;
}


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