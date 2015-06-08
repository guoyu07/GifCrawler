#include "dbutil.h"

DBUtil* DBUtil::dbUtil=NULL;
DBUtil::DBUtil():db(NULL,0),count(0),MAX_COUNT(30)
{
    db.open(NULL,"my.db",NULL,DB_BTREE,DB_CREATE,0);
}
DBUtil::~DBUtil()
{
    db.close(0);
}
/** 添加数据
 */
void DBUtil::add(std::string key, std::string data)
{
    Dbt dbKey(&key,key.length());
    Dbt dbData(&data,data.length());
    int ret=db.put(NULL,&dbKey,&dbData,DB_NOOVERWRITE);
    if(ret==DB_KEYEXIST)//如果KEY已经存在的话，返回DB_KEYEXIST
    {

    }
//        std::cout<<key<<" is exist,add data fail"<<std::endl;
    else
    {
        ++count;
        if(count>MAX_COUNT)
        {
            count=0;
            db.sync(0);
        }
    }
}
/** 删除数据
 */
void DBUtil::remove(std::string key)
{
    Dbt dbKey(&key,key.length());
    db.del(NULL,&dbKey,0);
    ++count;
}
/**查询数据
 */
std::string DBUtil::select(std::string key)
{
    Dbt dbKey(&key,key.length());
    Dbt dbData;//创建一个新的数据容器
    int ret=db.get(NULL,&dbKey,&dbData,0);
    if(ret==DB_NOTFOUND)//如果没查到数据则返回DB_NOTFOUND
        return "";
    else
        return std::string((char*)dbData.get_data());
}
DBUtil* DBUtil::getInstance()
{
    if(dbUtil==NULL)
    {
        dbUtil=new DBUtil;
    }
    return dbUtil;
}
