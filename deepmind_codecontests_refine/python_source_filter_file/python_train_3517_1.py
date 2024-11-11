N, M, K = map(int, input().split())
F = [[] for _ in range(N)]
B = [[] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    F[a].append(b)
    F[b].append(a)

for _ in range(K):
    c, d = map(int, input().split())
    c, d = c - 1, d - 1
    B[c].append(d)
    B[d].append(c)


D = {}
parent = [-1] * N
visited = [False] * N
for root in range(N):
    if visited[root]:
        continue

    D[root] = set([root])
    stack = [root]
    while stack:
        n = stack.pop()
        visited[n] = True
        parent[n] = root

        for to in F[n]:
            if visited[to]:
                continue
            D[root].add(to)
            stack.append(to)

ans = [0] * N
for iam in range(N):
    group = D[parent[iam]]
    tmp_ans = len(group) - len(F[iam]) - 1
    for block in B[iam]:
        if block in group:
            tmp_ans -= 1
    ans[iam] = tmp_ans

print(*ans, sep=' ')
