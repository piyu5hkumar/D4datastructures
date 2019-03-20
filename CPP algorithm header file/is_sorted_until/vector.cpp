// is_sorted_until example
#include <iostream>    
#include <algorithm>    // is_sorted_until
#include <vector>        // vector
using namespace std;

/*
procedure to call is_sorted_until
*/

void check(vector<int> v)
{
	for(int i=0;i<6;i++)
	{
		cout<<v[i]<<"\t";
	}
	vector<int>::iterator i=is_sorted_until(v.begin(),v.end());	//you can also give your range here
	i!=v.end()?cout<<"\nafter "<<*i<<" the range is unsorted\n\n":cout<<"\nsorted\n\n";
}

int main () {
  	vector<int> vec1 {2,4,8,9,1,99};
  	vector<int> vec2 {1,3,9,12,28,99};
	check(vec1);
	check(vec2);
return 0;
}
