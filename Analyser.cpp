#include "Analyser.h"


std::optional<Result> Analyser::getBit(const array<int, 2046> &signal, const array<int, 1023> &chipSequence) {
    for (unsigned int delta = 0; delta < signal.size() / 2; delta++) {
        int result = 0;

        for (size_t i = 0; i < chipSequence.size(); i++) {
            result += chipSequence[i] * signal[i + delta];
        }

        if (result > config::SPIKE_LIMIT || result < -config::SPIKE_LIMIT) {
            return Result{
                    result > 0,
                    delta};
        }
    }

    return std::nullopt;
}