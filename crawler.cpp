#include "crawler.h"

Crawler::Crawler(std::string filePath):imgUtil(filePath)
{
    std::fstream urlFile("url.txt",std::ios::in);
    std::string url;
    if(!urlFile)
    {
        std::cerr<<"open url.txt error"<<std::endl;
        return ;
    }
    while (getline(urlFile,url)) {
        queue.addUnvisitedLink(url);
    }
    std::fstream rangeFile("range.txt",std::ios::in);
    if(!rangeFile)
    {
        std::cerr<<"open range.txt error"<<std::endl;
        return ;
    }
    std::string temp;
    std::vector<std::string> range;
    while (getline(rangeFile,temp)) {
        range.push_back(temp);
    }
    parse.setRange(range);
}
void Crawler::crawling()
{
    HandleUrl* handleUrl=HandleUrl::getInstance();
    while (!queue.empty()) {
        std::string url=queue.front();
        //验证url的和法性
        if(parse.isValid(url))
        {
            try//发生异常后继续进行循环
            {
                handleUrl->downLoadData(url);
                //获得页面的html
                std::string html(handleUrl->getData()->begin(),handleUrl
                                 ->getData()->end());
                std::vector<std::string> urls=parse.getUrls(html,url);
                for(auto url:urls)
                {
                    queue.addUnvisitedLink(url);
                }
                std::cout<<url<<std::endl;
                std::vector<std::string> imgs=parse.getImgSrc(html);//保存网页内的动态图片
                for(auto src:imgs)
                {
                    handleUrl->downLoadData(src);
                    imgUtil.saveImg(handleUrl->getData());
                }
            }catch (std::exception &e)
            {
                std::cerr<<e.what()<<std::endl;
            }
        }
        queue.pop(url);
    }
}
