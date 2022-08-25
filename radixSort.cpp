#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void distribute(const vector<int> &v, queue<int> digitQueue[], int pwr) {
	int i;
	for(int i=0; i < v.size(); i++)
	digitQueue[(v[i]/pwr) % 10].push(v[i]);
}

void collect(queue<int> digitQueue[], vector<int> &v) {
	int i = 0;

	for(int digit = 0; digit < 10; digit++)
		while(!digitQueue[digit].empty()) {
			v[i] = digitQueue[digit].front();
			digitQueue[digit].pop();
			i++;
			}
}

void radixSort(vector<int>& v, int d) {

 	int power = 1;
 	queue<int> digitQueue[10];

 	for (int i=0; i < d; i++) {
  	distribute(v, digitQueue, power);
  	collect(digitQueue, v);
  	power *= 10;
 	}
}
void radixSort(vector<int>& arr) {
 radixSort( arr,6)  ;

}


int main()
{
vector<int> vect;
vect.push_back(10);
    vect.push_back(20);
    vect.push_back(56);
     vect.push_back(57);
      vect.push_back(2);
       vect.push_back(1);
radixSort(vect);
for (int i = 0; i < vect.size(); i++)
      cout << vect[i] << " ";
    return 0;
}
