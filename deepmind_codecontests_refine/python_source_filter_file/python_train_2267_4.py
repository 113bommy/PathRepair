x,n,*a=map(int,open(0).read().split())
b=[1]*101
for i in a:
    b[i]=0
c=100  
ans=0
for i in range(101):
    if b[i] and c>abs(x-i):
        c=abs(x-i)
        ans=i
print(ans)