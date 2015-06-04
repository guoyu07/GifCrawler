#include "handleurl.h"
HandleUrl* const HandleUrl::handleUrl=new HandleUrl;


/** 下载数据的回调函数，注意不是HandleUrl的成员函数
 */
size_t setData(void *buffer, size_t size, size_t nmemb, void *user_p)
{
    std::vector<char>* data=HandleUrl::getInstance()->getData();
    for(int i=0;i<size*nmemb;++i)
    {
        char* c=(char*)buffer+i;
        data->push_back(*c);
    }
    return size*nmemb;
}

HandleUrl* HandleUrl::getInstance()
{
    return handleUrl;
}
std::vector<char>* HandleUrl::getData()
{

     return this->data;
}

HandleUrl::HandleUrl()
{
    curlCode=curl_global_init(CURL_GLOBAL_ALL);
    if(CURLE_OK!=curlCode)
    {
        std::cerr<<"init libcurl failed"<<std::endl;
    }
    data=new std::vector<char>;
}
HandleUrl::~HandleUrl()
{
    curl_global_cleanup();
    delete data;
}
/** 处理url，下载文件
 */
void HandleUrl::downLoadData(std::string url)
{
    if(CURLE_OK!=curlCode)
    {
        std::cerr<<"init libcurl failed"<<std::endl;
        return ;
    }
    CURL* handle=curl_easy_init();
    if(NULL==handle)
    {
        std::cerr<<"get a easy handle error"<<std::endl;
        return ;
    }
    curl_easy_setopt(handle,CURLOPT_URL,url.c_str());
    curl_easy_setopt(handle, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(handle,CURLOPT_WRITEFUNCTION,setData);
    data->clear();
    curl_easy_perform(handle);
    curl_easy_cleanup(handle);
}
/** 保存文件
 */
void HandleUrl::saveFile(std::string path)
{
    std::fstream file(path,std::ios::out);
    std::vector<char>* data=HandleUrl::getInstance()->getData();
    std::copy(data->begin(),data->end(),std::ostreambuf_iterator<char>(file));
    file.close();
}
