n,r=map(int, input().split())
a=list(map(int, input().split()))
b=[0]*n
for i in range(n):
    if a[i]==1:
        if i-r+1<0:
            c=0
        else:
            c=i-r+1
        if i+r-1>n-1:
            c1=n-1
        else:
            c1=i+r-1
        for j in range(c, c1+1):
            b[j]+=1
x=sum(a)
y=15
z=0
if min(b)==0:
    print(-1)
else:
    for i in range(n):
        if a[i]==1:
            if i-r+1<0:
                c=0
            else:
                c=i-r+1
            if i+r-1>n-1:
                c1=n-1
            else:
                c1=i+r-1        
            for j in range(c, c1+1):
                if (b[j]==1):
                    z+=1
            if z==0:
                x-=1
                for j in range (c, c-1):
                    b[j]-=1
            z=0
    print(x)