#include<bits/stdc++.h>
using namespace std;

map<string, int> freq;
map<string, int>::iterator it;
string a[100];
int n;

int main()
{
	int i;

	freq["dhaka"] = 1;
	freq["dhaka"]++;
	freq["dhaka"] += 5;

	cin>>n;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
		freq[a[i]]++;
	}

	for(it=freq.begin(); it!=freq.end(); it++)
	{
		cout<<it->first<<" "<it->second<<endl;
	}

	if(freq.find("dhaka") != freq.end())
	{
		printf("Found");
	}
}