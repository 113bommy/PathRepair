def fac(n):
    x=1
    for i in range(1,n+1):
        x*=i
    return x

n,m=list(map(int,input().split(" ")))

x=fac(n+2*m-1)
y=fac(2*m)
z=fac(n-1)
print((x//(y*z))%(1000000007))