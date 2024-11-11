def findCentroids(v, parent):
    # memo[v] = 1  # 要素数
    flag = True
    q = [[~v, parent], [v]]
    visited = [0] * N
    while q:
        V = q.pop()
        if V[0] >= 0:
            visited[V[0]] = 1
            for u in adj[V[0]]:
                if visited[u]:
                    continue
                q.append([~u, V[0]])
                q.append([u])
        else:
            flag = True
            memo[~V[0]] = 1
            #print(~V[0], V[1], adj[~V[0]])
            for u in adj[~V[0]]:
                if u == V[1]:
                    continue
                if (memo[u] > N / 2):
                    flag = False
                memo[~V[0]] += memo[u]
            if N - memo[~V[0]] > N / 2:
                flag = False
            if flag:
                centroids.append(~V[0])
            #print(~V[0], memo)


t = int(input())
for _ in range(t):
    N = int(input())
    adj = [[] for _ in range(N)]
    for _ in range(N-1):
        x, y = map(lambda x: int(x)-1, input().split())
        adj[x].append(y)
        adj[y].append(x)

    # memo[v]: 根をvとした時の値をメモ
    memo = [None]*N
    centroids = []

    findCentroids(0, N)
    centroids.sort()

    if len(centroids) == 1:
        print(1, adj[0][0]+1)
        print(1, adj[0][0]+1)
    else:
        for j in range(N):
            if j in adj[centroids[0]] and j != centroids[0] and j != centroids[1]:
                print(1 + centroids[0], 1 + j)
                print(1 + centroids[1], 1 + j)
                break
