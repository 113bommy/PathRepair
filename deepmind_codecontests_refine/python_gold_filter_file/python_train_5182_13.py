n, k = map(int, input().split())
P = [int(x)-1 for x in input().split()]
C = [int(x) for x in input().split()]

vis = [0 for i in range(n+1)]
	

res = -10000000000000000000000
for i in range(0,n):
	if vis[i] == 0:
		su = 0
		vis[i] = 1
		v = []
		v.append(C[i])
		su += C[i]
		x = P[i]
		while x != i:
			vis[x] = 1
			su += C[x]
			v.append(C[x])
			x = P[x]
		vs = len(v)
		for ii in range(vs):
			umm = 0
			for j in range(vs):
				x = (ii+j)%vs
				umm += v[x]
				steps = 1+(x-ii+vs)%vs
				if k >= vs:
					if(su > 0):
						r = max((k-steps)//vs,0)
						res = max(res, r*su + umm)
					else:
						res = max(res,umm)
				else:
					if steps <= k:
						res = max(res,umm)


print(res)