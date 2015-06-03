#include "crawler.h"

Crawler::Crawler(std::string url,std::string filePath)
{
    queue.addUnvisitedLink(url);
}
void Crawler::init()
{

}
void Crawler::crawling()
{
    while (!queue.empty()) {
        std::string url=queue.front();
        //验证url的和法性

        handleUrl.downLoadData(url);
        //获得页面的html
        std::string html(handleUrl.getData().begin(),handleUrl
                         .getData().end());
        std::vector<std::string> urls=parse.getUrls(html);
        for(auto url:urls)
        {
            if(!queue.contains(url))
            {
                queue.addUnvisitedLink(url);
            }
        }
        std::cout<<url<<std::endl;
        queue.pop();
    }
}
