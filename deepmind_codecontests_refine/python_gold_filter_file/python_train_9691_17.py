n,d = map(int,input().split())
a=list(map(int,input().split()))
r,c = 0,2
for i in range(n-1):
	r = abs(a[i]-a[i+1])
	if r > 2*d:
		c+=2
	if r==2*d:
		c+=1
print(c)