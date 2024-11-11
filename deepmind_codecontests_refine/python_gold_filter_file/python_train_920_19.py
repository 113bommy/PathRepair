from copy import deepcopy
n, x = map(int, input().split())
a = list(map(int, input().split()))
ans = sum(a)
a1 = deepcopy(a)
for i in range(1, n):
    cur = x * i
    a2 = deepcopy(a1)
    for j in range(n):
        a1[n - j - 1] = min(a2[n - j - 1], a[n - i - j - 1])
        cur += a1[n - j - 1]
    ans = min(ans, cur)
print(ans)