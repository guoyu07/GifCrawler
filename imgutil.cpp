#include "imgutil.h"

ImgUtil::ImgUtil(std::string dir)
{
    this->dir=dir;
}

ImgUtil::~ImgUtil()
{

}
/** 判断图片是否是动态图片
 */
bool ImgUtil::isValid(std::vector<char> *img) const
{
    if((*img)[0]=='G'&&(*img)[1]=='I'&&(*img)[2]=='F')
        return true;
    else
        return false;
}

//#include <openssl/md5.h>
/** 保存动态图片
 */
void ImgUtil::saveImg(std::vector<char> *img)
{
    if(img->size()<1024*10)//如果小于10KB的话不保存
        return ;
    if(isValid(img))
    {
        std::string md5Str=md5(std::string(img->begin(),img->end()));
        if(imgSet.find(md5Str)!=imgSet.end())//存在重复
            return ;
        std::fstream file(dir+"/"+md5Str+".gif",std::ios::out);
        if(!file)
        {
            std::cerr<<"open "<<md5Str<<" error"<<std::endl;
            return ;
        }
        for(auto c:*img)
            file.put(c);
        file.close();
        std::cout<<" ---- IMG:svae "<<md5Str<<" success"<<std::endl;
        img->clear();
        imgSet.insert(md5Str);
    }
}

