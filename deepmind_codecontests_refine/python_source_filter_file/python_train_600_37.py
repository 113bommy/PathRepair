import sys
from heapq import heapify, heappop, heappush

def solve():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    Edge = [[] for i in range(N)]
    for i in range(1, N):
        Edge[i].append((0, i - 1))
    for _ in range(M):
        L, R, C = map(int, input().split())
        Edge[L-1].append((C, R-1))
    
    Dist = [-1] * N
    Q = []
    heapify(Q)
    heappush(Q, (0, 0))
    while Q:
        nowcost, nownode = heappop(Q)
        if Dist[nownode] == -1:
            Dist[nownode] = nowcost
            for addcost, nextnode in Edge[nownode]:
                if Dist[nownode] == -1:
                    heappush(Q, (nowcost + addcost, nextnode))
    print(Dist[N-1])

    return 0

if __name__ == "__main__":
    solve()