n = int(input())

A = set()
B = set()
C = set()

cost = {}

for i in range(n):
	l = input().split()
	c = int(l[0])
	vits = l[1]
	
	cost[i] = c
	for k in vits:
		if k == 'A':
			A.add(i)
		elif k == 'B':
			B.add(i)
		else:
			C.add(i)

minmoney = 300001
abc = A&B&C
ab = A&B  #- abc
bc = B&C  #- abc
ac = A&C  #- abc

a = A  #- ab - ac - abc
b = B  #- bc - ab - abc
c = C  #- ac - bc - abc

minc = mina = minb = 100001
for x in a:
	mina = min(mina, cost[x])
	
for x in b:
	minb = min(minb, cost[x])
	
for x in c:
	minc = min(minc, cost[x])
	
minab = minbc = minac = 200001
for x in ab:
	minab = min(minab, cost[x])

for x in bc:
	minbc = min(minbc, cost[x])
	
for x in ac:
	minac = min(minac, cost[x])

minabc = 300001
for x in abc:
	minabc = min(minabc, cost[x])

minmoney = min(minabc, minab+minc, minac+minb, minbc+mina, mina+minb+minc)
if minmoney > 100000:
	print(-1)
else:
	print(minmoney)

