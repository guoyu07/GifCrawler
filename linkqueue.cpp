#include "linkqueue.h"

LinkQueue::LinkQueue():MAX_SIZE(10)
{
}
/** 获得头部链接
 */
std::string LinkQueue::front()
{
    return *unvisitedSet.begin();
}
/** 出队
 */
void LinkQueue::pop(std::string url)
{
    addVisitedLink(url);
    unvisitedSet.erase(url);
}
/** 检测队列是否为空
 */
bool LinkQueue::empty()
{
    return unvisitedSet.empty();
}

/** 添加访问过的的路径
 */
void LinkQueue::addVisitedLink(std::string link)
{
    visitedSet.insert(link);
}
/** 添加没有访问过的路径，等待爬虫访问
 */
void LinkQueue::addUnvisitedLink(std::string url)
{
    if(unvisitedSet.find(url)!=unvisitedSet.end())
        return ;
    if(visitedSet.find(url)!=visitedSet.end())
        return ;
    unvisitedSet.insert(url);
}
