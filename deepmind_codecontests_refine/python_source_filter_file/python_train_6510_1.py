n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
c = list(map(int,input().split()))

good = {}
for i in range(n):
    if a[i] in good:
        good[a[i]] += 1
    else:
        good[a[i]] = 1
res = (0, 0)
maxi = -1
for i in range(m):
    g = 0
    p = 0
    if b[i] in good: g = good[b[i]]
    if c[i] in good: p = good[c[i]]
    if g > res[0]:
        maxi = i
        res = (g, p, )
    elif g == res[0] and p > res[1]:
        maxi = i
        res = (g, p, )
print(maxi+1)