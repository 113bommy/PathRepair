from collections import Counter
n, m, v, p = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
a = a[::-1]
tmp = a[p-1]
ans = p
l = 0
r = n-1
if v <= p:
    for i in range(p, n):
        if a[i]+m >= tmp:
            ans += 1
    print(ans)
    exit()
while l<r:
    mid = (l+r)//2
    if mid<=p:
        l = mid
        continue
    if a[mid]+m<tmp:
        r = mid-1
    else:
        thresh = a[mid]+m 
        amari = (v-p)*m
        for i in range(p-1,n):
            if i==mid:
                continue
            amari-=min(m,thresh-a[i])
        if amari<=0:
            l = mid
        else:
            r=mid-1
print(r+1)