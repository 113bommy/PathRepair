x, y = map(int, input().split())

if x >= y and y % x == 0:
    print(-1)
else:
    print(x)

