n=int(input())
l=[int(x) for x in input().split()]
value=0
inc=10**10
for t in range(1, 105):
	g=0
	for i in range(n):
		g+=max(0, abs(l[i]-t)-1)
	if g<inc:
		inc=g
		value=t
print(value, inc)