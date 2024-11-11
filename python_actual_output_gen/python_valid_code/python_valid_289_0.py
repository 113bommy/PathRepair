n=int(input())
c=[0]*n
a=[int(x) for x in input().split()]
m=int(input())
b=[int(x)-1 for x in input().split()]
for e in b:
    c[e]+=1
c[0]*=2
c[-1]*=2
d=0
df=0
r=max([e//2 for e in c])
c=[e-r*2 for e in c]
if not any(c):
    df=a[1]-a[0]
    for i in range(1,n-1):
        if a[i+1]-a[i]!=df:
            print(-1)
            break
    else:
        print(df*2*(n-1)-1)
else:
    for i in range(n-1):
        de=a[i+1]-a[i]
        d+=min(c[i],c[i+1])*de
        df+=de    
    print(d+r*2*df)