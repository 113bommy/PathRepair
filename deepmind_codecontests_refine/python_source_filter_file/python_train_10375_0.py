from sys import stdin
from collections import defaultdict
import heapq

n = int(stdin.readline())
a = [[] for _ in range(n)]
for _ in range(n-1):
    e = stdin.readline().split(' ')
    u, v = int(e[0]), int(e[1])
    a[u-1].append(v-1)
    a[v-1].append(u-1)


leaves = [i for i in range(n) if len(a[i]) == 1]


def dfs_from(root):
    depth = defaultdict(int)
    child = {}
    parent = defaultdict(lambda: -1)
    stack = [root]
    visited = [False for _ in range(n)]
    while len(stack) > 0:
        crt = stack[-1]
        if visited[crt]:
            stack.pop(-1)
            if len(a[crt]) > 1:  # not a leaf
                child[crt], depth[crt] = max([(c, depth[c]+1) for c in a[crt]
                                              if c != parent[crt]],
                                             key=lambda x: x[1])
            else:
                child[crt] = -1
                depth[crt] = 0
            continue

        visited[crt] = True
        for next in a[crt]:
            if next != parent[crt]:
                stack.append(next)
                parent[next] = crt

    return depth, child


first_choice = leaves[0]
d1, child1 = dfs_from(first_choice)

root = max([(leaf, d1[a[leaf][0]]) for leaf in leaves],
           key=lambda leaf_depth: leaf_depth[1])[0]
while child1[root] != -1:
    root = child1[root]
depth, child = dfs_from(root)

solution = [1]
pq = []
for k, v in depth.items():
    heapq.heappush(pq, (-v, k))

seen = [False for _ in range(n)]
seen[root] = True

while len(pq) > 0:
    _, best = heapq.heappop(pq)
    if seen[best]:
        continue
    path = []
    c = best
    s = 0
    while c != -1:
        seen[c] = True
        c = child[c]
        s = s+1
    s = s + solution[-1]
    solution.append(s)


for _ in range(n - min(len(solution), n)):
    solution.append(n)

print(' '.join([str(s) for s in solution]))
