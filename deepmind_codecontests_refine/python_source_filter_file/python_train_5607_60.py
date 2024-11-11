x,y=map(int,input().split())

count=0
xlist=[x,-x,x,-x]
ylist=[y,y,-y,-y]
numlist=[0,1,1,2]
ans=10**9+7

for i in range(4):
    if xlist[i] <= ylist(i):
        ans=min(ans,numlist[i]+ylist[i]-xlist[i])

print(ans)
