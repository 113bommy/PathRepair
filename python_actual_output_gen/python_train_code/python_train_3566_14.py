x, y, l, r = map(int, input().split())
a = [0]
for i in range(70):
    for j in range(70):
        a.append(x ** i + y ** j)
a.sort()
ans = 0
for i in range(len(a) - 1):
    if a[i+1]<r:
        r1=a[i+1]-1
    else:
        r1=r
    if a[i]>l:
        l1=a[i]+1
    else:
        l1=l
    if ans<=r1-l1: ans=r1-l1+1
print(ans)

