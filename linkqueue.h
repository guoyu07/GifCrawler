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
    void saveLink();
    bool isRightLink(std::string link);
    bool isVisited(std::string link);
public:
    LinkQueue();
    void addVisitedLink(std::string link);
    void addUnvisitedLink(std::string link);
    void removeLink(std::string link);
};

#endif // LINKQUEUE_H
