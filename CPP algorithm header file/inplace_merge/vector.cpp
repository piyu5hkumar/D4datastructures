// inplace_merge example
#include <iostream>     // std::cout
#include <algorithm>    // std::inplace_merge, std::sort, std::copy
#include <vector>       // std::vector
#include <functional>

//including this to able to use all the required things from standard namespace
using namespace std;

//bool function for comparison
bool myfunction (int i,int j) { return (i<j); }

int main () {
	
  int first_half[] = {50,1,5,3,15};
  int second_half[] = {0,-20,9,20,777};
  vector<int> v1;
  vector<int> v2;
  
  sort (first_half,first_half+5);
  sort (second_half,second_half+5);
  
  //pushing values in the vector container v1
  for (int i = 0; i <sizeof(first_half)/sizeof(int); i++) 
    {
		v1.push_back(first_half[i]); 
	}
  for (int i = 0; i <sizeof(second_half)/sizeof(int); i++) 
    {
    	v1.push_back(second_half[i]); 
    }   


  //using version 1	
  inplace_merge (v1.begin(),v1.begin()+5,v1.end());
  cout << "The resulting vector contains: using version 1";
  for (int i=0;i<10;i++)
  {
	cout << ' ' << v1[i];
  }
  
  
  //pushing values in the vector container v2
  for (int i = 0; i <sizeof(first_half)/sizeof(int); i++) 
    {
		v2.push_back(first_half[i]); 
	}
  for (int i = 0; i <sizeof(second_half)/sizeof(int); i++) 
    {
    	v2.push_back(second_half[i]); 
    } 

  
  //using version 2
  inplace_merge (v2.begin(),v2.begin()+5,v2.end(),myfunction);
  cout << "\nThe resulting vector contains: using version 2";
  for (int i=0;i<10;i++)
  {
	cout << ' ' << v2[i];
  }	
  
  return 0;
}
