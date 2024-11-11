from collections import defaultdict


def find_path_length(g, start, end):
    # visited = set()
    # visited.add(start)
    q = [start]
    weight = 0
    while q:
        weight += 1
        nq = []
        for next in q:
            for e in list(g[next]):
                if e == end:
                    return weight
                g[next].discard(e)
                g[e].discard(next)
                nq.append(e)
        q = nq
    return -1


def solve(n, m, railways):
    g_train = defaultdict(set)
    g_bus = defaultdict(set)
    for a, b in railways:
        g_train[b].add(a)
        g_train[a].add(b)
    for i in range(1, n):
        for j in range(2, n + 1):
            if j not in g_train[i]:
                g_bus[i].add(j)
                g_bus[j].add(i)

    if len(g_train[n]) == n - 1 or len(g_train[n]) == 0:
        return -1

    if n in g_train[1]:
        return find_path_length(g_bus, 1, n)
    else:
        return find_path_length(g_train, 1, n)


n, m = map(int, input().split())
railways = []
for _ in range(m):
    a, b = map(int, input().split())
    railways.append((a, b))

print(solve(n, m, railways))
