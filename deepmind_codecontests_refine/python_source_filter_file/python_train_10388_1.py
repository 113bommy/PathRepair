N = int(input())
A = [int(a) for a in input().split()]
X = [[] for i in range(N)]
for i in range(N-1):
    x, y = map(int, input().split())
    x, y = x-1, y-1
    X[x].append(y)
    X[y].append(x)

def EulerTour(n, X, i0):
    def bl(k):
        l, r = -1, n-1
        while r - l > 1:
            m = (l + r) // 2
            if L[m][-1] < k:
                l = m
            else:
                r = m
        return l + 1

    inf = 1 << 30
    P = [-1] * n
    Q = [~i0, i0]
    ANS = [0] * n
    L = [[inf] for _ in range(n)]
    I = [0] * n
    while Q:
        i = Q.pop()
        if i < 0:
            i = ~i
            L[I[i]].pop()
            continue
        if i >= 0:
            k = A[i]
            b = bl(k)
            L[b].append(k)
            I[i] = b
            ANS[i] = bl(inf)
        for a in X[i][::-1]:
            if a != P[i]:
                P[a] = i
                for k in range(len(X[a])):
                    if X[a][k] == i:
                        del X[a][k]
                        break
                Q.append(~a)
                Q.append(a)
    return ANS

print("\n".join(map(str, EulerTour(N, X, 0))))