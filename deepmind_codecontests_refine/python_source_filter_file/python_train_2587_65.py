k,s=map(int,input().split())
a=0
for i in range(k+1):
  for j in range(k+1):
    if s-i-j <=k and s-i-j >=0:
      a+=1
print(ans)