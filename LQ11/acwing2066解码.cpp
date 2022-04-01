//acwing2066解码 
//模拟 字符串处理 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio> 
using namespace std;
#if 1
int main(){
	string s, res;
	cin >> s;
	
	for(int i = 0; i < s.size(); i++ ){
		if(i + 1 < s.size() && s[i + 1] <= '9'){
			int k = s[i + 1] - '0';
			while(k--) res += s[i];
			i ++;
		}
		else{
			res += s[i]	;		
		}
		cout << res;
	}
	
	
	return 0;
} 


#else //尝试 通过 
char word[110];

int main(){
	cin >> word;
	int i = 0;
	
	int m = strlen(word);
	while(m--){
		char tmp = word[i++];
		if( word[i] >= '1' && word[i] <= '9' ) {
		    
			for(int j = 0; j < word[i] - '0'; j ++) {
			    cout << tmp;
			}
		tmp = word[i++];
		}
		else {
			cout << tmp;
		}				
	}
	
	return 0;
}
#endif
