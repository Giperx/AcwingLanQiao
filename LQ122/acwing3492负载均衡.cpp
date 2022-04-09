//acwing3492负载均衡
//模拟 堆
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue> 
#define x first
#define y second
using namespace std;
const int N = 200010;
int n, m;
int s[N];
typedef pair<int, int> PII;
priority_queue< PII, vector<PII>, greater<PII> > q[N];

int main()
{

    cin >> n >> m;
    for(int i = 1; i  <= n; i++ ) cin >> s[i];
    
    while(m-- )
   {
   	int a, b, c, d;
   	cin >> a >> b >> c >> d;
   	while(q[b].size() && q[b].top().x <= a){
   		s[b] += q[b].top().y;
   		q[b].pop(); 
	   }
	   
	if(s[b] < d) puts("-1");
	else{
		q[b].push({a + c, d});
		s[b] -= d;
		printf("%d\n", s[b]); 		
		
		
	}
   }
    return 0;
}

