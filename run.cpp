#include "run.h"

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