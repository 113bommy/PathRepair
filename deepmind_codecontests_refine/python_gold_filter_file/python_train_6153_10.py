n, d = map(int, input().split())
m = int(input())
for i in range(m):
    x, y = map(int, input().split())
    if (d <= x + y <= 2 * n - d) and (-1 * d <= x - y <= d):
        print('Yes')
    else:
        print('No')