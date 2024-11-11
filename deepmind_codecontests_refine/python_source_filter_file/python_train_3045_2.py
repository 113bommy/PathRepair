import sys;input=sys.stdin.readline
N, M = map(int, input().split())
n1, n2, n3 = map(int, input().split())
G = [set() for _ in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    G[u].add(v)
    G[v].add(u)

cl = [-1 for _ in range(N+1)]
vs = set()
Y = []
for i in range(1, N+1):
    if i in vs:
        continue
    cl[i] = 0
    tmp = [[i], []]
    stack = [i]
    vs.add(i)
    while stack:
        v = stack.pop()
        for u in G[v]:
            if cl[u] == cl[v]:
                print("NO")
                sys.exit()
            if u in vs:
                continue
            cl[u] = 1-cl[v]
            tmp[cl[u]].append(u)
            vs.add(u)
            stack.append(u)
    Y.append(tmp)
k = len(Y)
dp = [[0]*(N+1) for _ in range(k+1)]
dp[0][0] = 1
for i in range(k):
    y1, y2 = len(Y[i][0]), len(Y[i][1])
    for j in range(N, -1, -1):
        tmp = 0
        if j-y1>=0:
            tmp = dp[i][j-y1]
        if j-y2>=0:
            tmp = dp[i][j-y2] | tmp
        dp[i+1][j] = tmp
if dp[-1][n2] == 0:
    print("NO")
    sys.exit()
mch = n2
ans = [0] * (N+1)
for i in range(k-1, -1, -1):
    y1, y2 = len(Y[i][0]), len(Y[i][1])
    if mch>y1 and dp[i][mch-y1]:
        for u in Y[i][0]:
            ans[u] = 2
        for u in Y[i][1]:
            if n1 > 0:
                ans[u] = 1
                n1 -= 1
            else:
                ans[u] = 3
        mch -= y1
    else:
        for u in Y[i][0]:
            if n1 > 0:
                ans[u] = 1
                n1 -= 1
            else:
                ans[u] = 3
        for u in Y[i][1]:
            ans[u] = 2
        mch -= y2
print("YES")
print("".join(str(u) for u in ans[1:]))



