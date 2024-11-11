n,d = map(int,input().split())
l=list(map(int,input().split()))
k,c = 0,2
for i in range(n-1):
	k= abs(l[i]-l[i+1])
	if k > 2*d:
		c+=2
	if l==2*d:
		c+=1
print(c)