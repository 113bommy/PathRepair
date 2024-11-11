from math import factorial
def nCr(n,r):
  num = factorial(n)
  den = factorial(r)*factorial(n-r)
  return num//den

n = int(input())
print(nCr(n,n)+nCr(n,6)+nCr(n,5))