d, n = map(int, input().split())
m = int(input())
for _ in range(m) :
    x, y = map(int, input().split())
    if (x + y) >= d and (x + y) <= n + n - d and (x - y) >= -d and (x - y) <= d :
        print("YES")
    else :
        print("NO")