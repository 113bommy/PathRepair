X = int(input())

ans = 1
for i in range(2, X):
  n = i*i
  while n <= X:
    ans = max(ans, n)
    n *= i
print(ans)    
  