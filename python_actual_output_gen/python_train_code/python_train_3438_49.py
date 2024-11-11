X = int(input())

ans = 0
for i in range(2, X):
  n = i
  while n <= X:
    ans = max(ans, n)
    n *= i
print(ans)    
  