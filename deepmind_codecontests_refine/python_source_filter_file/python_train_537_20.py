for tc in range(int(input())):
	n,k,d = map(int,input().split())
	a = list(map(int,input().split()))
	ans = n
	for i in range(0,n-d+1):
		ans = min(len(set(a[i:i+8])),ans)
	print(ans)
 		   	  	 	 	  	  		  	  			 	