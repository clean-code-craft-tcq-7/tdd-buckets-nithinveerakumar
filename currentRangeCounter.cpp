#include <stdio.h>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <list>
#include <map>
#include <sstream>

using namespace std;


string getContRageCount(string range){

    std::stringstream testRange(range);
    string segment;
    list<int> rangeset;
    while(getline(testRange, segment, ','))
    {
        rangeset.push_back(stoi(segment));
    }
    rangeset.sort();
    list <string> rangeMap;
    std::ostringstream oss;
    int tmp=rangeset.front();
    list <int> test;
     for (auto& rng : rangeset) {

        if((rng-tmp)>1)
        {
            oss<<test.front()<<"-"<<test.back()<<","<<test.size()<<endl;
            rangeMap.push_back(oss.str());
            test.clear();
            //oss.clear();
        }
        test.push_back(rng);
        tmp=rng;
    }
    if(!test.empty())
    {
        oss<<test.front()<<"-"<<test.back()<<","<<test.size()<<endl;
        rangeMap.push_back(oss.str());
       // oss.clear();
        test.clear();
    }

    return oss.str();
}