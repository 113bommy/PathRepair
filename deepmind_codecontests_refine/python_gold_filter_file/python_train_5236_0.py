T, = map(int, input().split())
for _ in range(T):
    K, = map(int, input().split())
    if K%2 != 0:
        print(-1)
        continue
    X = []
    R = 0
    while 1:
        c = 4
        f = 1
        while R + c - 2 <= K:
            if f:
                f = 0
                X.append(1)
            else:
                X.append(0)
            c*=2
        R += c//2 - 2
#        print(c, R, K)
        if R == K:
            break
    print(len(X))
    print(*X)
