xs, ys = map(int, input().split())
xd, yd = map(int, input().split())
n = int(input())
s = input()
x, y = 0, 0
for i in range(n):
    if s[i] == 'U':
        y += 1
    elif s[i] == 'D':
        y -= 1
    elif s[i] == 'L':
        x -= 1
    elif  s[i] == 'R':
        x += 1
ans, l, r = 10 ** 15, 0, 2 * (10 ** 9)
while l <= r:
    mid = (l + r) // 2
    kx, ky, i = xs + x * mid, ys + y * mid, 0
    while abs(xd - kx) + abs(yd - ky) > mid * n + i and i < n - 1:
        if s[i] == 'U':
            ky += 1
        elif s[i] == 'D':
            ky -= 1
        elif  s[i] == 'L':
            kx -= 1
        elif s[i] == 'R':
            kx += 1
        i += 1
    if abs(yd - ky) + abs(xd - kx) <= mid * n + i:
        ans = min(ans, mid * n + i)
        if l == r:
            break
        r = mid
    else:
        if l == r:
            break
        l = mid + 1
if ans == 10 ** 15:
    print("-1")
else:
    print(ans)