// is_sorted_until example
#include <iostream>    
#include <algorithm>    // is_sorted_until
#include <set>        // multiset
using namespace std;

/*
procedure to call is_sorted_until
*/

void check(multiset<int> ms)
{
	multiset<int>::iterator it;
	for(it =ms.begin();it!=ms.end();it++)
	{
		cout<<*it<<"\t";
	}
	multiset<int>::iterator i=is_sorted_until(ms.begin(),ms.end());	//you can also give your range here
	i!=ms.end()?cout<<"\nafter "<<*i<<" the range is unsorted\n\n":cout<<"\nsorted\n\n";
}

int main () {
  	multiset<int> ms1 {2,4,8,9,1,99};
  	multiset<int> ms2 {1,3,9,12,28,99};
	check(ms1);
	check(ms2);
return 0;
}
