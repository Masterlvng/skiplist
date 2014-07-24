#include "../src/skiplist.hpp"
#include <map>
#include <sys/time.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using namespace util;

typedef struct ss
{
    string* s;
} s_t;

string concate(string s, int i)
{
    stringstream ss;
    ss << s << i;
    return ss.str();
}

int main()
{  
    /*
    s_t* st = new s_t();
    cout << st->s;
*/
    string s("sdfsdfsdf");
    util::SkipList<string, unsigned int> list;
    unsigned int a = 12344;

    int i = 0;
    for(;i<100000;i++)
    {
        list.Insert(concate("sdf", i), a);
    }
    /*
    struct timeval start, end;
    unsigned int val = 12344;
    util::SkipList<unsigned long, unsigned int> list;
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
    */
}
