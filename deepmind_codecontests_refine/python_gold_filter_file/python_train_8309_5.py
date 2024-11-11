N, Q = map(int, input().split())

if N == 1:
    for i in range(Q):
        V, W = map(int, input().split())
        print(min(V, W))
else:
    p = []
    p.append(1)
    for i in range(40):
        p.append(p[-1] * N)

    for i in range(Q):
        V, W = map(int, input().split())

        v = []
        w = []
        dv = 0
        dw = 0

        while V > (p[dv + 1] - 1) // (N - 1): dv = dv + 1
        while W > (p[dw + 1] - 1) // (N - 1): dw = dw + 1

        v.append(V)
        e = V
        for j in range(dv, 0, -1):
            e = (e - (p[j] - 1) // (N - 1) - 1) // N + (p[j - 1] - 1) // (N - 1) + 1;
            v.append(e)
        v.reverse()

        w.append(W)
        e = W
        for j in range(dw, 0, -1):
            e = (e - (p[j] - 1) // (N - 1) - 1) // N + (p[j - 1] - 1) // (N - 1) + 1;
            w.append(e)
        w.reverse()

        ans = 1
        j = 0
        while j < len(v) and j < len(w) and v[j] == w[j]:
            ans = v[j]
            j = j + 1
        print(ans)
