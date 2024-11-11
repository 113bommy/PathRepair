X, Y = map(int, input().split())

if X % Y == 0 or X>10**18:
    print(-1)
else:
    print(X)