#include <iostream>
#include <algorithm>

using namespace std;

void inputArray(int a[], int n){
	for (int i=0; i<n; i++)
		cin>>a[i];
}

void displayArray(int a[], int n){
	for (int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;	
}

int getMax(int a[], int n){
	int max=a[0];
	for (int i=0; i<n; i++)
		if (a[i]>max) max=a[i];
	return max;		
}
int getMin(int a[], int n){
	int min=a[0];
	for (int i=0; i<n; i++)
		if (a[i]<min) min=a[i];
	return min;		
}

//Return the position first found of x within the array
//Return -1 in case find not found
int getFirstPos(int a[], int n, int x){
	int pos=-1;
	for (int i=0; i<n; i++)
		if (a[i]==x){
			pos=i; break;
		}
	return pos;	
}

//Return the position theK of x within the array
//Return -1 incase find not found or out of range
int getPosTheK(int a[], int n, int x, int theK){
	int pos=-1, count=0; 
	if (theK>=n) return pos;
	for (int i=0; i<n; i++)
		if (a[i]==x){
			count++;
			if (count==theK){
				pos=i; break;
			}
		}
	return pos;	
}

void sortAsc(int a[], int n){
	sort(a,a+n);	
}
//Bubble sort in ascending order
void sortAsc2(int a[], int n){
	for (int i=0; i<n-1; i++)
		for (int j=n-1; j>i; j--)
			if (a[j-1] > a[j]){
				int tmp=a[j-1]; a[j-1]=a[j]; a[j]=tmp;
			}
}
//Bubble sort in descending order
void sortDesc(int a[], int n){
	for (int i=0; i<n-1; i++)
		for (int j=n-1; j>i; j--)
			if (a[j-1] < a[j]){
				int tmp=a[j-1]; a[j-1]=a[j]; a[j]=tmp;
			}
}

//Sort in the range from pos1 to pos2 in ascending order
//Keep the remain unchange
void sortInRange(int a[], int n, int pos1, int pos2){
	if (pos1>pos2){
		int tmp=pos1; pos1=pos2; pos2=tmp;
	}
	for (int i=pos1; i<pos2; i++)
		for (int j=pos2; j>i; j--)
			if (a[j-1] > a[j]){
				int tmp=a[j-1]; a[j-1]=a[j]; a[j]=tmp;
			}	
}

//Return the value at position pos
//Return -999 in case out of the range.
int getValueAtPos(int a[], int n, int pos){
	int rs=-999;
	if (pos<0 || pos>=n) return rs;
	for (int i=0; i<n; i++)
		if (i==pos){
			rs=a[i]; break;
		}
	return rs;	
}
int main(){
	int n;
	cin>>n;
	int a[n];
	inputArray(a,n);
	cout<<"=== OUTPUT ==="<<endl;
	displayArray(a,n);
//	cout<<"The maximum value: "<<getMax(a,n)<<endl;
//	cout<<"The minimum value: "<<getMin(a,n)<<endl;
	int x, pos, theK;
//	cout<<"Input searching number: "; cin>>x;
//	pos=getFirstPos(a,n,x);
//	if (pos!=-1)
//		cout<<"The position first found "<<x<<" is "<<pos<<endl;
//	else
////		cout<<"Find not found "<<x<<" in the array."<<endl;	
//	cout<<"The position of the first max: "<<getFirstPos(a,n,getMax(a,n))<<endl;	
//	cout<<"The position of the first min: "<<getFirstPos(a,n,getMin(a,n))<<endl;	
//	cout<<"Input the position the-K: "; cin>>theK;
//	pos=getPosTheK(a,n,x,theK);
//	if (pos!=-1)
//		cout<<"The position the-"<<theK<<" of "<<x<<" is "<<pos<<endl;
//	else
//		cout<<"Find not found the position the-"<<theK<<" of "<<x<<" in the array."<<endl;	
//	cout<<"Sort in acsending order"<<endl;
//	sortAsc2(a,n);
//	displayArray(a,n);	
//	cout<<"Sort in descsending order"<<endl;
//	sortDesc(a,n);
//	displayArray(a,n);	
//	cout<<"Sort in the range"<<endl;
//	sortInRange(a,n,getPosTheK(a,n,getMax(a,n),2),getPosTheK(a,n,getMin(a,n),2));
//	displayArray(a,n);	
//	cin.ignore() ;
	cout<<"Input postion to get value: "; cin>>pos;
	int rs=getValueAtPos(a,n,pos);
	if (rs!=-999)
		cout<<"The value at position "<<pos<<" is: "<<rs<<endl;
	else
		cout<<"Searching value out of range."<<endl;	
	
	return 0;
}
