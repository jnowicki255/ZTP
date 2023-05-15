#include <iostream>
#include <vector>
#include <Python.h>

int main() {
    // Inicjalizacja interpretera Pythona
    Py_Initialize();

    // Importowanie modułu sortowania z Pythona
    PyObject* pModule = PyImport_ImportModule("sorting_module");

    if (pModule) {
        // Pobieranie referencji do funkcji sortującej
        PyObject* pFuncBubbleSort = PyObject_GetAttrString(pModule, "bubble_sort");
        PyObject* pFuncQuickSort = PyObject_GetAttrString(pModule, "quick_sort");

        if (pFuncBubbleSort && pFuncQuickSort) {
            // Tworzenie listy liczb do posortowania
            PyObject* pArgs = PyTuple_New(1);

            // Przygotowywanie danych wejściowych
            std::vector<int> numbers = {4, 2, 7, 1, 9, 5};
            PyObject* pList = PyList_New(numbers.size());
            for (size_t i = 0; i < numbers.size(); ++i) {
                PyList_SetItem(pList, i, PyLong_FromLong(numbers[i]));
            }
            PyTuple_SetItem(pArgs, 0, pList);

            // Wywoływanie funkcji sortujących
            PyObject* pResultBubbleSort = PyObject_CallObject(pFuncBubbleSort, pArgs);
            PyObject* pResultQuickSort = PyObject_CallObject(pFuncQuickSort, pArgs);

            // Konwersja wyników na listy C++
            Py_ssize_t sizeBubbleSort = PyList_Size(pResultBubbleSort);
            std::vector<int> sortedBubbleSort(sizeBubbleSort);
            for (Py_ssize_t i = 0; i < sizeBubbleSort; ++i) {
                PyObject* pItem = PyList_GetItem(pResultBubbleSort, i);
                sortedBubbleSort[i] = PyLong_AsLong(pItem);
            }

            Py_ssize_t sizeQuickSort = PyList_Size(pResultQuickSort);
            std::vector<int> sortedQuickSort(sizeQuickSort);
            for (Py_ssize_t i = 0; i < sizeQuickSort; ++i) {
                PyObject* pItem = PyList_GetItem(pResultQuickSort, i);
                sortedQuickSort[i] = PyLong_AsLong(pItem);
            }

            // Wypisywanie posortowanych wyników
            std::cout << "Sortowanie bąbelkowe: ";
            for (int num : sortedBubbleSort) {
                std::cout << num << " ";
            }
            std::cout << std::endl;

            std::cout << "Quicksort: ";
            for (int num : sortedQuickSort) {
                std::cout << num << " ";
            }
            std::cout << std::endl;

            // Zwolnienie obiektów
            Py_DECREF(pResultBubbleSort);
            Py_DECREF(pResultQuickSort);
            Py_DECREF(pArgs);
            Py_DECREF(pList);
            Py_DECREF(pFuncBubbleSort);
            Py_DECREF(pFuncQuickSort);
        }

        // Zwolnienie obiektu modułu
        Py_DECREF(pModule);
    }

    // Zamykanie interpretera Pythona
    Py_Finalize();

    return 0;
}