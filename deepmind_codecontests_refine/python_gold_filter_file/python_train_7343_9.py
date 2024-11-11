n=int(input())
tailles=list(map(int,input().split()))
a=1
while a!=-1:
	a=-1
	b=-1
	
	i=0
	while i!=n-1 and tailles[i+1]>=tailles[i]:
		i+=1
	
	if i!=n-1:
		a=1
		print(i+1,i+2)
		
		tailles[i],tailles[i+1]=tailles[i+1],tailles[i]
