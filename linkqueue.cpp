#include "linkqueue.h"

LinkQueue::LinkQueue():MAX_SIZE(1000)
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
void LinkQueue::pop()
{
    std::string url=*unvisitedSet.begin();
    visitedSet.insert(url);
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
    if(visitedSet.size()>=MAX_SIZE)
    {
        saveLink();
    }
    visitedSet.insert(link);
}
/** 添加没有访问过的路径，等待爬虫访问
 */
void LinkQueue::addUnvisitedLink(std::string link)
{
    unvisitedSet.insert(link);
}
/** 队列是否含有某个url
 */
bool LinkQueue::contains(std::string url)
{
    if(unvisitedSet.count(url)!=0)
        return true;
    if(visitedSet.count(url)!=0)
        return true;
    return false;
}

/** 删除
 */
void LinkQueue::removeLink(std::string link)
{

}
/** 把访问过的路径写入berkeley db
 */
void LinkQueue::saveLink()
{

}
/** 使用正则表达式判断一个url是否合法
 */
bool LinkQueue::isRightLink(std::string link)
{

}
/** 判断一个url是否已经访问过
 */
bool LinkQueue::isVisited(std::string link)
{

}
