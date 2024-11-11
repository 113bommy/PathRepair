import sys

T = int(sys.stdin.readline().strip())
for t in range (0, T):
    n = int(sys.stdin.readline().strip())
    N = [[] for i in range (0, n)]
    C = [[] for i in range (0, n)]
    for i in range (0, n-1):
        x, y = list(map(int, sys.stdin.readline().strip().split()))
        x, y = x-1, y-1
        N[x].append(y)
        N[y].append(x)
    for i in range (0, n):
        if len(N[i]) == 1:
            x1 = i
            y1 = N[i][0]
    N[x1] = []
    N[y1].remove(x1)
    L = [i for i in range (0, n)]
    while len(L) > 0:
        i = L.pop()
        if len(N[i]) - len(C[i]) == 1:
            s = sum(C[i])
            C[i].append(n - 2 - s)
            for j in N[i]:
                if len(N[j]) - len(C[j]) != 0:
                    C[j].append(s + 1)
                    if len(N[j]) - len(C[j]) == 1:
                        L.append(j)
    C[x1] = [n + 10]
    for i in range (0, n):
        C[i] = max(C[i])
    x2 = C.index(min(C))
    y2 = x1
    print(x1 + 1, y1 + 1)
    print(x2 + 1, y2 + 1)


    