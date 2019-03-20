// is_sorted_until example
#include <iostream>    
#include <algorithm>    // is_sorted_until
#include <list>        // list
using namespace std;

/*
procedure to call is_sorted_until
*/

void check(list<int> l)
{
	list<int>::iterator it;
	for(it =l.begin();it!=l.end();it++)
	{
		cout<<*it<<"\t";
	}
	list<int>::iterator i=is_sorted_until(l.begin(),l.end());	//you can also give your range here
	i!=l.end()?cout<<"\nafter "<<*i<<" the range is unsorted\n\n":cout<<"\nsorted\n\n";
}

int main () {
  	list<int> l1 {2,4,8,9,1,99};
  	list<int> l2 {1,3,9,12,28,99};
	check(l1);
	check(l2);
return 0;
}
