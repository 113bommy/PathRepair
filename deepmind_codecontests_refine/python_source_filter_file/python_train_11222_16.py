n=int(input())
h=list(map(int,input().split()))
ans=0
cnt=0
for i in range(n-1):
  if h[i]-h[i+1]>=0:
    cnt+=1
  else:
    cnt=0
  ans=max(ans,cnt)
print(cnt)