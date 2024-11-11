import sys
from operator import itemgetter

inf = 1<<30

def solve():
    N, M = map(int, sys.stdin.readline().split())

    cost = [[inf]*N for i in range(N)]
    for u in range(N):
        cost[u][u] = 0

    for i in range(M):
        si, ti, di = map(int, sys.stdin.readline().split())
        cost[si][ti] = di

    res = WarshallFloyd(N, cost)

    if res is None:
        print('NEGATIVE CYCLE')
    else:
        for i in range(N):
            print(*[res[i][j] if res[i][j] < inf else 'INF' for j in range(N)])


def WarshallFloyd(N, cost):
    dist = [[inf]*N for i in range(N)]

    for i in range(N):
        for j in range(N):
            dist[i][j] = cost[i][j]

    for k in range(N):
        for i in range(N):
            for j in range(N):
                if dist[i][k] < inf and dist[k][j] < inf:
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    if any(dist[i][i] < 0 for i in range(N)):
        return None
    else:
        return dist

if __name__ == '__main__':
    solve()