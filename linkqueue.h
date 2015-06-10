#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <iostream>
#include <set>
class LinkQueue
{
private:
    int MAX_SIZE;//已经访问过的url的容器保存的最大值，默认是1000
    std::set<std::string> visitedSet;//已经访问过的url
    std::set<std::string> unvisitedSet;//没有访问过的url
    void addVisitedLink(std::string link);
public:
    LinkQueue();
//    bool isVisited(std::string url);
    void addUnvisitedLink(std::string link);
    bool empty();
    void pop(std::string url);
//    bool contains(std::string url);
    std::string front();
};

#endif // LINKQUEUE_H
