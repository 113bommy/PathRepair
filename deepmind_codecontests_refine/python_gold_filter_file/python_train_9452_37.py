import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N, M, P = lr()
# 終了時、T*P枚支払う
graph = [lr() for _ in range(M)]

def bellmanford(start, N):
    INF = 10 ** 12
    dist = [-INF] * (N+1) # 1-indexed
    dist[start] = 0
    for i in range(N+N+5):
        for pre, ne, weight in graph:
            if dist[pre] != -INF and dist[pre] + weight - P > dist[ne]:
                dist[ne] = dist[pre] + weight - P
                # n回繰り返してもスコアが更新された場合
                if i > N-1:
                    dist[ne] = INF
    if dist[N] == INF:
        return -1
    else:
        return max(0, dist[N])

answer = bellmanford(1, N)
print(answer)
