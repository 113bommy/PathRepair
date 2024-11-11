import sys

q = 10 ** 9 + 7
T = int(sys.stdin.readline().strip())
for t in range (0, T):
    n = int(sys.stdin.readline().strip())
    N = [[] for i in range (0, n)]
    D = [0] * n
    for i in range (0, n-1):
        u, v = list(map(int, sys.stdin.readline().strip().split()))
        u, v = u - 1, v - 1
        N[u].append(v)
        N[v].append(u)
        D[u] = D[u] + 1
        D[v] = D[v] + 1
    m = int(sys.stdin.readline().strip())
    p = list(map(int, sys.stdin.readline().strip().split()))
    F = []
    M = [1] * n
    L = [i for i in range (0, n)]
    while len(L) > 0:
        L2 = []
        i = 0
        while i < len(L):
            u = L[i]
            while D[u] == 1:
                F.append(M[u] * (n - M[u]))
                D[u] = -1
                for v in N[u]:
                    if D[v] != -1:
                        D[v] = D[v] - 1
                        M[v] = M[v] + M[u]
                        if D[v] == 1:
                            u = v
            if D[L[i]] > 1:
                L2.append(i)
            i = i + 1
        L = L2[:]
    p.sort()
    F.sort()
    ans = 0
    if m <= n - 1:
        p = [1] * (n - 1 - m) + p
    else:
        for i in range (n-1, m):
            p[n-2] = (p[n-2] * i) % q
    for i in range (0, n-1):
        ans = (ans + p[i] * F[i]) % q
    print(ans)

        
        