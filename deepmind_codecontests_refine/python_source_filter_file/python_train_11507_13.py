def fact(i):
  ans = 1
  for j in range(1, i + 1):
    ans *= j
  return ans

def c(i, j):
  return fact(i) / (fact(j) * fact(i - j))

n = int(input())
print(c(n, 5) + c(n, 7) + c(n, 6))