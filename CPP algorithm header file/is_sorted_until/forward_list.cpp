// is_sorted_until example
#include <iostream>    
#include <algorithm>    // is_sorted_until
#include <forward_list>        // forward_list
using namespace std;

/*
procedure to call is_sorted_until
*/

void check(forward_list<int> fl)
{
	forward_list<int>::iterator it;
	for(it =fl.begin();it!=fl.end();it++)
	{
		cout<<*it<<"\t";
	}
	forward_list<int>::iterator i=is_sorted_until(fl.begin(),fl.end());	//you can also give your range here
	i!=fl.end()?cout<<"\nafter "<<*i<<" the range is unsorted\n\n":cout<<"\nsorted\n\n";
}

int main () {
  	forward_list<int> fl1 {2,4,8,9,1,99};
  	forward_list<int> fl2 {1,3,9,12,28,99};
	check(fl1);
	check(fl2);
return 0;
}
