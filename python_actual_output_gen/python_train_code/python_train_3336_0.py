n=int(input())
flowers=[0]+list(map(int,input().split()))
ans=0
for i in range(1,n+1):
  ans+=max(flowers[i+1]-flowers[i],0)
print(ans)