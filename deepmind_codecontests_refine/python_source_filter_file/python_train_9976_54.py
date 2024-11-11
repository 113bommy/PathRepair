x=int(input())
ans=0
for i in range(1,32):
  for j in range(2,10):
    if x>=i**j:
      ans=(max(ans,i**J))
print(ans)