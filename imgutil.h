#ifndef IMGUTIL_H
#define IMGUTIL_H

#include <iostream>
#include <fstream>
#include "md5.h"
#include "dbutil.h"
#include <vector>
class ImgUtil
{
    std::string dir;
    DBUtil* db;
    bool isValid(std::vector<char>* img) const;
//    std::string getImgMd5(std::vector<char>* img) const;
public:
    ImgUtil(std::string);
    ~ImgUtil();
    void saveImg(std::vector<char>* img) const;
};

#endif // IMGUTIL_H
