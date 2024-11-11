from collections import deque

N = int(input())

adj = [[] for _ in range(N)]
for i in range(N):
    S = input()
    for j, s in enumerate(S):
        if s == '1':
            adj[i].append(j)

ans = 0
for i in range(N):
    que = deque()
    que.append(i)
    seen = [0] * N
    seen[i] = 1
    while que:
        v = que.pop()
        for u in adj[v]:
            if seen[u] == 0:
                que.append(u)
                seen[u] = -seen[v] - 1 if seen[v] > 0 else -seen[v] + 1
            else:
                if seen[v] * seen[u] > 0:
                    print(-1)
                    exit()
    ans_i = max(max(seen), -min(seen))
    ans = max(ans, ans_i)
print(ans)
