// is_sorted_until example
#include <iostream>    
#include <algorithm>    // is_sorted_until
#include <array>        // array
using namespace std;

/*
procedure to call is_sorted_until
*/

void check(array<int,6> a)
{
	for(int i=0;i<6;i++)
	{
		cout<<a[i]<<"\t";
	}
	array<int,6>::iterator i=is_sorted_until(a.begin(),a.end());	//you can also give your range here
	i!=a.end()?cout<<"\nafter "<<*i<<" the range is unsorted\n\n":cout<<"\nsorted\n\n";
}

int main () {
  	array<int,6> arr1 {2,4,8,9,1,99};
  	array<int,6> arr2 {1,3,9,12,28,99};
	check(arr1);
	check(arr2);
return 0;
}
