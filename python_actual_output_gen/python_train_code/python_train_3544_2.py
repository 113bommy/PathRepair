n,T = map(int,input().split())
a = list(map(int,input().split()))

cur = 0
ased = a[:]
ased.sort(key=lambda x:-x)
ased += [0]

s = sum(a)
r = 0

while cur!=n:
    while ased[cur]>T:
        s -= ased[cur]
        cur += 1
    if s<=T and s>0:
        d,T = divmod(T,s)
        r += d*n
        continue
    for i in range(n):
        if a[i]<=T:
            T -= a[i]
            r += 1
print(r)
