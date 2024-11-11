from collections import defaultdict as dc 
# import math
 

 
N = int(input())
for _ in range(N):
	n,m = map(int,input().split())
	res = []
	gress = [0]*(n+1)
	dn = dc(list)
	
	for _ in range(m):
		d,x,y = map(int,input().split())
		if d==1:
			dn[x].append(y)
			gress[y]+=1
		res.append([d,x,y])
	zp = [i for i in range(1,n+1) if gress[i]==0]
	count = 0
	p = [0]*(n+1)
	print(zp,gress)
	while zp:
		u = zp.pop()
		count+=1
		p[u] = count
		for v in dn[u]:
			gress[v]-=1
			if gress[v]==0:
				zp.append(v)
	print(p,zp)
	if count==n:
		print('YES')
		for d,x,y in res:
			if d==1:
				print(x, y)
			elif p[x]<p[y]:
				print(x, y)
			else:
				print(y, x)
	else:
		print('NO')