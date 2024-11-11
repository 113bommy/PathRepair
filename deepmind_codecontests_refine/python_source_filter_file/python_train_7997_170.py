def resolve():
    X, Y = [int(i) for i in input().split()]
    if Y % X == 0:
        print(-1)
    else:
        print(X)

resolve()