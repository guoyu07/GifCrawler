#include "linkqueue.h"

LinkQueue::LinkQueue():MAX_SIZE(10)
{
    db=DBUtil::getInstance();
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
//    if(visitedSet.size()>=MAX_SIZE)
//    {
//        for(auto url:visitedSet)
//        {
//            db->add(url,"1");
//        }
//        visitedSet.clear();
//    }
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
    if(visitedSet.size()>=MAX_SIZE)
    {
        for(auto url:visitedSet)
        {
            db->add(url,"1");
        }
        visitedSet.clear();
    }
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
    std::string temp=db->select(url);
    if(temp.size()>0)//如果已经访问过，并写入数据库，就不在插入
        return ;
    unvisitedSet.insert(url);
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


bool LinkQueue::isVisited(std::string url)
{
    if(db->select(url).size()>0)
        return true;
    else
        return false;
}

