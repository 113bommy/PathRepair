import sys
input = sys.stdin.readline
import heapq

def main():
    N,M = map(int,input().split())
    INF = 10**10+1
    root = [[] for _ in range(N)]
    for i in range(N-1):
        root[i+1].append((0,i))
    for _ in range(M):
        l,r,c = map(int,input().split())
        root[l-1].append((c,r-1))
    
    dist = [INF for _ in range(N)]
    q = [(0,0)]
    dist[0] = 0
    while q:
        d,now = heapq.heappop(q)
        if dist[now] < d:
            continue
        for cost,fol in root[now]:
            _d = d+cost
            if dist[fol] > _d:
                dist[fol] = _d
                heapq.heappush(q,(_d,fol))

    if dist[-1] == INF:
        print(-1)
    else:
        print(dist[-1])

if __name__ == "__main__":
    main()
