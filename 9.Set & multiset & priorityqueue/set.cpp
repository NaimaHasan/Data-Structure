#include<bits/stdc++.h>
using namespace std;

// begin() – Returns an iterator to the first element in the set.
// end() – Returns an iterator to the theoretical element that follows last element in the set.
// size() – Returns the number of elements in the set.
// max_size() – Returns the maximum number of elements that the set can hold.
// empty() – Returns whether the set is empty.


// insert(const g) – Adds a new element ‘g’ to the set.
// iterator insert (iterator position, const g) – Adds a new element ‘g’ at the position pointed by iterator.
// erase(iterator position) – Removes the element at the position pointed by the iterator.
// erase(const g)– Removes the value ‘g’ from the set.
// clear() – Removes all the elements from the set.

// find(const g) – Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.
// count(const g) – Returns 1 or 0 based on the element ‘g’ is present in the set or not.
// lower_bound(const g) – Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set.
// upper_bound(const g) – Returns an iterator to the first element that will go after the element ‘g’ in the set.

int main()
{
	set<int> s;
	set<int>::iterator it;

	s.insert(1);
	s.insert(4);
	s.insert(3);
	s.insert(3);
	s.insert(5);
	s.insert(6);

	for(it=s.begin(); it!=s.end(); it++) cout<<*it<endl;

	while(1)
	{
		scanf("%d", &x);
		if(s.find(x) == s.end()) printf("Not Found\n");
		else printf("Found\n");
	}

}