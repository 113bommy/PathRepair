n,k=map(int,input().split())
l=sorted(map(int,input().split()))
c,s=0,0
for x in range(k):
	a,b,f=l[c],l[c]-s,0
	print(b)
	s+=b
	for y in range(x+1,n):
		if l[y]!=a:c=y;f=1;break
	if f==0:break
for z in range(k-x-1):print(0)