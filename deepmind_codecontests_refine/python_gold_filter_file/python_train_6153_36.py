n, d = map(int, input().split())
i = int(input())
while(i):
    i -= 1
    x, y = map(int, input().split())
    if (x + y - d) * (x + y - 2*n + d) > 0 or (x - y - d) * (x - y + d) > 0:
        print("NO")
    else:
        print("YES")