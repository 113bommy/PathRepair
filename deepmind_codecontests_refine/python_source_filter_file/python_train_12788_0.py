a,b,c,d,e,f=map(int,input().split())
a,b=a*100,b*100

DP=[-1 for _ in range(f+2)]
DP[a],DP[b]=0,0
for i in range(f+1):
    if DP[i]==-1:continue
    for j in a,b:
        if i+j<=f:DP[i+j]=DP[i]
    for j in c,d:
        if i+j<=f and 100*(DP[i]+j)/(i+j)<=100*e/(100+e):
            DP[i+j]=DP[i]+j

ans,water=0,[a,0]
for i,j in enumerate(DP):
    if i==0:continue
    if ans<100*j/i:
        ans=100*j/i
        water=[i,j]
print(*water)