from collections import defaultdict, deque

N, M = map(int, input().split())
E = defaultdict(list)
for _ in range(M):
    u, v = map(int, input().split())
    E[u].append(v+N)
    E[u+N].append(v+2*N)
    E[u+2*N].append(v)
S, T = map(int, input().split())
R = [-1 for _ in range(3*N)]
R[S-1] = 0

q = deque()
q.append(S)
while q:
    n = q.popleft()
    if n == T:
        break
    for t in E[n]:
        if R[t-1] < 0:
            R[t-1] = R[n-1] + 1
            q.append(t)
print(-1 if R[T-1] < 0 else R[T-1] // 3)