from collections import defaultdict
import sys
sys.setrecursionlimit(500000)
test = 0


def countleaf(tree, n, leafs):
    leafs[n] = 1 if len(tree[n]) == 0 else 0

    for i in tree[n]:
        leafs[n] += countleaf(tree, i, leafs)
    
    return leafs[n]
    
n = int(input())
edges = list(map(int, input().split()))
tree = [[] for i in range(n)]

leafs = [0] * n

for i, e in enumerate(edges):
    tree[e - 1] += [i + 1]

if test: print(tree)

for i in range(n - 1, -1, -1):
    if not tree[i]:
        leafs[i] = 1
    else:
        leafs[i] = sum(leafs[j] for j in tree[i])

print(*leafs)
