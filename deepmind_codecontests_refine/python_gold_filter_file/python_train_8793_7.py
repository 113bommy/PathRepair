n,m=map(int,input().split())
a=0
while n<m:
	if m&1==0:
		m//=2
	else:	
		m+=1
	a+=1
print (a+n-m)
