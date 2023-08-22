cmake_minimum_required(VERSION 3.23)
project(BasicAlgorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(BasicAlgorithms BubbleSort.cpp InsertionSort.cpp MergeSort.cpp QuickSort.cpp Stack.cpp Queue.cpp BinarySearch.cpp CounterSort.cpp CountSortNegative.cpp CountSortStable.cpp CountSortStavbleNegative.cpp RadixSortLSD.cpp HeapSort.cpp BinaryTree.cpp AVL.cpp RLE_encode.cpp BFS.cpp DFS.cpp)
