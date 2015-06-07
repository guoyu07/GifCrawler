#include <iostream>
#include <fstream>
#include "crawler.h"
#include "md5.h"
int main(int argc,char *argv[])
{
    Crawler craler;
    craler.crawling();
//    std::cout<<md5("aabbcc").c_str();
    return 0;
}

