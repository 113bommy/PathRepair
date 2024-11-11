n,k = map(int,input().split())
a = list(map(int,input().split()))
s = []
c = 0
for i in range(k):
	if (n//a[i])*a[i]>c:
		c = (n//a[i])*a[i]
		s = [i+1,n//a[i]]

if n == 0:
	print(a.index(min(a))+1,0)
else:
	print(*s)
