import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, M, P = map(int, input().split())

edges = []
for _ in range(M):
    a, b, c = map(int, input().split())
    edges.append([a-1, b-1, -c+P])


def bellnabFord(edges, src, N):
    inf = float('inf')
    dist = [inf for i in range(N)]
    dist[src] = 0

    for i in range(2*N):
        for s, d, c in edges:
            if s != inf and dist[d] > dist[s]+c:
                dist[d] = dist[s]+c
                if i >= N:
                    dist[d] = float('inf')

            if i == N-1:
                prev = dist[-1]
    return (prev, dist[-1])


prev, dist = bellnabFord(edges, 0, N)
if prev != dist:
    ans = -1
else:
    ans = max(0, -dist)
print(ans)
