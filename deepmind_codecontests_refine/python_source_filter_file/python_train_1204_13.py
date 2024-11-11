n=int(input())
arr=list(map(int,input().split()))
if n==1:print(1);exit()
freq=[0]*(10**5+1)
for i in arr:freq[i]+=1
ans=0
for i in range(2,10**5+1):
  j=i;cnt=0
  for k in range(j,10**5+1,j):
     cnt+=freq[k]
  ans=max(cnt,ans)
print(ans)
