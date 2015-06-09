#include "imgutil.h"

ImgUtil::ImgUtil(std::string dir)
{
    this->dir=dir;
    db=DBUtil::getInstance();
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
void ImgUtil::saveImg(std::vector<char> *img,std::string path) const
{
    if(img->size()<1024*10)//如果小于10KB的话不保存
        return ;
    if(isValid(img))
    {
//        std::string md5=getImgMd5(img);
        std::string md5Str=md5(path);
//        std::cout<<md5Str<<std::endl;
        std::string temp=db->select(md5Str);//查看文件是否保存
        std::fstream file(dir+"/"+md5Str+".gif",std::ios::out);
        if(!file)
        {
            std::cerr<<"open "<<md5Str<<" error"<<std::endl;
            return ;
        }
        for(auto c:*img)
            file.put(c);
        file.close();
        db->add(md5Str,"1");
//        std::cout<<" ---- IMG:svae "<<md5Str<<" success"<<std::endl;
        img->clear();
    }
}
/** 获得图片的md5值
 */
std::string ImgUtil::getImgMd5(std::vector<char> *img) const
{
    return md5vector(img);
}
