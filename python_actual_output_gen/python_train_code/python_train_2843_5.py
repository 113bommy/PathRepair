a = int(input())
b = int(input())
c = int(input())
d = int(input())

def f(x, y):
  return x & y
def g(x, y):
  return x | y
def h(x, y):
  return x ^ y
  
A = f(a, b)
B = h(c, d)
C = g(b, c)
D = f(a, d)

x = g(A, B)
y = h(C, D)

print(1 - f(x, y))
