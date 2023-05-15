#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> numbers) {
    int n = numbers.size();
    for (int i = 0; i < n; i++) {
        // Zatrzymaj pętlę, jeśli żadne zamiany nie są już potrzebne
        bool alreadySorted = true;
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
                alreadySorted = false;
            }
        }
        if (alreadySorted) {
            break;
        }
    }
    return numbers;
}

vector<int> quickSort(vector<int> numbers) {
    if (numbers.size() <= 1) {
        return numbers;
    }
    int pivot = numbers[numbers.size() / 2];
    vector<int> left, middle, right;
    for (int num : numbers) {
        if (num < pivot) {
            left.push_back(num);
        } else if (num == pivot) {
            middle.push_back(num);
        } else {
            right.push_back(num);
        }
    }
    vector<int> sorted;
    sorted = quickSort(left);
    sorted.insert(sorted.end(), middle.begin(), middle.end());
    vector<int> rightSorted = quickSort(right);
    sorted.insert(sorted.end(), rightSorted.begin(), rightSorted.end());
    return sorted;
}