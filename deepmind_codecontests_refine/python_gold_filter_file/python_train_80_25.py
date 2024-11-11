n,m=map(int,input().split())
a=set([int(input()) for _ in range(m)])
p,q=0,1
for i in range(1,n+1):
    p,q=q,(p+q)%(10**9+7)*(not i in a)
print(q)