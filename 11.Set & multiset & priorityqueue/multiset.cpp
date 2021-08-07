#include<bits/stdc++.h>
using namespace std;
//same as set, but allows multiple element

void print_set(set<int> st)
{
	multiset<int>::iterator it;
	for(it=st.begin(); it!=st.end(); it++) cout<<*it<endl;
}

int main()
{
	multiset<int> s;
	multiset<int>::iterator it;

	s.insert(1);
	s.insert(4);
	s.insert(3);
	s.insert(3);
	s.insert(5);
	s.insert(6);

	s.erase(s.find(3)); //gon erase first 3;
    s.erase(3); //gon erase all 3

	while(1)
	{
		scanf("%d", &x);
		if(s.find(x) == s.end()) printf("Not Found\n");
		else printf("Found\n");
	}

}