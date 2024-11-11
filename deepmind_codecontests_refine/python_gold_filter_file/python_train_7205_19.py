t = int(input())
for i in range(t):
    a, b, c, n = map(int, input().split())
    maxi = max(a, b, c)
    res = (n - (maxi - a) - (maxi - b) - (maxi - c))
    if res >= 0 and res % 3 == 0:
        print("YES")
    else:
        print("NO")