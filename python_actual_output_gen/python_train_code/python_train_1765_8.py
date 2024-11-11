n,s=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
flag="YES"
if a[0]!=1:
	flag="NO"
else:
	c=0
	for i in range(n):
		if a[i]==1 and b[i]==1:
			c=1
	if a[s-1]!=1 and b[s-1]!=1 and c==1:
		flag="NO"
	if c==0 and a[s-1]!=1:
		flag="NO"
print(flag)