#include <iostream>
#include <fstream>
#include "crawler.h"
int main(int argc,char *argv[])
{
    Crawler craler("http://tieba.baidu.com/f?kw=%E7%BE%8E%E5%9B%BE","path");
    craler.crawling();
    return 0;
}

