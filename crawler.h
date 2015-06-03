#ifndef CRAWLER_H
#define CRAWLER_H
#include <iostream>
#include "linkqueue.h"
#include "htmlparse.h"
#include "handleurl.h"
class Crawler
{
private:
    HtmlParse parse;//解析html
    HandleUrl handleUrl;//处理url请求
    LinkQueue queue;//url的请求队列
public:
    Crawler(std::string url,std::string filePath);
    void init();
    void crawling();
};

#endif // CRAWLER_H
