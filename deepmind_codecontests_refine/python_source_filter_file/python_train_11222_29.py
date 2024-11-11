N=int(input())
H=list(map(int,input().split()))
ans=0
tmp=0
for i in range(N-1):
  if H[i]>=H[i+1]:
    tmp+=1
  else:
    tmp=0
  ana=max(tmp,ans)
  
print(ans)