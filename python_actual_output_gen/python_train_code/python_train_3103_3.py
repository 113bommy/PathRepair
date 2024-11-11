n=int(input())
a=list(map(int,input().split()))
dp={}
m=-1
an1=[]
for i in range(n):
    try:
        p=dp[a[i]-1]
    except:
        p=0
    dp[a[i]]=p+1
    if dp[a[i]]>m:
        m=dp[a[i]]
        an=a[i]
ans=[]
for i in range(n-1,-1,-1):
    if a[i]==an:
        ans.append(i)
        an-=1
print(len(ans))
for i in range(len(ans)-1,-1,-1):
    print(ans[i],end=" ")
