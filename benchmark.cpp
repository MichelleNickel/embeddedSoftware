#include <array>

#include <benchmark/benchmark.h>

#include "run.h"

using std::array;

static array<int, 1023> signal;
static array<array<int, 1023>, 24> chipSequences;

static void Bench_GetBit(benchmark::State& state) {
    if (state.thread_index() == 0) {
        signal = readSignal("./gps_sequence_1.txt");
        chipSequences = generateChipSequences();
    }

    for (auto _ : state) {
        for (int i = 0; i < chipSequences.size(); i++) {
            const auto calcResult = Analyser::getBit(signal, chipSequences.at(i));
        }
    }
}

BENCHMARK(Bench_GetBit);

BENCHMARK_MAIN();