n, d = map(int, input().split())
m = int(input())
for i in range(m):
    x, y = map(int, input().split())
    if x + y < d:
        print("NO")
        continue
    if x + y > 2 * n - d:
        print("NO")
        continue
    if (n - x) + y < n - d:
        # print((n - x), y, 1)
        print("NO")
        continue
    if (n - y) + x < n - d:
        # print((n - y), x, 2)
        print("NO")
        continue
    print("YES")
