//acwing99����ը�� 
#include<cstring>
#include<iostream> 
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 5010;

int n , r;//nΪ���� �� rΪ�߳� ����סr-1 * r-1 
int n1 , m1; //�м�ֵ������󳤿� 
//int a[N][N]; //ԭ���� 
int s[N][N]; //ǰ׺�;���
 //�±��1��ʼ 
int main(){
	scanf("%d%d", &n , &r);   
	r = min(r , 5001);
	n1 = m1 = r;
	  
	while(n--){
		int x, y ,w;
		scanf("%d%d%d",&x, &y , &w);
		x++ , y++;
		n1=max(x , n1) , m1 = max(y , m1);  			
		s[x][y] += w ;
	}
	
	//Ԥ����ǰ׺�;���
	for(int i = 1; i <= 5001; i++){
		for(int j = 1; j <= 5001; j++){
			s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];  			
		}
	}
	
	int ans = 0;
	for(int i = r ; i <= 5001 ;i++ ){
		for(int j = r; j <= 5001; j++){
//			int t = s[i][j] - s[i-(r-1)-1][j] - s[i][j-(r-1)-1] + s[i-(r-1)-1][j-(r-1)-1];
			int t = s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r];
			ans = max(t,ans); 
		}
	}
		
	printf("%d" , ans);
	
	return 0;
}
