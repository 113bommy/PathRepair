n,m,v,p = map(int, input().split())
a = list(map(int, input().split()))
a.sort(reverse=True)
tg = a[p-1]
l = p-1
r = n
biggest = 0
while l<r:
    x = (l+r)//2
    if a[p-1]-a[x]<=m:
        border = v*m-(n-x+p-1)*m
        biggest = sum([a[x]+m-a[j] for j in range(p-1,x)])
    else:
        r = x
        continue
    if border > biggest:
        r = x
    elif border <= biggest:
        l = x+1
print(l)