n = int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ans=0
for i in range(n):
    ans1=a[i]
    ans2=b[i]
    for j in range(i+1,n):
        ans1=ans1|a[j]
        ans2=ans2|b[j]
    ans=max(ans,ans1+ans2)
print(ans)        
