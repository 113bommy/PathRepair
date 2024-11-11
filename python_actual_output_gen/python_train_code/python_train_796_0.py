n = int(input())
a = list(map(int, input().split()))

occ = {}
for i in range(n):
    if a[i] not in occ:
        occ[a[i]] = 0
    occ[a[i]] += 1

res = 0
for x in occ:
    if (occ[x] < x):
        res += x
    else:
        res += occ[x] - x

print(res)