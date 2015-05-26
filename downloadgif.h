#ifndef DOWNLOADGIF_H
#define DOWNLOADGIF_H

#include <iostream>
#include <fstream>
class DownLoadGif
{
private:
    std::string path;
public:
    bool isPathExist(std::string path);
    DownLoadGif();
};

#endif // DOWNLOADGIF_H
