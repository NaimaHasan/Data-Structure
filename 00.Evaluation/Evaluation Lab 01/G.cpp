// You are given information of N employees. 
// Particularly you are given the Name, Department and Designation of an employee. 
// You have to sort the employee according to Department first (increasing). 
// Then by Designation (MD, GM, DGM, AGM, ENGR) and then by name (increasing). 
// Use STL sort and compare function.

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

struct employee
{
	char Name[16];
	char Dept[16];
	char Des[5];
};

bool comp( struct employee e1, struct employee e2 )
{
	if(strcmp(e1.Dept, e2.Dept) < 0) return true;
	if(!strcmp(e1.Dept, e2.Dept))
	{
		if(!strcmp(e1.Des, "MD"))
		{
			if( !strcmp(e2.Des, "GM") ) return true;
			if( !strcmp(e2.Des, "DGM") ) return true;
			if( !strcmp(e2.Des, "AGM") ) return true;
			if( !strcmp(e2.Des, "ENGR") ) return true;
		}

		if( !strcmp(e1.Des, "GM") )
		{
            if( !strcmp(e2.Des, "DGM") ) return true;
            if( !strcmp(e2.Des, "AGM") ) return true;
            if( !strcmp(e2.Des, "ENGR") ) return true;
		}

		if( !strcmp(e1.Des, "DGM") )
		{
            if( !strcmp(e2.Des, "AGM") ) return true;
            if( !strcmp(e2.Des, "ENGR") ) return true;
        }

		if( !strcmp(e1.Des, "AGM") )
			if( !strcmp(e2.Des, "ENGR") ) return true;
                

		if((!strcmp(e1.Des, "MD") && !strcmp(e2.Des, "MD")) || 
		   (!strcmp(e1.Des, "GM") && !strcmp(e2.Des, "GM")) || 
		   (!strcmp(e1.Des, "DGM") && !strcmp(e2.Des, "DGM")) || 
		   (!strcmp(e1.Des, "AGM") && !strcmp(e2.Des, "AGM")) || 
		   (!strcmp(e1.Des, "ENGR") && !strcmp(e2.Des, "ENGR")))

			if( strcmp(e1.Name, e2.Name) < 0) return true;
		
	}

	return false;
}

int main(){
	long long int n, i;

	struct employee array[100005];
	
	scanf("%lld", &n);

	for(i = 0; i < n; i++)
		scanf("%s %s %s", array[i].Name, array[i].Dept, array[i].Des);

	sort(array, array+n, comp);

	for(i = 0; i < n; i++)
		printf("%s %s %s\n", array[i].Name, array[i].Dept, array[i].Des);

	return 0;
}
