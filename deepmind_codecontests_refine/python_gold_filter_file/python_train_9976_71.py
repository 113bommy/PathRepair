X = int(input())
ans = 1

for b in range(1,X):
  for p in range(2,10):
    if b**p<=X:
      ans = max(ans,b**p)
      
print(ans)
