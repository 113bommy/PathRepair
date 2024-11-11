X = int(input())

ans = 0
for i in range(X-1,0,-1):
  for j in [2, 3, 5, 7]:
    if(i**j < X):
      ans = max(ans, i**j)
print(ans)