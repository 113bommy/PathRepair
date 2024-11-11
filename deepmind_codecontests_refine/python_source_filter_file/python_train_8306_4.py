import sys

sys.setrecursionlimit(2 * 10 ** 5)


def dfs(v, p, links):
    farthest_d = 0
    farthest_v = v

    for u in links[v]:
        if u == p:
            continue
        res_d, res_v = dfs(u, v, links)
        if res_d > farthest_d:
            farthest_d = res_d
            farthest_v = res_v
    return farthest_d + 1, farthest_v


def solve(n, links):
    if n == 1:
        return True

    d, v = dfs(0, -1, links)
    d, v = dfs(v, -1, links)
    if (d + 1) % 3 == 0:
        return False
    return True


n = int(input())
links = [set() for _ in [0] * n]
for line in sys.stdin:
    a, b = map(int, line.split())
    a -= 1
    b -= 1
    links[a].add(b)
    links[b].add(a)
print('First' if solve(n, links) else 'Second')
