n=int(input())
a=list(map(int,input().split()))
c=0
for i in range(n):
    if a[i]>0:
        c+=(a[i]-1)
        a[i]=1
    elif a[i]<0:
        c+=(abs(a[i]+1))
        a[i]=-1
c0=a.count(0)
c1=a.count(-1)
d=c1-c0
#print(c0,c1,d)
if c0>=c1 or c1%2==0:
    print(c+c0)
else:
    for i in range(n):
        if d%2==0:
            break
        if(a[i]==-1 and c0<1):
            c+=2
            d-=1
    #print(c)
    print(c+c0)