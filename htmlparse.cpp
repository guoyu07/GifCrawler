#include "htmlparse.h"

HtmlParse::HtmlParse()
{

}
/** 获得html中的所有的链接
 */
std::vector<std::string> HtmlParse::getUrls(std::string &html)
{
    std::vector<std::string> urls;
//    RE2 re("\s*(?i)href\s*=\s*(\"([^\"]*\")|'[^']*'|([^'\">\s]+))");
//    RE2 re("<a\\s.*?href=\"([^\"]+)\"[^>]*>(.*?)</a>");
    RE2 re("<a(?: [^>]*)+href=([^ >]*)(?: [^>]*)*>");
    re2::StringPiece input(html);
    std::string res;int count=0;
    while(re2::RE2::FindAndConsume(&input, re, &res) ){
        urls.push_back(res);
        std::cout<<res<<std::endl;
        ++count;
    }
    std::cout<<count<<std::endl;
    return urls;
}
/** 获得页面所有图片的地址
 */
std::vector<std::string> HtmlParse::getImgSrc(std::string &html)
{
    std::vector<std::string> imgs;
    RE2 re("<img[^>]+src\\s*=\\s*['\"]([^'\"]+)['\"][^>]*>");
    re2::StringPiece input(html);
    std::string res;int count=0;
    while(re2::RE2::FindAndConsume(&input, re, &res) ){
        imgs.push_back(res);
        std::cout<<res<<std::endl;
        ++count;
    }
    std::cout<<count<<std::endl;
}

