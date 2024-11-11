n = int(input())
a = list(map(int,input().split()))

l = 1
m = 1
r = 3

sumll = a[0]
suml = a[0]
sumrr = sum(a[3:])
sumr = a[1]+a[2]+sumrr

res = sumr + a[0]

for m in range(1,n-2):
    suml += a[m]
    sumr -= a[m]
    while sumll+a[l]<=suml/2 and l<m:
        sumll += a[l]
        l += 1
    while sumrr-a[r]>=sumr/2 and r<n-1:
        sumrr -= a[r]
        r += 1
    p1 = sumll
    q1 = suml - sumll
    r1 = sumr - sumrr
    s1 = sumrr
    # print(p1,q1,r1,s1)
    p2 = p1 + a[l]
    q2 = q1 - a[l]
    r2 = r1 + a[r]
    s2 = s1 - a[r]
    abs1 = max(p1,q1,r1,s1)-min(p1,q1,r1,s1)
    abs2 = max(p2,q2,r2,s2)-min(p2,q2,r2,s2)
    abs3 = max(p1,q1,r2,s2)-min(p1,q1,r2,s2)
    abs4 = max(p2,q2,r1,s1)-min(p2,q2,r1,s1)
    rest = min(abs1,abs2,abs3,abs4)
    if res > rest:
        res = rest

print(res)