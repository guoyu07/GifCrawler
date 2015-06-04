#ifndef CRAWLER_H
#define CRAWLER_H
#include <iostream>
#include <fstream>
#include "linkqueue.h"
#include "htmlparse.h"
#include "handleurl.h"
class Crawler
{
private:
    HtmlParse parse;//解析html
    LinkQueue queue;//url的请求队列
public:
    Crawler(std::string url,std::string filePath);
    void crawling();
};

#endif // CRAWLER_H
