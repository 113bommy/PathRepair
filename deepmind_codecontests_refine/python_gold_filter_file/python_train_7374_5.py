N=int(input())
ans=0
for i in range(N):
    x,y= map(int,input().split())
    ans+=y-x+1
print(ans)