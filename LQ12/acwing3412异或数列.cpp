//acwing3412�������
#include<iostream>
#include<cstring>
using namespace std;
const int N = 22;
int num[N]; // ��¼ÿһλ����1�Ĵ���

void get_cnt(int n) {
    int cnt = 1;
    while(n) {
        if(n & 1)   num[cnt]++;
        cnt++;
        n >>= 1;
    }
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        memset(num, 0, sizeof num);
        int k, sum = 0;
        scanf("%d", &k);
        for(int i = 0; i < k;i++) {
            int s;
            scanf("%d", &s);
            get_cnt(s); // ��¼num����
            sum ^= s;    
        }

        if(!sum)    puts("0");
        else {
            for(int i = 20; i >= 1;i--) {
                if(num[i] == 1) {
                    puts("1");
                    break;
                }else if(num[i] & 1) { // 1�ĸ���Ϊ����
                    if(k % 2 == 0)  {puts("-1"); break;} // 0�ĸ���������
                    else    {puts("1"); break;} // 0�ĸ�����ż��
                }
            }
        }
    }

    return 0;
}

