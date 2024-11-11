n,m=map(int,input().split())
def fun(x,y,m):
    res=1
    while y>0:
        if y%2==1:
            res=(res*x)%m
        y//=2
        x=(x*x)%m
    return res
tot = fun(2,m,10**9+7)-1
print(fun(tot,n,10**9+7))