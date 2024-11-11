n,k=map(int,input().split())
a=list(map(int,input().split()))
ans=0
min_nk=min(n,k)
for i in range(min_nk+1):#左
    for j in range(n-min_nk+i,n+1):#右
        count=a[0:i]+a[j:n]
        count.sort()
       # print(count)
        ans=max(ans,sum(count))
        for x in range(1,min_nk-len(count)+1):#消せれば消す
           # print(sum(count[x:]))
            ans=max(ans,sum(count[x:]))
print(ans)

