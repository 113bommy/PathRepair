n, m = map(int, input().split())

half = n / 2
ans = 0
if half == 1 and m == 1:
    ans = 1
elif m <= half:
    ans = m + 1
else:
    ans = m - 1

if n == 1:
    ans = 1
print(ans)