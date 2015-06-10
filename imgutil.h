#ifndef IMGUTIL_H
#define IMGUTIL_H

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include "md5.h"
class ImgUtil
{
    std::set<std::string> imgSet;
    std::string dir;
    bool isValid(std::vector<char>* img) const;
public:
    ImgUtil(std::string);
    ~ImgUtil();
    void saveImg(std::vector<char>* img) ;
};

#endif // IMGUTIL_H
