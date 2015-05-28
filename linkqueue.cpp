#include "linkqueue.h"

LinkQueue::LinkQueue():MAX_SIZE(1000)
{

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
