#include "crawler.h"

Crawler::Crawler(std::string url,std::string filePath)
{
    queue.addUnvisitedLink(url);
    std::fstream file("range.txt",std::ios::in);
    std::string temp;
    std::vector<std::string> range;
    while (getline(file,temp)) {
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
            handleUrl->downLoadData(url);
            //获得页面的html
            std::string html(handleUrl->getData()->begin(),handleUrl
                             ->getData()->end());
            std::vector<std::string> urls=parse.getUrls(html,url);
            for(auto url:urls)
            {
                if(!queue.contains(url))
                {
                    queue.addUnvisitedLink(url);
                }
            }
            std::cout<<url<<std::endl;
        }
        queue.pop();
    }
}
