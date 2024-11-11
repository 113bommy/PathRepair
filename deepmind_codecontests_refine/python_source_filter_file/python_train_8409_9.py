n=int(input()) 
m=10**5+4 
for i in range(n,m): 
	lst=[] 
	if all(( i % j) !=0 for  j in range(2,int(n**0.5//1+1))): 
		print(i,j) 
		break