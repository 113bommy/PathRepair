n, k = [int(v) for v in input().split()]
a = [int(v) for v in input().split()]

b = []
for i in range(n):
    s = a[i]
    b.append(s)
    for j in range(i+1, n):
        s += a[j]
        b.append(s)

MAX = 40
ans = 0
for t in range(MAX, 0, -1):
    x = ans + 2 ** (t-1)
    cnt = 0
    for v in b:
        if x & v == x:
            cnt += 1
    if cnt >= k:
        ans = x

print(ans)