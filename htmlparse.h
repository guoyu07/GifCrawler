#ifndef HTMLPARSE_H
#define HTMLPARSE_H

#include <iostream>
#include <vector>
#include <re2/re2.h>
class HtmlParse
{
public:
    std::vector<std::string> getLinks(std::string& html);
    std::vector<std::string> getImgSrc(std::string& html);
    HtmlParse();
};

#endif // HTMLPARSE_H
