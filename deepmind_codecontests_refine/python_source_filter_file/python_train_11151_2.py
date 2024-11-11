n,m=map(int,input().split())
x=input()
y=input()
a=list(x)
b=list(y)
power=1
sumof=0
res=0
mod=998244353
print(b)
for i in range(0,m):
    if(i<n and a[n-1-i]=='1'):
        sumof=(sumof+power)%mod
    if(b[m-1-i]=='1'):
        res=(res+sumof)%mod
    power=(2*power)%mod
print(res)
