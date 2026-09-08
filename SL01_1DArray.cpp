#include <iostream>
using namespace std;

void inputArray(int a[], int n){
	for (int i=0; i<n; i++)
		cin>>a[i];
}

void displayArray(int a[], int n){
	for (int i=0; i<n; i++)
		cout<<a[i]<<" ";
}

int main(){
	int n;
	cin>>n;
	int a[n];
	inputArray(a,n);
	displayArray(a,n);
	return 0;
}
