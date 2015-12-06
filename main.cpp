#include <iostream>
#include "hwlist.h"

int main() {
    HWList<int>* firstList = new HWList<int>();

    firstList->push_back(10);
    firstList->push_back(20);
    firstList->push_back(30);

    HWList<int>* secondList = new HWList<int>();
    *secondList = *firstList;

    std::cout << "firstList: ";
    for (HWList<int>::iterator it = firstList->begin(); it != firstList->end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl << "secondList: ";
    for (HWList<int>::iterator it = secondList->begin(); it != secondList->end(); it++)
        std::cout << *it << " ";

    std::cout << std::endl << firstList;
    std::cout << std::endl << secondList;


    firstList->push_back(20);
    firstList->push_back(10);

    std::cout << std::endl << "firstList: ";
    for (HWList<int>::iterator it = firstList->begin(); it != firstList->end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl << "secondList: ";
    for (HWList<int>::iterator it = secondList->begin(); it != secondList->end(); it++)
        std::cout << *it << " ";

    return 0;
}
