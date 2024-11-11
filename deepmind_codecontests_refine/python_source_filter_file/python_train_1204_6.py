n=int(input())
ip=list(map(int,input().split()))
m=max(ip)
arr=[0 for i in range(m+1)]
for i in ip:
    arr[i]+=1
ans=0
for i in range(2,m+1):
    j=i
    count=0
    while j<=m:
        count+=arr[j]
        j+=i
    if count>ans:
        ans=count
print(ans)
