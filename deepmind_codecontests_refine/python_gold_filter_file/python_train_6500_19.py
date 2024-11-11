n=int(input())
a=list(map(int,input().split(" ")))
b=sorted(a)
for x in range(n-1):
    a[x+1]+=a[x]
    b[x+1]+=b[x]
b=[0]+b
a=[0]+a
m=int(input())
for x in range(0,m):
    t,l,r=map(int,input().split(" "))
    if t==1:
        print(a[r]-a[l-1])
    else:
        print(b[r]-b[l-1])