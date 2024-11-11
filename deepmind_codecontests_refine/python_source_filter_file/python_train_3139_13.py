h,n=map(int,input().split())
d=list(map(int,input().split()))
minn=h
cnt=0
for i in range(n):
    h+=d[i]
    cnt+=1
    minn=min(minn,h)
    if h<=0:
        exit(print(cnt))
if sum(d)>=0:exit(print(-1))
tmp=max(0,minn//-sum(d))
h+=tmp*sum(d)
cnt+=n*tmp
for i in range(100000000):
    cnt+=1
    h+=d[i%n]
    if h<=0:
        exit(print(cnt))