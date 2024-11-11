X, Y = map(int, input().split())

if Y % X == 0 or X>10**18:
    print(-1)
else:
    print(X)