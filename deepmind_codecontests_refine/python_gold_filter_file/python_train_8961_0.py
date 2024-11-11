import sys
from collections import deque
input = sys.stdin.readline

def bfs(root):
	q = deque()
	q.append(root)
	path = []
	while len(q)!=0:
		e = q.popleft()
		path.append(e)
		vis[e] = 1
		if not vis[c[e]]:
			q.append(c[e])
		else:
			return path,c[e]

n = int(input())
a = list(map(int,input().split()))
c = [-1]*n
for i in range(n):
	c[i]=a[i]-1
vis = [0]*n
ans = {}
for i in range(n):
	if not vis[i]:
		p,e = bfs(i)
		# print (p,e,ans)
		if e in ans:
			for j in p:
				ans[j] = ans[e]
			continue 
		flag = 1
		for j in p:
			if flag:
				ans[j] = e+1
			else:
				ans[j] = j+1
			if j==e:
				flag = 0
for i in range(n):
	print (ans[i],end =" ")
print ()
