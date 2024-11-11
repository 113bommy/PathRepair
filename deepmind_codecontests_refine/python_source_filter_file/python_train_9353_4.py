mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, L, T = map(int, input().split())
    M, T = divmod(T, L)
    X = []
    W = []
    for _ in range(N):
        x, w = map(int, input().split())
        X.append(x)
        W.append(w)

    if N == 1:
        if W[0] == 1:
            print((X[0] + T)%L)
        else:
            print((X[0] - T)%L)
        exit()

    Y = []
    for i in range(N):
        if W[i] == 1:
            Y.append(((X[i] + T)%L, 1))
        else:
            Y.append(((X[i] - T)%L, 2))
    Y.sort(key=lambda p: p[0])

    if W[0] == 1:
        y0 = (X[0] + T)%L
        for i in range(N):
            if Y[i][0] == y0:
                i0 = i
                break
        S = 0
        i = 0
        idx = (M * W.count(2) * 2)%N
        while True:
            i = (i+1)%N
            if i:
                S += X[i] - X[i-1]
            else:
                S += L - (X[-1] - X[0])
            if S >= T*2:
                break
            if W[i] == 2:
                idx = (idx+1)%N
        ans = [0] * N
        for i in range(N):
            ans[(idx+i)%N] = Y[(i0+i)%N][0]
    else:
        y0 = (X[0] - T) % L
        for i in range(N-1, -1, -1):
            if Y[i][0] == y0:
                i0 = i
                break
        S = 0
        i = 0
        idx = (M * W.count(1) * 2)%N
        while True:
            i = (i - 1) % N
            if i != N-1:
                S += X[i+1] - X[i]
            else:
                S += L - (X[-1] - X[0])
            if S >= T * 2:
                break
            if W[i] == 1:
                idx = (idx - 1)%N
        ans = [0] * N
        for i in range(0, -N, -1):
            ans[(idx + i) % N] = Y[(i0+i)%N][0]
    for a in ans:
        print(a)


if __name__ == '__main__':
    main()
