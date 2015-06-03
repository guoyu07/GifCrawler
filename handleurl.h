#ifndef HANDLEURL_H
#define HANDLEURL_H

#include <iostream>
#include <vector>
#include <fstream>
#include "linkqueue.h"
#include "htmlparse.h"
#include "curl/curl.h"
class HandleUrl
{
private:
    std::vector<char> data;//保存下载的数据，html或者image
    LinkQueue queue;//url队列
    CURLcode curlCode;//CURL初始化的状态码
    static HandleUrl* const handleUrl;
public:
    HandleUrl();
    ~HandleUrl();
    std::vector<char>& getData();
    void saveFile(std::string path);
    static HandleUrl*  getInstance();
    void downLoadData(std::string url);
};

#endif // HANDLEURL_H
