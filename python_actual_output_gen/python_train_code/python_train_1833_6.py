n=int(input())
INF=10**9+7
sum=0
m=INF
for i in range(n):
    a,b=map(int,input().split())
    sum+=a
    if a>b:
        m=min(m,b)
if m==0:
    print(0)
else:
    print(sum-m)