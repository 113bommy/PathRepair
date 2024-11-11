n=int(input())
a=list(map(int,input().split()))
res,ans,temp=0,0,0
for i in a:
    if i==1:
        ans+=1
        temp=1
    elif i==0 and temp==1:
        ans+=1
        temp=0
if temp==0:
    print(ans-1)
else:
    print(ans)
