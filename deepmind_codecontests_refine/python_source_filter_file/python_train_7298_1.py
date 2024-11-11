def check(mid):
    mx=0
    for i in range(n):
        mx=max(mx,(x[i]-mid)**2/(2*y[i])+(y[i]/2))
    return mx

n=int(input())
l=-10000000
r= 10000000
x=[]
y=[]
c1,c2=0,0
for i in range(n):
    a,b=map(int,input().split())
    if b>=0:
        c1+=1
    else:
        c2+=1
        
    
    x.append(a)
    y.append(b)
if c1 and c2:
    print(-1)
    exit()
for i in range(100):
    m1=l+(r-l)/3
    m2=r-(r-l)/3
    if check(m1)>check(m2):
        l=m1
    else:
        r=m2
print(check(l))