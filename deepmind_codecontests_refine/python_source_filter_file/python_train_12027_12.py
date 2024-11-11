def fact(i):
  ans = 1
  for j in range(1, i + 1):
    ans *= j
  return ans

def c(i, j):
  return fact(i) / (fact(j) * fact(i - j))

n = int(input())
ans = 1
for j in range(5):
 ans *= n - j
print(ans * c(n, 5))