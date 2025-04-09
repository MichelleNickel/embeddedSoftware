#include "Analyser.h"


std::optional<Result> Analyser::getBit(const array<int, 1023> &signal, const array<int, 1023> &chipSequence) {
    array<int, 1023> tmp = chipSequence;

    for (unsigned int delta = 0; delta < signal.size(); delta++) {
        const int result = Analyser::multiply(signal, tmp);

        if (result > config::SPIKE_LIMIT || result < -config::SPIKE_LIMIT) {
            return Result{
                result > 0,
                delta
            };
        }

        std::rotate(tmp.begin(), tmp.begin() + 1, tmp.end());
    }

    return std::nullopt;
}

int Analyser::multiply(const array<int, 1023> &arr1, const array<int, 1023> &arr2) {
    int result = 0;

    for (size_t i = 0; i < arr1.size(); ++i) {
        result += arr1[i] * arr2[i];
    }

    return result;
}