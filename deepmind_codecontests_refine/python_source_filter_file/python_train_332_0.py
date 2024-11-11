from sys import stdin, stdout

LEVEL_COUNT = 15


def get_preprocessed_input():
    n = int(stdin.readline())
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, stdin.readline().split())
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)
    d = [0] * n
    dp = [[0] * n for _ in range(LEVEL_COUNT)]
    p = dp[0]
    stack = [0]
    while stack:
        u = stack.pop()
        d[u] = d[p[u]] + 1
        for v in g[u]:
            if v != p[u]:
                p[v] = u
                stack.append(v)
    for level in range(1, LEVEL_COUNT):
        for i in range(n):
            dp[level][i] = dp[level - 1][dp[level - 1][i]]
    return d, dp


def lca(d, dp, a, b):
    if d[a] < d[b]:
        a, b = b, a
    for dp1 in reversed(dp):
        a1 = dp1[a]
        if d[a1] >= d[b]:
            a = a1
    if a == b:
        return a
    for dp1 in reversed(dp):
        a1 = dp1[a]
        b1 = dp1[b]
        if a1 != b1:
            a = a1
            b = b1
    # assert dp[0][a] == dp[0][b]
    return dp[0][a]


def path_len(d, dp, a, b):
    return d[a] + d[b] - 2 * d[lca(d, dp, a, b)]


def main():
    d, dp = get_preprocessed_input()
    for _ in range(int(stdin.readline())):
        x, y, a, b, k = map(int, stdin.readline().split())
        x -= 1
        y -= 1
        a -= 1
        b -= 1
        path1 = path_len(d, dp, a, b)
        path2 = min(path_len(d, dp, a, x) + path_len(d, dp, y, b),
                    path_len(d, dp, a, y) + path_len(d, dp, x, b)) + 1
        if k >= path1 and k % 2 == path1 % 2 or\
           k >= path2 and k % 2 == path2 % 2:
            print("YES")
        else:
            print("NO")


main()
