#include"currentRangeCounter.h"

using namespace std;

list<int> convertStringNumbersToIntList(string range){
   std::stringstream testRange(range);
    string segment;
    list<int> rangeList;
    while(getline(testRange, segment, ','))
    {
        rangeList.push_back(stoi(segment));
    }
    rangeList.sort();
    return rangeList;
}

string groupRangeList(list<int> rangeList)
{
    list <string> rangeListString;
    std::ostringstream oss;
    int previousRange=rangeList.front();
    list <int> tempList;
     for (auto& currentRange : rangeList) {

        if((currentRange-previousRange)>1)
        {
            oss<<tempList.front()<<"-"<<tempList.back()<<","<<tempList.size()<<endl;
            rangeListString.push_back(oss.str());
            tempList.clear();
            //oss.clear();
        }
        tempList.push_back(currentRange);
        previousRange=currentRange;
    }
    if(!tempList.empty())
    {
       oss<<tempList.front()<<"-"<<tempList.back()<<","<<tempList.size()<<endl;
       rangeListString.push_back(oss.str());
       // oss.clear();
        tempList.clear();
    }
    return oss.str();
}

string getContinuousRangeCount(string range){

    list<int> rangeList = convertStringNumbersToIntList(range);
    if(!rangeList.empty()) {
        string formattedRangeCount = groupRangeList(rangeList);
        return formattedRangeCount;
    } else {
        return "0";
    }
}