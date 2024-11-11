x=int(input())
ans=0
for i in range(1,32):
  for j in range(2,11):
    if pow(i,j)<=x:
      ans=max(pow(i,j),ans)
print(ans)