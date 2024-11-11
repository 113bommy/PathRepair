import math,sys,re,itertools,pprint
rs,ri,rai=input,lambda:int(input()),lambda:list(map(int, input().split()))

n, d = rai()
a = [ rai() for i in range(n) ]
a.sort(key=lambda x: x[0])
l, r = 0, 1
s = m = a[0][1]
while r < n:
    s += a[r][1]
    while a[r][0] - a[l][0] >= d:
        s -= a[l][1]
        l += 1
    m = max(s, m)
    r += 1
print(m)
