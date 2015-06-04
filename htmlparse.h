#ifndef HTMLPARSE_H
#define HTMLPARSE_H

#include <iostream>
#include <vector>
#include <vector>
#include <re2/re2.h>
class HtmlParse
{
private:
    std::vector<std::string> rangeUrlVec;//url的访问范围
public:
    std::vector<std::string> getUrls(std::string& html,std::string curUrl);
    std::vector<std::string> getImgSrc(std::string& html);
    bool isValid(std::string url);
    void setRange(std::vector<std::string> range);
    HtmlParse();
};

#endif // HTMLPARSE_H
