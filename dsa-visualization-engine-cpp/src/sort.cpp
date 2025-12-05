#include "sort.h"
#include <algorithm>

using namespace std;

namespace Sorts {

static void bubble(vector<int> &a, Logger &logger) {
    int n = a.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j + 1 < n - i; ++j) {
            logger.logStep("Compare", {a[j], a[j+1]});
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                logger.logStep("Swap", a);
            }
        }
}

static int partition(vector<int> &a, int l, int r, Logger &logger) {
    int pivot = a[r];
    int i = l - 1;
    logger.logStep("Partition pivot", {pivot});

    for (int j = l; j < r; ++j) {
        logger.logStep("Compare", {a[j], pivot});
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
            logger.logStep("Swap", a);
        }
    }

    swap(a[i + 1], a[r]);
    logger.logStep("Swap pivot into place", a);
    return i + 1;
}

static void quick(vector<int> &a, int l, int r, Logger &logger) {
    if (l < r) {
        int p = partition(a, l, r, logger);
        quick(a, l, p - 1, logger);
        quick(a, p + 1, r, logger);
    }
}

void bubbleSort(vector<int> arr, Logger &logger) {
    logger.logMsg("Starting Bubble Sort");
    bubble(arr, logger);
    logger.logMsg("Finished Bubble Sort");
}

void quickSort(vector<int> arr, Logger &logger) {
    logger.logMsg("Starting Quick Sort");
    if (!arr.empty())
        quick(arr, 0, arr.size() - 1, logger);
    logger.logMsg("Finished Quick Sort");
}

static void merge(vector<int> &a, int l, int m, int r, Logger &logger) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = a[l + i];
    for (int i = 0; i < n2; ++i) R[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        logger.logStep("Compare (merge)", {L[i], R[j]});
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
        logger.logStep("After write (merge)", a);
    }

    while (i < n1) { a[k++] = L[i++]; logger.logStep("After write (merge)", a); }
    while (j < n2) { a[k++] = R[j++]; logger.logStep("After write (merge)", a); }
}

static void msort(vector<int> &a, int l, int r, Logger &logger) {
    if (l < r) {
        int m = l + (r - l) / 2;
        msort(a, l, m, logger);
        msort(a, m + 1, r, logger);
        merge(a, l, m, r, logger);
    }
}

void mergeSort(vector<int> arr, Logger &logger) {
    logger.logMsg("Starting Merge Sort");
    if (!arr.empty())
        msort(arr, 0, arr.size() - 1, logger);
    logger.logMsg("Finished Merge Sort");
}

void heapSort(vector<int> arr, Logger &logger) {
    logger.logMsg("Starting Heap Sort");

    int n = arr.size();
    auto heapify = [&](auto self, int idx, int heapSize) -> void {
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;

            if (left < heapSize && arr[left] > arr[largest])
                largest = left;
            if (right < heapSize && arr[right] > arr[largest])
                largest = right;

            if (largest == idx) break;

            logger.logStep("Swap (heapify)", {arr[idx], arr[largest]});
            swap(arr[idx], arr[largest]);
            logger.logStep("After swap (heapify)", arr);

            idx = largest;
        }
    };

    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(heapify, i, n);

    for (int end = n - 1; end > 0; --end) {
        logger.logStep("Swap (extract)", {arr[0], arr[end]});
        swap(arr[0], arr[end]);
        logger.logStep("After swap (extract)", arr);
        heapify(heapify, 0, end);
    }

    logger.logMsg("Finished Heap Sort");
}

} // namespace Sorts