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
    if((*img)[0]=='g'&&(*img)[1]=='i'&&(*img)[2]=='f')
        return true;
    else
        return false;
}
/** 保存动态图片
 */
void ImgUtil::saveImg(std::vector<char> *img) const
{
    if(isValid(img))
    {
        std::string md5=getImgMd5(img);
        std::string temp=db->select(md5);//查看文件是否保存
        std::fstream file(dir+md5+".gif",std::ios::in);
        if(temp.size()>0)
            return ;
        if(!file)
        {
            std::cerr<<"open "<<md5<<" error"<<std::endl;
            return ;
        }
        for(auto c:*img)
            file.put(c);
        file.close();
        db->add(md5,"1");
    }
}
/** 获得图片的md5值
 */
std::string ImgUtil::getImgMd5(std::vector<char> *img) const
{
    std::string imgStr(img->begin(),img->end());
    return md5(imgStr.c_str());
}
