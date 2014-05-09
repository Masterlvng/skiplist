#include "../src/skiplist.hpp"
#include <map>
#include <sys/time.h>
#include <iostream>
using namespace std;
using namespace util;

int main()
{   
    struct timeval start, end;
    unsigned int val = 12344;
    util::SkipList<unsigned long, unsigned int> list(600120000);
    std::cout << "skiplist" << std::endl;
    gettimeofday(&start,NULL);
    unsigned long i;
    for(i = 0; i < 6000000; i++)
    {
        list.Insert(i,val);
    }
    gettimeofday(&end,NULL);
    unsigned long time_pass;
    time_pass = 1000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000;
    std::cout << time_pass <<" ms" << std::endl; 
    std::map<unsigned long, unsigned int> mmap;
    std::cout << "map:" << std::endl; 

    gettimeofday(&start,NULL);
    for(i = 0; i < 6000000; i++)
    {
        mmap.insert(map<unsigned long, unsigned int>::value_type(i, val));   
    }
    gettimeofday(&end,NULL);
    time_pass = 1000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000;

    std::cout << time_pass <<" ms" << std::endl; 
    return 1;
}
