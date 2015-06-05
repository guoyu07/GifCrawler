#ifndef CRAWLER_H
#define CRAWLER_H
#include <iostream>
#include <fstream>
#include "linkqueue.h"
#include "htmlparse.h"
#include "handleurl.h"
#include "imgutil.h"
class Crawler
{
private:
    HtmlParse parse;//解析html
    LinkQueue queue;//url的请求队列
    ImgUtil imgUtil;
public:
    Crawler(std::string filePath="./img");
    void crawling();
};

#endif // CRAWLER_H
