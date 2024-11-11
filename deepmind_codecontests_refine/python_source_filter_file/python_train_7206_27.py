t = int(input())
for i in range(t):
    a, b, x, y = map(int, input().split())
    x1 = a-x-1
    x2 = x-1
    y1 = b-y-1
    y2 = y-1
    ans1 = max(x1, x2)*b
    ans2 = max(y1, y2)*a
    if x2 > x1:
        ans1 += b
    if y2 > y1:
        ans2 += a
    ans = max(ans1, ans2)
    print(ans)
