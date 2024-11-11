import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

N,M,P = map(int,input().split())
edge = []
for i in range(M):
    A,B,C = map(int,input().split())
    edge.append([A-1,B-1,P-C])

def Bellman_Ford(edges, start, N):
    inf = float("inf")
    # dist[i]: 頂点iまでの最短距離
    dist = [inf for i in range(N)]
    dist[start] = 0

    for i in range(N+N):
        for a,b,c in edges:
            if a != inf and dist[b] > dist[a] + c:
                dist[b] = dist[a] + c
                # startからgoalまでに負閉路がある場合
                if i >= N:
                    dist[b] = -inf
        # 一回目のベルマンフォード法の結果
        if i == N-1:
            first_time = dist[-1]
    # (一回目,二回目)
    return first_time, dist[-1]

first,second = Bellman_Ford(edge, 0, N)
if first != second:
    answer = -1
else:
    answer = max(0,-second)

print(answer)