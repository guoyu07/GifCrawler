#include "dbutil.h"

DBUtil::DBUtil():db(NULL,0),count(0),MAX_COUNT(3000)
{
    db.open(NULL,"my.db",NULL,DB_BTREE,DB_CREATE,0);
}
~DBUtil()
{
    db.close(0);
}

void DBUtil::add(std::string key, std::string data)
{
    Dbt dbKey(k,k.length());
    Dbt dbData(d,d.length());
    int ret=db.put(NULL,&dbKey,&dbData,DB_NOOVERWRITE);
    if(ret==DB_KEYEXIST)//如果KEY已经存在的话，返回DB_KEYEXIST
        cout<<key<<" is exist,add data fail"<<endl;
    else
    {
        ++count;
        if(cout>MAX_COUNT)
        {
            count=0;
            db.sync();
        }
    }
}
void DBUtil::remove(std::string key)
{

}
std::string DBUtil::select(std::string key)
{
    Dbt dbKey(key,);
    Dbt dbData;//创建一个新的数据容器
    int ret=db.get(NULL,&dbKey,&dbData,0);
    if(ret==DB_NOTFOUND)//如果没查到数据则返回DB_NOTFOUND
        return "";
    else
        return dbData.get_data();
}

