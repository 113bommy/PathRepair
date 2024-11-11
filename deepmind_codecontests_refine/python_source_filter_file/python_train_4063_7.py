# It took me about 40 minutes to finsih this assignment.
# The task itself is relatively simple, since we have sample code on handouts.
# One problem I met was that in case 22, I had a "RecursionError" (maximum recursion depth exceeded in comparison).
# The solution was simple: import sys, and add a line "sys.setrecursionlimit(100000)".

#import sys

line = input().split()
n = int(line[0])
q = int(line[1])
mat = [0]*n
for i in range(n):
	mat[i]=i
#sys.setrecursionlimit(100000)

def root(a):
	if mat[a]==a:
		return a
	else:
		mat[a] = root(mat[a])
		return mat[a]

def union(a, b):
	mat[root(a)]=root(b)

def is_same(a,b):
	if root(a) == root(b):
		return 1
	else:
		return 0

for i in range(q):
	line = input().split()
	a = int(line[0])
	line[1]=int(line[1])-1
	line[2]=int(line[2])-1
	if a==0:
		union(mat[line[1]],mat[line[2]])
	if a==1:
		print(is_same(mat[line[1]],mat[line[2]]))