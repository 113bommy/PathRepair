import math
q=int(input())
w=list(map(int,input().split()))
l=[]
g=w[-1]
for i in range(q-2,-1,-1):
	k=math.gcd(w[i],g)
	l.append(w[i]*(g/k))
	g=k
g=l[0]
for i in l[1::]:
	g=math.gcd(i,g)
print(g)