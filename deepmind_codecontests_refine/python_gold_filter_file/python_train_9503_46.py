def f(a):
  res = 1
  for i in range(1, 1+a):
    res *= i
  return res
n = int(input())
print(f(n) * f(n//2 - 1) ** 2 // f(n//2) ** 2 // 2)
