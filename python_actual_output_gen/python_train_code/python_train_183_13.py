a,b,c,x,y = map(int,input().split())
y=min(a+b,2*c)
s=min(x,y)
if x>y:
    n=x-y
    k=a
else:
    n=y-x
    k=b
print(round(y*s+n*min(k,2*c)))
