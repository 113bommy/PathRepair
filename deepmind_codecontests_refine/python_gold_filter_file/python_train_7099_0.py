t = int(input())
for i in range(t):
    n = int(input())
    d = [int(x) for x in input().split()]
    s = [0] * n
    used = [-1] * n

    for i in range(n):
        if used[i] == -1:
            u, v = i, d[i] - 1
            while True:
                s[i] += 1
                used[u] = i
                u, v = v, d[v] - 1
                if u == i:
                    break
    res = []
    for j in range(n):
        res.append(s[used[d[j] - 1]])
    print(*res)
