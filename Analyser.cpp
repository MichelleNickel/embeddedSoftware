#include "Analyser.h"


std::optional<Result> Analyser::getBit(const array<int, 1023> &signal, const array<int, 1023> &chipSequence) {
    const size_t N = chipSequence.size();

    for (unsigned int delta = 0; delta < N; ++delta) {
        int result = 0;
        for (size_t i = 0; i < N; ++i) {
            result += signal[i] * chipSequence[(i + delta) % N];
        }

        if (result > config::SPIKE_LIMIT || result < -config::SPIKE_LIMIT) {
            return Result{
                result > 0, 
                delta
            };
        }
    }

    return std::nullopt;
}

/*
int Analyser::multiply(const array<int, 1023> &arr1, const array<int, 1023> &arr2) {
    int result = 0;

    for (size_t i = 0; i < arr1.size(); ++i) {
        result += arr1[i] * arr2[i];
    }

    return result;
}
*/