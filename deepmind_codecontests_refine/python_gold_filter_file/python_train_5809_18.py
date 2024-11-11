from bisect import bisect_left

n, m = map(int, input().split())
a = list(map(int, input().split()))

a.sort(reverse=True)
b = list(reversed(a))

rs = [0] * n
rs[0] = a[0]
for i, x in enumerate(a[1:]):
    rs[i+1] = rs[i] + x

L = a[-1] * 2
H = a[0] * 2

while H - L > 1:
    M = (L + H) // 2
    count = 0
    for x in a:
       count += n - bisect_left(b, M - x)
    if count == m:
        L = M
        break
    elif count > m:
        L = M
    else:
        H = M

ans = 0
count = 0
for x in a:
    c = n - 1 -  bisect_left(b, L - x)
    count += c + 1
    if c >= 0:
        ans += rs[c] + x * (c+1)

print(ans - (count-m) * L)
