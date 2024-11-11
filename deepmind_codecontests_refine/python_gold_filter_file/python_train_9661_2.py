n=int(input())
a=list(map(int,input().split()))
b=[i for i in a if i>=0]
c=[i for i in a if i<0]
if len(b)==n:
    b.sort()
    print(-b[0]+sum(b[1:]))
    now=b[0]
    for i in range(1,n-1):
        print(now,b[i])
        now-=b[i]
    print(b[-1],now)
elif len(c)==n:
    c.sort(reverse=1)
    print(c[0]-sum(c[1:]))
    now=c[0]
    for i in range(1,n):
        print(now,c[i])
        now-=c[i]
else:
    print(sum(b)-sum(c))
    for i in range(len(b)-1):
        print(c[0],b[i])
        c[0]-=b[i]
    for i in c:
        print(b[-1],i)
        b[-1]-=i