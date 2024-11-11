n = int(input())
m = int(input())
a = []
for i in range(n):
    a.append(int(input()))
mi = min(a)
cur = m
for i in range(n):
    cur += a[i] - mi
ans = cur // n
if cur % n != 0:
    ans += 1

ma = max(a) + m
print(max(ans + mi, max(a) - mi), ma)
