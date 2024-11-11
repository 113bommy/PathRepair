n=int(input())
ans,ans1=0,0
for i in range(n):
    x,y=map(int,input().split())
    if x<0 and y<0:
        ans+=1
    if x<0 and y>0:
        ans+=1
    if x>0 and y>0:
        ans1+=1
    if x>0 and y<0:
        ans1+=1
if (ans==1 or ans1==1) or abs(ans-ans1)==n:
    print("YES")
else:
    print("NO")
