#https://codeforces.com/contest/769/problem/C
import collections
lis = input().split()
n,m,k = int(lis[0]),int(lis[1]),int(lis[2])
empty = [[False for i in range(m)] for j in range(n)]
mainrow,maincol = 0,0
for i in range(n):
	s = input()
	for j in range(m):
		if(s[j]=='.'):
			empty[i][j] = True
		elif (s[j]=='X'):
			empty[i][j] = True
			mainrow = i
			maincol = j
d = [[-1 for i in range(m)] for j in range(n)]
que = collections.deque([(mainrow,maincol)])
d[mainrow][maincol] = 0
changes = [(1,0),(-1,0),(0,1),(0,-1)]
while(que):
	(x,y) = que.popleft()
	for (i,j) in changes:
		xnex = x+i
		ynex = y+j
		if(xnex>=0 and xnex<n and ynex>=0 and ynex<m and empty[xnex][ynex] and d[xnex][ynex]==-1):
			d[xnex][ynex]=d[x][y]+1
			que.append((xnex,ynex))
currrow = mainrow
currcol = maincol
lis = []
if(k%2==0):
	flag = False
	for (i,j) in changes:
		xnex = mainrow+i
		ynex = maincol+j
		if(xnex>=0 and xnex<n and ynex>=0 and ynex<m and empty[xnex][ynex]):
			flag = True
	if(flag):
		while(k):
			if(currrow+1<n and empty[currrow+1][currcol] and d[currrow+1][currcol]<k):
				lis.append('D')
				currrow+=1
			elif(currcol-1>=0 and empty[currrow][currcol-1] and d[currrow][currcol-1]<k):
				lis.append('L')
				currcol-=1
			elif(currcol+1<m and empty[currrow][currcol+1] and d[currrow][currcol+1]<k):
				lis.append('R')
				currcol+=1
			else:
				lis.append('U')
				currrow-=1
			k-=1
		if(currcol == maincol and currrow == mainrow):
			print("".join(lis))
		else:
			print("IMPOSSIBLE WHY")
	else:
		print("IMPOSSIBLE")
else:
	print("IMPOSSIBLE")