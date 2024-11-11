n = int(input())
m = 998244353
x,y=0,1
for i in range(n-1):
    x,y = y,x+y
    x%=m
    y%=m
r = pow(2,n,m)
print((y*pow(r,m-2,m))%m)
