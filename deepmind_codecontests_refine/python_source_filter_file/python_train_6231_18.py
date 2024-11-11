import sys


def input(): return sys.stdin.readline().strip()


N, M = (list)(map(int, input().split()))
edge = []

for _ in range(M):
    edge.append((list)(map(int, input().split())))


inf = 10**15

d = [inf]*(N+1)
d[1] = 0
ans = inf
for i in range(N-1):
    for a, b, c in edge:
        c = -c
        new_d = d[a]+c
        if d[a] != inf and d[b] > new_d:
            d[b] = new_d

for a, b, c in edge:
    c = -c
    new_d = d[a]+c
    if d[b] < new_d:
        d[b] = new_d
        if b == N:
            print('inf')
            exit()
print(-d[-1])
