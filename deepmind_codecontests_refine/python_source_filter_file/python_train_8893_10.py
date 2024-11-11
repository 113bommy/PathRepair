# http://codeforces.com/problemset/problem/431/C

n, k, d = list(map(int, input().split()))

def paths_with_weight(n, k, d):
    """Naive recursive implementation."""
    if n == 0:
        return 1 if d == 0 else 0
    if n < 0:
        return 0
    return sum([paths_with_weight(n - i, k, (d if i < d else 0)) for i in range(1, k + 1)])

def dp_paths_with_weight(n, k, d, modulo=0):
    """DP Implementation. P[i][b] is the subproblem representing
    all paths from the k-tree that sum to total weight of i and
    having an edge (b=1) of weight at least d or not having such
    a constraint (b=0).
    """
    P = [[0 for b in range(2)] for i in range(n + 1)]
    P[0][0] = 1
    if modulo:
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                if i - j >= 0:
                    P[i][0] += P[i - j][0] % modulo
                    P[i][1] += (P[i - j][1] if j < d else P[i - j][0]) % modulo
        return P[n][1] % modulo
    else:
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                if i - j >= 0:
                    P[i][0] += P[i - j][0]
                    P[i][1] += (P[i - j][1] if j < d else P[i - j][0])
        return P[n][1]

print(dp_paths_with_weight(n, k, d, 1000))
