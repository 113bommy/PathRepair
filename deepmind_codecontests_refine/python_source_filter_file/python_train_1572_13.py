n=int(input())
a=[int(v) for v in input().split()]
a.sort()
if n==1:
    ans=0
else:
    m=(a[n-1]-a[0])*(a[-1]-a[n])
    p=a[-1]-a[0]
    q=p
    for j in range(1,n):
        q=min(q,a[j+n-1]-a[j])
    ans=min(m,p*q)
    print(ans)
        
