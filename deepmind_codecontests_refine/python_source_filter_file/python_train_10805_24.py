from collections import deque

N = int(input())
A = [['nul']] + [list(map(int, input().split())) for _ in range(N)]

# how many times each player matched
c = [0 for _ in range(N + 1)]
predeq = deque([])

for i in range(1, N + 1):
    j = A[i][c[i]]
    if i == A[j][c[j]] and i < j:
        predeq.append((i, j))

ans = 0
while predeq:
    print(predeq)
    postdeq = deque([])
    for i, j in predeq:
        c[i] += 1
        c[j] += 1
        if c[i] < N - 1:
            k = A[i][c[i]] # next player
            if A[k][c[k]] == i:
                postdeq.append((i, k))
        if c[j] < N - 1:
            k = A[j][c[j]]
            if A[k][c[k]] == j:
                postdeq.append((j, k))
    ans += 1
    predeq = postdeq

if c == [0] + [N - 1] * N:
    print(ans)
else:
    print(-1)
