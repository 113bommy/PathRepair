t=int(input())
ans=[]
for i in range(0, t):
    n=int(input())
    a=list(map(int, input().split()))
    ans.append([0])
    ans[i]=0
    sum=0
    for j in range(0,len(a)):
        sum+=a[j]
        if a[j]==0:
            ans[i]+=1
            sum+=1
    if sum==0:
        ans[i]+=1
for i in range(0, t):
    print(ans[i])