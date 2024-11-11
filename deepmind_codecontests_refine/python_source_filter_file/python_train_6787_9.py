l = [0] * (10**6 + 1)
l[2] = 2
mod = 10**9 + 7
n, m = [int(i) for i in input().split()]
for i in range(3, max(m, n) + 1):
    l[i] = (l[i - 1] + l[i - 2]) % mod
res = 0
for i in range(n + 1):
    res += l[i]
for j in range(m + 1):
    res += l[j]
print(2 + res)