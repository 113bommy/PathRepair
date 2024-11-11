a=int(input())
ans=0
for i in range(a):
   x,y=map(int,input().split())
   ans+=y-x+1
print(ans)