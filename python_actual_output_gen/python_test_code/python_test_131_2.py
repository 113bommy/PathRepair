q = lambda:map(int, input().split())
n, k = q()
a = []
for _ in range(n):
    a += [q()]
print(k - sum(r - l + 1 for l,r in a) % k)