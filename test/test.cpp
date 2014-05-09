#include "../src/skiplist.hpp"
#include <iostream>

using namespace util;

int main()
{
    util::SkipList<int, int> list;
    int key = 3;
    int val = 4;
    int rev = list.Insert(key,val);
    if (rev == 1)
    {
        std::cout << "insert success!" << std::endl;
    }
    int ret;
    rev = list.Search(key, ret);
    if (rev == 1 && ret == 4) 
    {
        std::cout << "search success!" << std::endl;
    }
    ret = 0;
    rev = list.Delete(key, ret);
    if (rev == 1 && ret == 4 && list.Search(key, val) == 0)
    {
        std::cout << "delete success!" << std::endl;
    }
    return 0;
}
