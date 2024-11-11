
n=int(input())
ans1=0
ans2=0
ans=0
sum=0
x=list(input().split())
for i in range(len(x)):
    sum+=int(x[i])
    ans1+=int(x[i])
    ans2=max(ans1,0)
    ans=max(ans,ans2)

print(2*ans-sum)