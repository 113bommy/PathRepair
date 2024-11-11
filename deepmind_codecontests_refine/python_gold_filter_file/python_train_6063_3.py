from collections import deque


def process():
    q = deque()
    q.append(0)
    s = []
    seen = [0] * n
    while len(q) > 0:
        node = q.popleft()
        s.append(node)
        seen[node] = 1
        flag = False
        for c in connections[node]:
            if not seen[c]:
                q.append(c)
                distance[c] = distance[node] + 1
    seen = [0] * n
    while len(s) > 0:
        node = s.pop()
        seen[node] = 1
        for c in connections[node]:
            if not seen[c]:
                children[c] += children[node] + 1
    for i in range(n):
        scores[i] = distance[i] - children[i]


n, k = list(map(int, input().split()))
connections = [[] for _ in range(n)]

for i in range(n - 1):
    u, v = list(map(int, input().split()))
    connections[u - 1].append(v - 1)
    connections[v - 1].append(u - 1)

scores = [0] * n
distance = [0] * n
children = [0] * n

process()
scores.sort()
# print("distance {}\n children {}\n".format(distance, children))

print(sum(scores[-k:]))
