#include <iostream>
#include <fstream>
#include "crawler.h"
int main(int argc,char *argv[])
{
    Crawler craler("http://tieba.baidu.com/f?ie=utf-8&kw=gif&fr=search","path");
    craler.crawling();
    return 0;
}

