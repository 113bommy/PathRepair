x,y= map(int, input().split())
a=min(x,y)
b=max(x,y)
mod=pow(10,9)+7
if b-a>=a or (a-(b-a))%3!=0:
    print(0)

else:
    r=(a-(b-a))//3
    l=((a-(b-a))//3)+(b-a)
    c=1
    d=1
    for i in range(r):
        c=(c*(l+r-i))%mod
        d=(d*(r-i))%mod
    ans=c*pow(d,mod-2,mod)
    print(ans%mod)