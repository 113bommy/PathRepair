t=int(input())
for i in range(t):
    b,p,f=map(int,input().split())
    h,c=map(int,input().split())
    s=0
    if h>=c:
        s+=min(p,b//2)*h
        b=b-2*min(p,b//2)
        s+=min(f,b//2)*c
    else:
        s+=min(f,b//2)*c
        b=b-2*min(f,b//2)
        s+=min(p,b//2)*h

print(s)
