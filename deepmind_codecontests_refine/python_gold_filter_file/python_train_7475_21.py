n,q=map(int,input().split())
s=input()
lr=[list(map(int,input().split())) for _ in range(q)]
L=[0]
c=0
for i in range(n-1):
	if s[i]=='A' and s[i+1]=='C':
		c += 1
	L.append(c)
for l,r in lr:
	print(L[r-1]-L[l-1])