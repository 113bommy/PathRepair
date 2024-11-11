import collections
from itertools import combinations
N = int(input())
ab = [tuple(map(int, input().split())) for i in range(N-1)]
M = int(input())
uv = [tuple(map(int, input().split())) for i in range(M)]


def popcount(x):
    x = x - ((x >> 1) & 0x5555555555555555)

    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333)

    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f
    x = x + (x >> 8)
    x = x + (x >> 16)
    x = x + (x >> 32)
    return x & 0x0000007f


G = [[-1]*N for i in range(N)]
for i in range(N-1):
    a, b = ab[i]
    a -= 1
    b -= 1
    G[a][b] = i
    G[b][a] = i

q = collections.deque()

G2 = [[0 for j in range(N)] for i in range(N)]

for i in range(N):
    q.append((i, 0))
    reached = [False]*N
    reached[i] = True
    while(q):
        x, s = q.popleft()
        for y in range(N):
            if G[x][y] == -1 or reached[y]:
                continue
            else:
                G2[i][y] = s | (1 << G[x][y])
                q.append((y, s | 1 << G[x][y]))
                reached[y] = True


ans = 2**(N-1)
ans2 = 0
for i in range(1, 2**M):
    tmp = 2**(N-1) - 1
    for j in range(M):
        if (i >> j) % 2 == 1:
            u, v = uv[j]
            u -= 1
            v -= 1
            tmp &= ~G2[u][v]
    ans2 += ((-1)**(popcount(i)-1)) * (1 << popcount(tmp))
    # print(ans2, i)
print(ans-ans2)
