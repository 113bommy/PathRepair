t = int(input())
for _ in range(t):
    a = list(map(int, input().split()))
    a.sort()
    a.reverse()
    ans = 0
    if a[0] > 0:
        ans += 1
        a[0] -= 1
    if a[1] > 0:
        ans += 1
        a[1] -= 1
    if a[2] > 0:
        ans += 1
        a[2] -= 1
    if a[0] > 0 and a[1] > 0:
        ans += 1
        a[0] -= 1
        a[1] -= 1
    if a[1] > 0 and a[2] > 0:
        ans += 1
        a[1] -= 1
        a[2] -= 1
    if a[0] > 0 and a[2] > 0:
        ans += 1
        a[0] -= 1
        a[1] -= 1
    if a[0] > 0 and a[1] > 0 and a[2] > 0:
        ans += 1
    print(ans)