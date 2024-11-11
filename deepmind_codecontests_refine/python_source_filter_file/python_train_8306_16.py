#Solve this by Rerooting
import sys
from itertools import accumulate
import queue
input = sys.stdin.buffer.readline

N = int(input())
adj = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    adj[a-1].append(b-1)
    adj[b-1].append(a-1)


#bfs、直すの面倒なので読み替えて。
dfs_order = []
parent = [-1] * N
root = 0
#queue
stack = queue.Queue()
stack.put(root)
while not stack.empty():
    node = stack.get()
    dfs_order.append(node)
    for next_node in adj[node]:
        if next_node != parent[node]:
            parent[next_node] = node
            stack.put(next_node)

dp1 = [1] * N
for node in reversed(dfs_order):
    for next_node in adj[node]:
        if next_node != parent[node]:
            dp1[node] = max(dp1[node], dp1[next_node] + 1)

dp2 = [1] * N
for node in dfs_order:
    around = [dp1[next_node]+1 if next_node != parent[node] else dp2[node] for next_node in adj[node]]
    from_left = [1] + list(accumulate(around, max))[:-1]
    from_right = list(accumulate(reversed(around), max))[-2::-1] + [1]
    without = [max(l, r) + 1 for l, r in zip(from_left, from_right)]
    for next_node, value in zip(adj[node], without):
        if next_node != parent[node]:
            dp2[next_node] = value

dp = [v1 + v2 - 1 for v1, v2 in zip(dp1, dp2)]

length = max(dp)

if length % 3 == 2:
    print("Second")
else:
    print("First")
