X=int(input())
ans=0

for i in range(1,100):
  for j in range(2,20):
    if i**j<=X:
      ans=max(ans,i**j)
      
print(ans)