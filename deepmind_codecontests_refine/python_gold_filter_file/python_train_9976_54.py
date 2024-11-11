n=int(input())

ans=1
for i in range(1,32):
  for j in range(2,10):
    if n>=i**j:
      ans=max(ans,i**j)
print(ans)