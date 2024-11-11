q=int(input())
for i in range(q):
	n=int(input())
	l=list(map(int,input().split()))
	l.sort()
	c=0;
	for i in range(n-1):
		if(l[i]+1==l[i+1]):
			c+=1
	if(c>0):
		print(2)
	else:
		print(1)
