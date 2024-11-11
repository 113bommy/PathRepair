def check(x):
    X=int(x)
    r=X//d*(k+d)
    x-=X//d*d
    if(x>=k):
        r+=k+x
    else:
        r+=2*x
    return r>=2*t
k,d,t=map(int,input().split())
d*=k//d+(k%d!=0)
l=0
r=1e18
for i in range(200):
    med=(r+l)/2
    if(check(med)):
        r=med
    else:
        l=med
print(l)
