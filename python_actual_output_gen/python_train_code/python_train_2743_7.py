N,K = map(int, input().split())
A = list(map(int, input().split()))

l,r = 0,max(A)
while l<r:
	m = (l+r)//2
	s = sum([a//m+(not a%m==0)-1 for a in A])
	if s <= K:
		r = m
	else:
		l = m+1
print(r)