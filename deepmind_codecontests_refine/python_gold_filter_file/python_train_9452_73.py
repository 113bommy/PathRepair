import sys
input = sys.stdin.readline

def main():
    N,M,P = map(int,input().split())
    edges = []


    for _ in range(M):
        A,B,C = map(int,input().split())
        edges.append([A-1,B-1,P-C])

    inf = 10000*(10**5)
    dist = [inf for _ in range(N)]
    dist[0] = 0

    for i in range(N-1):
        for edge in edges:
            if dist[edge[1]] > dist[edge[0]] + edge[2]:
                dist[edge[1]] = dist[edge[0]]+edge[2]
    ans = -1*dist[N-1]
    
    for i in range(N-1):
        for edge in edges:
            if dist[edge[1]] > dist[edge[0]]+edge[2]:
                dist[edge[1]] = dist[edge[0]]+edge[2]
    ans2 = -1*dist[N-1]

    if ans2<=ans: 
        print(max(0,ans))         
    else:
        print(-1)

if __name__ == "__main__":
    main()
