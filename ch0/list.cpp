#include<iostream>
using namespace std;
const int N = 100010;

//head ��ʾͷ�����һ���±�
//e[i] ��ʾ���i��ֵ
//ne[i] ��ʾ���i��nextָ���Ƕ���
//idx �洢��ǰ���ĸ��� 
int head ,e[N] ,ne[N] ,idx;

//��ʼ�� 
void init(){
	head = -1;
	idx = 0; 
}

//��x�嵽ͷ����
void add_to_head(int x){
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx++; 
}  

//��x�嵽�±���k�Ľ����� 
void add(int k, int x){
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;
}

//���±���k����Ľ��ɾ��
void remove(int k){
	ne[k] = ne[ne[k]];
} 
int main(){
	int m;
	cin>>m;
	init();
	while(m--){
		int k , x;
		char op;
		cin>>op;
		if(op == 'H'){
			cin>>x;
			add_to_head(x);
		}
		else if(op == 'D'){
			cin>>k;
			if(!k) head = ne[head];
			 remove(k-1);
		}
		else{
			cin>>k>>x;
			add(k-1, x);
		}
	} 
	for(int i = head ; i != -1; i = ne[i]){
		cout<< e[i] << ' ';
	}
	return 0;
}
