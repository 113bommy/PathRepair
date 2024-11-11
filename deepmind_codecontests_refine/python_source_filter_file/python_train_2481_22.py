N=int(input())
D,X=map(int,input().split())
ans=X
for i in range(N):
  ans+=1+(N-1)//int(input())
print(ans)