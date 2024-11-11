def main():
    N, M = map(int, input().split())
    edges = []
    
    for _ in range(M):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        edges.append([a,b,c])

    d = [float('inf')] * N
    d[0] = 0

    for i in range(N-1):
        for edge in edges:
            d[edge[1]] = min(d[edge[1]], d[edge[0]] - edge[2])

    ans = d[N-1]
    for edge in edges:
        d[edge[1]] = min(d[edge[1]], d[edge[0]] - edge[2])

    if ans == d[N-1]:
        print(-ans)
    else:
        print(inf)


main()