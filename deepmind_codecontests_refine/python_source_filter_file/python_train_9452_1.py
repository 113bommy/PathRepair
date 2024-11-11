import sys
input = sys.stdin.buffer.readline

def main():
    N,M,P = map(int,input().split())
    
    def BellmanFord(edges,v,source):
        INF = float("inf")
        dist = [INF for _ in range(v)]
        dist[source-1] = 0
        for i in range(2*v+1):
            for now,fol,cost in edges:
                if (dist[now] != INF and dist[fol]>dist[now]+cost):
                    dist[fol] = dist[now]+cost
                    if i > v-1:
                        dist[fol] = -INF
        if dist[fol] == -INF:
            return -1
        else:
            return max(0,-1*dist[v-1])
    
    edges = []
    for _ in range(M):
        a,b,c = map(int,input().split())
        edges.append((a-1,b-1,P-c))
    
    print(BellmanFord(edges,N,1))

if __name__ == "__main__":
    main()
