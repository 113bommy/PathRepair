N, M, P = map(int, input().split())

edges = [[] for _ in range(N)]
edgesR = [[] for _ in range(N)]
E = []
for _ in range(M):
    fr, to, c = map(int, input().split())
    fr -= 1
    to -= 1
    E.append((fr, to, -(c - P)))
    edges[fr].append(to)
    edgesR[to].append(fr)

def dfs(edges, s):
    visited = [False] * N
    st = [s]
    visited[s] = True
    while st:
        for to in edges[st.pop()]:
            if not visited[to]:
                st.append(to)
                visited[to] = True
    return visited

canGo = dfs(edges, 0)
canBack = dfs(edgesR, N - 1)

minDist = [10**18] * N
minDist[0] = 0
for i in range(N + 1):
    for fr, to, c in E:
        d = minDist[fr] + c
        if minDist[to] > d:
            if i == N and canGo[fr] and canBack[to]:
                print('-1')
                exit()
            minDist[to] = d

print(max(0, -minDist[N - 1]))
