p=1000000007
def mul(x,y):
    rt=1
    while y>0:
        if y%2==1:
            rt=(rt*x)%p
        x=(x*x)%p
        y=y//2
    return rt

x,y=map(int,input().split())
if(y%x!=0):print(0)
else:
    y/=x
    d=set([])
    i=1
    while i*i<=y:
        if y%i==0:
            d.add(i);d.add(y/i)
        i+=1
    d=sorted(list(d))
    dp=d[::]
    for i in range(len(d)):
        dp[i]=mul(2,d[i]-1)
        for j in range(i):
            if d[i]%d[j]==0:
                dp[i]-=dp[j]
    print(dp[-1])