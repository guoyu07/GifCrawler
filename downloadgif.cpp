#include "downloadgif.h"

DownLoadGif::DownLoadGif()
{

}
/** 判断一个文件路径是否存在
 * @brief DownLoadGif::isPathExist
 * @param path 路径
 * @return 如果存在返回true
 */
bool DownLoadGif::isPathExist(std::string path)
{
    std::fstream file(path+"/test",std::ios::in);
    if(file)
    {
        remove(path.append("/test").c_str());
        return true;
    }
    else
        return false;
}
