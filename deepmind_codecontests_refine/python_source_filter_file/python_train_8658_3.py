n,l,r = map(int,input().split())
s,m = 0,0
for i in range(1,l+1):
	s += i
for i in range(r):
	m += 2**i
print(s+n-l,end=' ')
print(m+(2**(r-1))*(n-r))