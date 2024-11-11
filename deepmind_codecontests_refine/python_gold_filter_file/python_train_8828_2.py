import sys
sys.setrecursionlimit(100000)

N, M = map(int, input().split())
Edge = [[]for _ in range(N)]
Far = [-1]*N
for _ in range(M):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    Edge[x].append(y)


def long(x):
    if len(Edge[x]) == 0:
        Far[x] = 0
        return 0
    if Far[x] >= 0:
        return Far[x]
    r = 0
    for i in Edge[x]:
        l = long(i) + 1
        r = max(r, l)
    Far[x] = r
    return r


for i in range(N):
    long(i)
print(max(Far))


