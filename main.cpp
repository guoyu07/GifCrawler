#include <iostream>
#include <fstream>
#include "handleurl.h"
using namespace std;

int main(int argc,char *argv[])
{
    HandleUrl* hu=HandleUrl::getInstance();
    hu->downLoadData("www.163.com");
    vector<char> v=hu->getData();
    string  str;
    str.append(v.begin(),v.end());

    HtmlParse hp;
    hp.getLinks(str);
    return 0;
}

