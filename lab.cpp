#include <iostream>
#include <vector>


// Einlesen der Datei
std::vector<int> readSignal(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> signal;
    int bit;
    while (file >> bit) {
        signal.push_back(bit);
    }
    return signal;
}


int main(int argc, char* argv[]) {
    // Sicherstellen, dass ein Parameter angegeben wurde (Dateiname)
    if (argc < 2) {
        std::cerr << "Error! Filename of signal missing." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <signal-file>" << std::endl;
        return 1;
    }

    // Datei einlesen
    std::string filename = argv[1];
    std::vector<int> signal = readSignal(filename);

    return 0;
}