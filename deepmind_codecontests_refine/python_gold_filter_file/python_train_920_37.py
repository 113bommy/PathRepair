n,x=map(int, input().split())
lst=list(map(int, input().split()))
ms=lst
lst=lst*2
ans=10**15
s=0
for i in range(n):
    s=i*x
    for j in range(n):
        ms[j]=min(ms[j],lst[n+j-i])
        s+=ms[j]
    ans=min(ans,s)
print(ans)