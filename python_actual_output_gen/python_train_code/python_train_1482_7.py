n, m, q = map(int, input().split())
s = input()
t = input()
c = [0 for i in range(n+1)]
b = 0
for i in range(n-m+1):
	#print (s[i:i+m])
	if s[i:i+m] == t:
		c[i+1] = 1
for i in range(1,n):
	c[i] += c[i-1]
for i in range(q):
	l, r = map(int, input().split())
	if r-l+1 < m:
		print (0)
	else:
		if l == 1:
			print (c[r-m+1])
		else:
			print (c[r-m+1]-c[l-1])