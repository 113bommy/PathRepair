import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 5 + 5)


def dfs(v, p, ccc, links, ans):
    ret_colors = defaultdict(int)
    ret_count = 1
    cv = ccc[v]
    for u in links[v]:
        if u == p:
            continue
        sub_colors, sub_count = dfs(u, v, ccc, links, ans)
        cc = sub_count - sub_colors[cv]
        ans[cv] -= cc * (cc + 1) // 2
        ret_count += sub_count

        if len(ret_colors) < len(sub_colors):
            ret_colors, sub_colors = sub_colors, ret_colors

        for c, cnt in sub_colors.items():
            ret_colors[c] += cnt

    ret_colors[cv] = ret_count

    return ret_colors, ret_count


def solve(n, ccc, links):
    if n == 1:
        return [1]

    all_pair = n * (n + 1) // 2
    ans = [all_pair] * (n + 1)

    colors, count = dfs(0, -1, ccc, links, ans)
    assert count == n

    for c in range(1, n + 1):
        cc = n - colors[c]
        ans[c] -= cc * (cc + 1) // 2

    return ans[1:]


n, *cab = map(int, sys.stdin.buffer.read().split())
ccc = cab[:n]
links = [set() for _ in range(n)]

for a, b in zip(cab[n + 0::2], cab[n + 1::2]):
    a -= 1
    b -= 1
    links[a].add(b)
    links[b].add(a)

print('\n'.join(map(str, solve(n, ccc, links))))
