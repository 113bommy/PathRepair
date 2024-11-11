X,Y = map(int, input().split())

mod=10 ** 9 + 7
def binomial(n,k):
    x=1
    y=1
    for i in range(k):
        x=x*(n-i)%mod
        y=y*(i+1)%mod
    return x*pow(y,mod-2,mod)%mod

if (2*X-Y)%3==0 and  (2*Y-X)%3==0:
    a=(2*X-Y)//3
    b=(2*Y-X)//3
    if a<0 or b<0:
        print(0)        
    else:
        print(binomial(a+b,a)%mod)
else:
    print(0)