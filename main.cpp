#include <iostream>
#include <set>

using namespace std;

set<pair<int,int>> visited;
int sumDigits(int num)
{
	int res=0;
	while(num)
	{
		res+=num%10;
		num/=10;
	}
	return res;
}


void searchCells(int currX,int currY, long long& res)
{
	if(sumDigits(abs(currX))+sumDigits(abs(currY))>25 || visited.find({currX,currY})!=visited.end())
		return;
	res++;
    visited.insert({currX,currY});
    searchCells(currX,currY+1,res);
    searchCells(currX+1,currY,res);
    return;
}
int main()
{
	int startX=1000,startY=1000;
	long long res=0;
    searchCells(startX,startY,res);
    cout<<res<<endl;
    return 0;
}
