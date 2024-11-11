from math import log
import sys
def buildTree(arr): 
	n = len(arr)
	tree = [0]*n + arr
	for i in range(n-1, 0, -1):
		z = int(log(i, 2))	# determines what level of the tree you're at
		if N%2 == 0:
			if z % 2 == 0:
				tree[i] = tree[2*i]^tree[2*i+1]
			else:
				tree[i] = tree[2*i]|tree[2*i+1]
		else:
			if z % 2 == 0:
				tree[i] = tree[2*i]|tree[2*i+1]
			else:
				tree[i] = tree[2*i]^tree[2*i+1]
	return tree

def updateTree(tree, ind, value, n):
	ind += n
	tree[ind] = value
	while ind > 1:
		ind //= 2
		z = int(log(ind, 2))
		if N%2 == 0:
			if z % 2 == 0:
				tree[ind] = tree[2*ind]^tree[2*ind+1]
			else:
				tree[ind] = tree[2*ind]|tree[2*ind+1]
		else:
			if z % 2 == 0:
				tree[ind] = tree[2*ind]|tree[2*ind+1]
			else:
				tree[ind] = tree[2*ind]^tree[2*ind+1]
	return tree

N, m = map(int, sys.stdin.readline().strip().split())
arr = list(map(int, sys.stdin.readline().strip().split()))
tree = buildTree(arr)
for i in range(m):
	ind, val = map(int,sys.stdin.readline().strip().split())
	tree = updateTree(tree, ind-1, val, len(arr))
	print(tree[1])