R = lambda: map(int, input().split())
n = int(input())
m = int(input())
a, b = list(R()), list(R())
b = b[1:] + b[:1]
l, r = 0, 2 * 10**9
while (r - l) / max(1, r) >= 1e-7 and l < 10**9 + 1:
    rem = mid = (l + r) / 2
    for i in range(n):
        rem -= (m + max(0, rem)) / a[i]
        rem -= (m + max(0, rem)) / b[i]
    if rem < 0:
        l = mid
    else:
        r = mid
print(l if l < 10**9 + 1 else -1)