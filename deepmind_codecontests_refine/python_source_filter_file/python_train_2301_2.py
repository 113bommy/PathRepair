n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
b = [0] * 100

for i in range(n):
    b[a[i] - 1] += 1

ma = max(b)
if ma % k != 0:
    min_my = (ma % k) * k + k
else:
    min_my = ma

ans = 0

for i in range(100):
    if b[i] != 0:
        ans += min_my - b[i]

print(ans)