import sys


if __name__ == '__main__':
    lines = sys.stdin.readlines()
    n = int(lines[0])
    rows = [None] * n
    alp = set()
    for i in range(n):
        u = lines[i + 1]
        w = set(list(u))
        rows[i] = list(w)
        alp = alp.union(w)
    m = len(alp)
    g = [set() for _ in range(m + n)]

    d = {}
    for i, c in enumerate(alp):
        d[c] = i

    for i, row in enumerate(rows):
        for c in list(row):
            g[d[c]].add(i+m)
            g[i+m].add(d[c])
    cnt = 0
    vis = [False]*(m+n)
    for i in range(m+n):
        if vis[i]:
            continue
        vis[i] = True
        cnt += 1

        def explore(v):
            for u in g[v]:
                if vis[u]:
                    continue
                vis[u] = True
                explore(u)
        explore(i)
    print(cnt)



