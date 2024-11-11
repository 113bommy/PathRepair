X,Y = map(int,input().split())
mod = 10**9+7

def p(m,n):
  a = 1
  for i in range(n):
    a = (a*(m-i)) % mod
  return a

def c(m,n):
  return p(m,n)*pow(p(n,n),mod-2,mod) % mod

if (X+Y) % 3 == 0 and Y//2 <= X <= Y**2:
  print(c((X+Y)//3,(2*X-Y)//3))
else:
  print(0)