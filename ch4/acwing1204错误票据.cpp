//acwing1204����Ʊ�� 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;
const int N = 100010;
int n, a[N];
 //��������ж�ǰ���ϵ 
int main(){
	int cnt;
	cin >> cnt;
	
	string line;
	getline(cin , line);//���Ե�һ�еĻس� 
	
	while(cnt--){
		getline(cin , line);
		stringstream ssin(line);
		
		while(ssin >> a[n]) n++;
	}
	
	sort(a , a+n);
	int res1 , res2;
	for(int i = 1; i < n; i++){
		if(a[i] == a[i-1]) res2 = a[i]; //�غ� 
		else if(a[i] >= a[i-1] + 2) res1 = a[i] - 1;//�Ϻ� 
	}
	
	cout<<res1<<' '<<res2<<endl;
	 
	return 0;
}
