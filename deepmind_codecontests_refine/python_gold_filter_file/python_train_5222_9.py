n, h, m=map(int, input().split())
a=[3000]*55
for _ in range(m):
	l, r, x=map(int, input().split())
	for i in range(l, r+1):
		if x*x<a[i]:
			a[i]=x*x
s=0
for i in range(1, n+1):
	if a[i]==3000:
		s+=h*h
	else:
		s+=a[i]
print(s)