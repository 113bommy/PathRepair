X=int(input())
ans=0

for i in range(100):
  for j in range(20):
    if i**j<=X:
      ans=max(ans,i**j)
      
print(ans)