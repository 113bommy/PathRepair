n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
arr=sorted(arr,reverse=True,key=lambda x:x[1]-x[0])
ans=0
for i in range(n):
  if i%2==0:
    ans+=arr[i][0]
  else:
    ans-=arr[i][1]
print(ans)
