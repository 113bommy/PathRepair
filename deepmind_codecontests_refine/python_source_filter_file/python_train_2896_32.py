n, k = map(int, input().split())
a = list(map(int, input().split()))
cum = [0] * (n+1)
for i in range(n):
    cum[i+1] = cum[i] + a[i]
koho = []
for l in range(n):
    for r in range(l,n):
        koho.append(cum[r+1] - cum[l])
ret = 0
for keta in reversed(range(30)):
    currkoho = []
    for s in koho:
        if s & (1 << keta) != 0:
            currkoho.append(s)
    if len(currkoho) >= k:
        koho = currkoho
        ret += (1 << keta)
print(ret)
