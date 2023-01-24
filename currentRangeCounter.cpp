
#include <map>
#include <cstring>
#include <list>
#include <map>
#include <sstream>
#include"currentRangeCounter.hpp"

using namespace std;

list<int> convertStringToList(string range){
   std::stringstream testRange(range);
    string segment;
    list<int> rangeSet;
    while(getline(testRange, segment, ','))
    {
        rangeSet.push_back(stoi(segment));
    }
    rangeSet.sort();
    return rangeSet;
}

string getContRageCount(string range){

    list<int> rangeSet = convertStringToList(range);
    list <string> rangeList;
    std::ostringstream oss;
    int tmp=rangeSet.front();
    list <int> test;
     for (auto& rng : rangeSet) {

        if((rng-tmp)>1)
        {
            oss<<test.front()<<"-"<<test.back()<<","<<test.size()<<endl;
            rangeList.push_back(oss.str());
            test.clear();
            //oss.clear();
        }
        test.push_back(rng);
        tmp=rng;
    }
    if(!test.empty())
    {
        oss<<test.front()<<"-"<<test.back()<<","<<test.size()<<endl;
        rangeList.push_back(oss.str());
       // oss.clear();
        test.clear();
    }

    return oss.str();
}