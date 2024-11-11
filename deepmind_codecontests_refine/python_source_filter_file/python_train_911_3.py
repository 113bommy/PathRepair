import sys
input = sys.stdin.readline
N = int(input())
P = list(map(lambda x:int(x)-1,input().split()))

costs = [0]*(N*N)
for i in range(N):
    for j in range(N):
        costs[i*N+j] = min(i,j,N-1-i,N-1-j)
exist = [1]*(N*N)

from collections import deque
ans = 0
for p in P:
    ans += costs[p]
    exist[p] = 0
    q = deque([p])
    while q:
        p = q.popleft()
        y,x = divmod(p,N)
        if x < N-1:
            np = p + 1
            if costs[np] > costs[p] + exist[p]:
                costs[np] = costs[p] + exist[p]
                q.append(np)
        elif x > 0:
            np = p - 1
            if costs[np] > costs[p] + exist[p]:
                costs[np] = costs[p] + exist[p]
                q.append(np)
        if y < N-1:
            np = p + N
            if costs[np] > costs[p] + exist[p]:
                costs[np] = costs[p] + exist[p]
                q.append(np)
        elif y > 0:
            np = p - N
            if costs[np] > costs[p] + exist[p]:
                costs[np] = costs[p] + exist[p]
                q.append(np)
print(ans)