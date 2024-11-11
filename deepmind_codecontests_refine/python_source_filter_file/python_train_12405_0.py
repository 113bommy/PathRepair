n = int(input())
m = n
g = [0] * 200005
for i in range(n - 1):
    a, b = input().split()
    a = int(a)
    b = int(b)
    g[a] += 1
    g[b] += 1
    m *= g[a] * g[b] % 998244353
print(m)
