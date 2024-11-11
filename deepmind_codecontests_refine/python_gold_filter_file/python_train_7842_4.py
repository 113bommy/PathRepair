k,b,n,t = map(int,input().split())
if k!=1:
    tmp = (t*(k-1)+b)/(k-1+b)
    ans=0
    for i in range(50):
        if tmp>=k**i:
           ans=i
    print(max(0,n-ans))
else:
    p = 1
    while p <= t:
        p = k * p + b
        n -= 1
    print(max(0, n+1))


