n, m = tuple(map(int, input().split(' ')))
vb = set()
hb = set()
for k in range(m):
	i, j = tuple(map(int, input().split(' ')))
	hb.add(i)
	vb.add(j)
c = 0
for i in range(1, n//2):
	c += 1 if i not in hb else 0
	c += 1 if n-i-1 not in hb else 0
	c += 1 if i not in vb else 0
	c += 1 if n-i-1 not in vb else 0
c += 1 if n%2==1 and (n//2+1 not in hb or n//2+1 not in vb) else 0
print(c)
