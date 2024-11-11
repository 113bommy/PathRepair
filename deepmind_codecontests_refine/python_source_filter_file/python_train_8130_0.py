import sys
from math import *

def minp():
	return sys.stdin.readline().strip()

n = int(minp())
m = [None]*n
k = [None]*3
dp = [None]*3
dp[0] = [None]*(n*n)
dp[1] = [None]*(n*n)
dp[2] = [None]*(n*n)
path = [None]*(n*n)
for i in range(n):
	m[i] = list(map(int, minp().split()))
	for j in range(n):
		path[m[i][j]-1] = (i,j)
for z in range(3):
	k_ = [None]*n
	for i in range(n):
		kk = [None]*n
		for j in range(n):
			kkk_ = [None]*3
			for zz in range(3):
				kkk = [None]*n
				for w in range(n):
					kkk[w] = [(1000000,0)]*n
				kkk_[zz] = kkk
			kk[j] = kkk_
		k_[i] = kk
	k[z] = k_

q = [0]*(10*n*n)
qr = 0
km = [(1,2),(1,-2),(-1,2),(-1,-2),(2,1),(2,-1),(-2,1),(-2,-1)]
sm = [(1,1),(1,-1),(-1,1),(-1,-1)]
lm = [(0,1),(0,-1),(-1,0),(1,0)]
mm = [km,sm,lm]
for z in range(3):
	for i in range(n):
		for j in range(n):
			#print('========')
			ql = 0
			qr = 1
			q[0] = (z, i, j, (0,0))
			kc = k[z][i][j]
			kc[z][i][j] = (0, 0)
			while ql < qr:
				t, x, y, dd = q[ql]
				#print(t,x,y,dd)
				d = kc[t][x][y]
				ql += 1
				if d != dd:
					continue
				dd = (d[0]+1, d[1]+1)
				for tt in range(3):
					if t != tt and kc[tt][x][y] > dd:
						kc[tt][x][y] = dd
						q[qr] = (tt,x,y,dd)
						qr += 1
				dd = (d[0]+1,d[1])
				if t == 0:
					for w in mm[t]:
						xx,yy = w[0]+x,w[1]+y
						if xx >= 0 and xx < n and yy >= 0 and yy < n:
							if kc[t][xx][yy] > dd:
								kc[t][xx][yy] = dd
								q[qr] = (t,xx,yy,dd)
								qr += 1
				else:
					for w in mm[t]:
						for hm in range(n*2):
							xx,yy = w[0]*hm+x,w[1]*hm+y
							if xx >= 0 and xx < n and yy >= 0 and yy < n:
								if kc[t][xx][yy] > dd:
									kc[t][xx][yy] = dd
									q[qr] = (t,xx,yy,dd)
									qr += 1
							else:
								break
dp[0][0] = (0,0)
dp[1][0] = (0,0)
dp[2][0] = (0,0)
for i in range(0,n*n-1):
	x,y = path[i]
	xx,yy = path[i+1]
	for z in range(3):
		for j in range(3):
			dist = k[z][x][y][j][xx][yy]
			if dp[j][i] != None:
				nd = (dp[j][i][0]+dist[0],dp[j][i][1]+dist[1])
				if dp[z][i+1] == None:
					dp[z][i+1] = nd
				else:
					dp[z][i+1] = min(dp[z][i+1],nd)
for j in range(n*n-1,n*n):
	qq = [dp[i][j] if dp[i][j] != None else (1000000,0) for i in range(3)]
	qm = min(qq)
	#print(j,qm)
	print(qm[0], qm[1])