// is_sorted_until example
#include <iostream>    
#include <algorithm>    // is_sorted_until
#include <set>        // set
using namespace std;

/*
procedure to call is_sorted_until
*/

void check(set<int> s)
{
	set<int>::iterator it;
	for(it =s.begin();it!=s.end();it++)
	{
		cout<<*it<<"\t";
	}
	set<int>::iterator i=is_sorted_until(s.begin(),s.end());	//you can also give your range here
	i!=s.end()?cout<<"\nafter "<<*i<<" the range is unsorted\n\n":cout<<"\nsorted\n\n";
}

int main () {
  	set<int> s1 {2,4,8,9,1,99};
  	set<int> s2 {1,3,9,12,28,99};
	check(s1);
	check(s2);
return 0;
}
