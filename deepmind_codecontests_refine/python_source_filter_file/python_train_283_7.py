if __name__ == "__main__":
    n, K= map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    cnt = 0
    c = 1
    for i in range(0,n):
        if a[i]==a[i-1]: 
            c+=1
        elif a[i]<=a[i-1]+K: 
            cnt+=c
            c=1
        else: c= 1
    print(n-cnt)
    
	  			 	 	 	 			  	  	   	  	 	