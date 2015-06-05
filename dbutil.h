#ifndef DBUTIL_H
#define DBUTIL_H

#include <iostream>
#include "db_cxx.h"
class DBUtil
{
private:
    Db db;
    DBUtil();
    int MAX_COUNT;
    int count;//操作次数，如果查过操作次数，数据将存储到磁盘上
    static DBUtil* dbUtil;
public:
    ~DBUtil();
    void add(std::string key,std::string data);
    void remove(std::string key);
    std::string select(std::string key);
    static DBUtil* getInstance();
};
#endif // DBUTIL_H
