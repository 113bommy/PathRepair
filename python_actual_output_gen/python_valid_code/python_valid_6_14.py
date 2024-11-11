n,k=map(int,input().split())
A=[list(map(int,input().split())) for i in range(n)]
i=-1
count=0
ans=0
while count<k:
  i+=1
  ans=A[i][0]
  count+=A[i][1]
print(ans)