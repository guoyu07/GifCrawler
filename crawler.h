#ifndef CRAWLER_H
#define CRAWLER_H
#include <iostream>

class Crawler
{
private:
public:
    Crawler(std::string path);
    void init();
    void crawling();
};

#endif // CRAWLER_H
