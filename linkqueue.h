#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <iostream>
#include <set>
#include "dbutil.h"
class LinkQueue
{
private:
    int MAX_SIZE;//已经访问过的url的容器保存的最大值，默认是1000
    std::set<std::string> visitedSet;//已经访问过的url
    std::set<std::string> unvisitedSet;//没有访问过的url
    DBUtil* db;
    void saveLink();
//    bool isRightLink(std::string link);
    bool isVisited(std::string link);
    void addVisitedLink(std::string link);
public:
    LinkQueue();
    void addUnvisitedLink(std::string link);
//    void removeLink(std::string link);
    bool empty();
    void pop();
    bool contains(std::string url);
    std::string front();
//    void setRange(std::set<std::string> range);
};

#endif // LINKQUEUE_H
