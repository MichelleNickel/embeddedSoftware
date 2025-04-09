#ifndef CONFIG_H
#define CONFIG_H

#include <array>

using std::array;

namespace config {
    const int SPIKE_LIMIT = 828;

    const inline array<array<unsigned int, 2>, 24> extractPoints = {{{2, 6},
                                                                     {3, 7},
                                                                     {4, 8},
                                                                     {5, 9},
                                                                     {1, 9},
                                                                     {2, 10},
                                                                     {1, 8},
                                                                     {2, 9},
                                                                     {3, 10},
                                                                     {2, 3},
                                                                     {3, 4},
                                                                     {5, 6},
                                                                     {6, 7},
                                                                     {7, 8},
                                                                     {8, 9},
                                                                     {9, 10},
                                                                     {1, 4},
                                                                     {2, 5},
                                                                     {3, 6},
                                                                     {4, 7},
                                                                     {5, 8},
                                                                     {6, 9},
                                                                     {1, 3},
                                                                     {4, 6}}};

}// namespace config

#endif//CONFIG_H
