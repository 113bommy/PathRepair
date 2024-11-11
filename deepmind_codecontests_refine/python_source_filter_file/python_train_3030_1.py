from sys import stdin
input=lambda : stdin.readline().strip()
from math import ceil,sqrt,factorial,gcd
from collections import deque
def dfs():
	stack=[1]
	while stack:
		x=stack.pop()
		for i in tree[x]:
			stack.append(i)
			tree[i].remove(x)

n=int(input())
tree={i:set() for i in range(1,n+1)}
for i in range(n-1):
	a,b=map(int,input().split())
	tree[a].add(b)
	tree[b].add(a)
dfs()
l=list(map(int,input().split()))
stack=deque()
stack.append(1)
a=1
flag="Yes"
while stack:
	x=stack.pop()
	s=set()
	for i in range(len(tree[x])):
		s.add(l[a])
		stack.append(l[a])
		a+=1
	if s!=tree[x]:
		flag="No"
		break
print(flag)