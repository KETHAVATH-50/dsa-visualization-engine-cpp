#pragma once
#include <vector>
#include "logger.h"

namespace Sorts {
    void bubbleSort(std::vector<int> arr, Logger &logger);
    void quickSort(std::vector<int> arr, Logger &logger);
    void mergeSort(std::vector<int> arr, Logger &logger);
    void heapSort(std::vector<int> arr, Logger &logger);
}