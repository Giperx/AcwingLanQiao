#include<iostream>
#include<stdlib.h>
using namespace std;
//¹é²¢ÅÅÐòÄ£°å 
const int N = 1e6 + 10;
int n;
int q[N] , tmp[N];
void merge_sort(int q[],int l , int r){
	if(l>=r) return ;
	
	int mid = rand()%(r - l + 1) + l;
	
	merge_sort(q,l,mid);
	merge_sort(q,mid+1,r);
	
	int k =0 , i = l, j = mid+1;
	while(i<=mid && j <=r) 
		if(q[i]<=q[j]) tmp[k++] = q[i++];
		else tmp[k++] = q[j++];
	
	while(i<=mid) tmp[k++] = q[i++];
	while(j<=r) tmp[k++] = q[j++];
	
	for(int i = l ,j=0; i<=r; i++,j++) q[i] = tmp[j];
	
}
int main(){
	scanf("%d",&n);
	for(int i =0 ; i < n; i++) scanf("%d",&q[i]);
	merge_sort(q,0,n-1);
	for(int i =0 ; i < n; i++) printf("%d ",q[i]);
	return 0;
}

