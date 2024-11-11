k,x,y=map(int,input().split())
if max(x,y)<k:
    print(-1)
    exit(0)

a=(x//k)
b=(y//k)
if (b==0 and a*x<y) or (a==0 and b*y<x) or (a+b==0):
    print(-1)
else:
    print(a+b)