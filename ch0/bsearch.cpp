//���仮��Ϊ[l , mid][mid + 1 ,r] 
int bsearch_1(int l ,int r){
	
	while(l < r){
		
		int mid = (l + r)>>1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	//���ҽ��Ϊ l = r 
	return 1;
}

//���仮��Ϊ[l,mid - 1][mid , r ]
int bsearch_2(int l ,int r){
	
	while(l < r){
		
		int mid = (l + r + 1 )>>1 ;
		if(check(mid)) l =mid;
		else  r = mid -1;
	}
	return 1;
} 
