from math import factorial

def Cnk(n, k):
  return factorial(n) / factorial(k) / factorial(n - k)

n = int(input())

print(Cnk(n, 5) + Cnk(n, 6) + Cnk(n, 7))