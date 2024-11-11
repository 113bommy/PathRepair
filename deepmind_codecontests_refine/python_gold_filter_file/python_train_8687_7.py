
n,m,k = map(int,input().split())
a = []
for i in range(m+1):
	a.append(bin(int(input())))
res = 0
t1 = a[m][2:].rjust(n,'0')
for i in range(m):
	diff = 0
	t2 =a[i][2:].rjust(n,'0')
	for u, v in zip(t1,t2):
		diff+= u!=v
	res+= diff<=k

print(res)
