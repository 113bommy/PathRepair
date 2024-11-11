n, d = [int(x) for x in input().split()]
m = int(input())
for _ in range(m):
    x, y = [int(x) for x in input().split()]
    if y >= -x + d and y <= x + d and y >= x - d and y <= x + n - d:
        print("YES")
    else:
        print("NO")