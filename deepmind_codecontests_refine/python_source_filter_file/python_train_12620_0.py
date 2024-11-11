t = int(input())
l = list(map(int,input().split()))
ans = 0
m = 0
for i in range(t):
	s = 0
	a = l[:]
	for j in range(i,1,-1):
		if a[j]<a[j-1]:
			a[j-1] = a[j]
		s+=a[j-1]
	s+=a[i]
	for k in range(i, t-1):
		if a[k]<a[k+1]:
			a[k+1] = a[k]
		s+=a[k+1]
	if s>ans:
		ans = s
		m = i
for i in range(m,1,-1):
	if l[i] <l[i-1]:
		l[i-1] = l[i]
for i in range(m,t-1):
	if l[i+1]>l[i]:
		l[i+1] = l[i]
print(*l)
