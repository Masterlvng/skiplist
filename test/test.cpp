#include "../src/skiplist.hpp"
#include <iostream>

using namespace util;

int main()
{
    util::SkipList<int, int> list(1023);
    int key = 3;
    int val = 4;
    std::cout << list.Insert(key,val) << std::endl;
    int ret;
    std::cout << list.Search(key, ret) << std::endl;
    std::cout << list.Delete(key, ret) << std::endl;
    std::cout << ret << std::endl;
    return 0;
}
