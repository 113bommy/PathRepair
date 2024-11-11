n,k,m=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
sm=sum(a)
avg=0
for i in range(min(m+1,n)):
    avg=max(avg,(sm+min(k*(n-i),m-i))/(n-i))
    sm-=a[i]
print(avg)