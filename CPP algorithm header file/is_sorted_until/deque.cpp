// is_sorted_until example
#include <iostream>    
#include <algorithm>    // is_sorted_until
#include <deque>        // deque
using namespace std;

/*
procedure to call is_sorted_until
*/

void check(deque<int> d)
{
	deque<int>::iterator it;
	for(it =d.begin();it!=d.end();it++)
	{
		cout<<*it<<"\t";
	}
	deque<int>::iterator i=is_sorted_until(d.begin(),d.end());	//you can also give your range here
	i!=d.end()?cout<<"\nafter "<<*i<<" the range is unsorted\n\n":cout<<"\nsorted\n\n";
}

int main () {
  	deque<int> d1 {2,4,8,9,1,99};
  	deque<int> d2 {1,3,9,12,28,99};
	check(d1);
	check(d2);
return 0;
}
