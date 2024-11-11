n,m,a=map(int,input().split())
x,y=0,0
if n%a==0:
    x=n/a
elif n%a!=0:
    x=(n//a)+1
if m%a==0:
    y=m/a
elif m%a!=0:
    y=m//a+1
print(x*y)