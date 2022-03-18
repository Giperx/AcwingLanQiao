//acwing1208·­Ó²±Ò
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;

int n;
char start[N], lastres[N];

void turn_one(int i){
	if(start[i] == '*') start[i] = 'o';
	else start[i] = '*';
}

int main(){
	cin>>start>>lastres;
	int j = strlen(start);

	for(int i =0; i < j -1 ; i++){
		if(start[i] != lastres[i]){
			turn_one(i);
			turn_one(i+1);
			++n;
		}
	}
	cout<<n<<endl;
	return 0;
}
