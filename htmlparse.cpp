#include "htmlparse.h"

HtmlParse::HtmlParse()
{

}
/** 获得html中的所有的链接
 */
std::vector<std::string> HtmlParse::getUrls(std::string &html,std::string curUrl)
{
    std::vector<std::string> urls;
    //    RE2 re("\s*(?i)href\s*=\s*(\"([^\"]*\")|'[^']*'|([^'\">\s]+))");
    //    RE2 re("<a\\s.*?href=\"([^\"]+)\"[^>]*>(.*?)</a>");
    RE2 re("<a(?: [^>]*)+href=([^ >]*)(?: [^>]*)*>");
    re2::StringPiece input(html);
    std::string res;
    while(re2::RE2::FindAndConsume(&input, re, &res) ){
        while (res.find('"')!=std::string::npos) {//去除引号
            std::string::size_type pos=res.find('"');
            res.erase(pos,pos+1);
        }
        if(res.find('#')!=std::string::npos)//含有#号的链接忽略
            continue;
        if(res[0]=='/')//判断是否是绝对路径
        {
            res=curUrl.substr(0,curUrl.find_first_of('/'))+res;
        }
        for(int i=0;i<rangeUrlVec.size();++i)
        {
            int len=rangeUrlVec[i].size();
            if(res.substr(0,len)==rangeUrlVec[i])//如果在范围内就添加到队列中
            {
                urls.push_back(res);
//                std::cout<<res<<std::endl;
                break;
            }
        }
    }
    return urls;
}
/** 获得页面所有图片的地址
 */
std::vector<std::string> HtmlParse::getImgSrc(std::string &html)
{
    std::vector<std::string> imgs;
//    RE2 re("<img[^>]+src\\s*=\\s*['\"]([^'\"]+)['\"][^>]*>");
    RE2 re("<img[^>]+src\\s*=\\s*['\"]([^'\"]+)['\"][^>]*>");
    re2::StringPiece input(html);
    std::string res;int count=0;
    while(re2::RE2::FindAndConsume(&input, re, &res) ){
        imgs.push_back(res);
    }
    return imgs;
}
/** url是否合法
 */
bool HtmlParse::isValid(std::string url)
{
    std::string s,t;
    re2::StringPiece input(url);
    re2::RE2 re("^(http://|https://)?((?:[A-Za-z0-9]+-[A-Za-z0-9]+|[A-Za-z0-9]+)\.)+([A-Za-z]+)[/\?\:]?.*$");
    if(re2::RE2::FullMatch(input, re , &s, &t))
        return true;
    else
        return false;
}
void HtmlParse::setRange(std::vector<std::string> range)
{
    rangeUrlVec=range;
}

