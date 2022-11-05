#pragma once
#include <iostream>
#include <vector>
#include "Timer.h"
const int d = 100;

namespace fn {
    void createMas(std::vector<int> & mas, int n);
    void printMas(std::vector<int> & mas);
    void shellSort(std::vector<int> & mas);

}