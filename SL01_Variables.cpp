#include <iostream>
using namespace std;
int main(){
	int n;
	char vC;
	float vF;
	double vD;
	string str;
	bool flag;
	
	cout<<"Input n = "; cin>>n;
	cout<<"Input a char c = "; cin>>vC;
	cout<<"Input a float f = "; cin>>vF;
	cout<<"Input a double d = "; cin>>vD;
	cin.ignore();	//Clear buffer
	cout<<"Input a string str = "; getline(cin,str);	
	
	cout<<"Inputed n = "<<n<<endl;
	cout<<"Inputed C = "<<vC<<endl;
	cout<<"Inputed f = "<<vF<<endl;
	cout<<"Inputed d = "<<vD<<endl;
	cout<<"Inputed string = "<<str<<endl;
	
	return 0;
}
