k,s=map(int,input().split())
res=0
for i in range(k+1):
  for j in range(K+1):
    if 0<=s-i-j and s-i-j<=k:res+=1
print(res)