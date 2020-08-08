#include<iostream>
#include<queue>

using namespace std;

int main()
{
	//priority queue using max heap
	priority_queue<int>max_pq;
	max_pq.push(10);
	max_pq.push(2);
	max_pq.push(69);
	max_pq.push(22);

	cout << "priority queue using max heap" << endl;
	while (max_pq.size() != 0)
	{
		cout << "top = " << max_pq.top() << endl;
		max_pq.pop();
	}

	// priority queue using min heap
	priority_queue<int, vector<int>, greater<int>> min_pq;
	min_pq.push(10);
	min_pq.push(2);
	min_pq.push(69);
	min_pq.push(22);

	cout << "\npriority queue using min heap" << endl;
	while (min_pq.size() != 0)
	{
		cout << "top = " << min_pq.top() << endl;
		min_pq.pop();
	}
	return 0;
}