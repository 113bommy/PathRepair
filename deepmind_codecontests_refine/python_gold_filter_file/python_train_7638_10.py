n,m,d = input().split()
n = int(n)
m = int(m)
d = int(d)
l = []
for i in range(n):
	l1 = [int(x) for x in input().split()]
	l +=l1
l.sort()
mid = l[int((n*m)/2)]
for i in range(len(l)):
	l[i] = abs(l[i]-mid)
s = sum(l)
if s%d == 0:
	print(int(s/d))
else:
	print(-1)