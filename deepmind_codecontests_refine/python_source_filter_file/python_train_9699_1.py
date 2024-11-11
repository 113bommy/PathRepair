n, m = map(int, input().split())
up = [[0 for j in range(m)] for i in range(n)]
ldw = [[0 for j in range(m)] for i in range(n)]
lup = [[0 for j in range(m)] for i in range(n)]

v = []

for i in range(n):
    v.append(input())

for i in range(n):
    for j in range(m):
        if not i or v[i][j] != v[i - 1][j]:
            up[i][j] = 1
            lup[i][j] = (1 if (not j or v[i][j] != v[i][j - 1]) else lup[i][j - 1] + 1)
        else:
            up[i][j] = up[i - 1][j] + 1
            lup[i][j] = min(lup[i - 1][j], (1 if (not j or v[i][j] != v[i][j - 1]) else lup[i][j - 1] + 1))

for i in range(n - 1, -1, -1):
    for j in range(m):
        if i == n - 1 or v[i][j] != v[i + 1][j]:
            ldw[i][j] = (1 if (not j or v[i][j] != v[i][j - 1]) else ldw[i][j - 1] + 1)
        else:
            ldw[i][j] = min(ldw[i + 1][j], (1 if (not j or v[i][j] != v[i][j - 1]) else ldw[i][j - 1]) + 1)

ans = 0

for i in range(1, n - 1):
    for j in range(m):
        if v[i][j] == v[i + 1][j]:
            continue
        h = up[i][j]
        up_st = i - h
        if up_st < 0 or up[up_st][j] < h:
            continue
        dw_st = i + h
        if dw_st >= n or up[dw_st][j] != h:
            continue
        w = min(lup[i][j], ldw[up_st - h + 1][j], lup[dw_st][j])
        ans += w

print(ans)
