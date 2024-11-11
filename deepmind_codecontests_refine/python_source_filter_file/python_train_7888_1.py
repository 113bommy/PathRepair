N=int(input())

robot=[]
for _ in range(N):
    x,l=map(int,input().split())
    robot.append((x+l-1,x-l+1))
robot.sort()

tmp=-10**10
ans=0
for i in range(N):
    end,start=robot[i]
    if tmp<start:
        tmp=end
        ans+=1
print(ans)


