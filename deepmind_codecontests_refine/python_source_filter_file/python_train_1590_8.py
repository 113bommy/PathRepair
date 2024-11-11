n = int(input())
a = list(map(int, input().split()))

a.sort()
cans, oans = 0, 1e100
for c in range(1, 10000):
    if (c**n>10**15):
        break
    cans=0
    for i in range(n):
        cans+=abs(a[i]-c**i)
    oans=min(cans,oans)
print (oans)
