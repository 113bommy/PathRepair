n = input()
a = 0
b = 0
for s in n:
  v = int(s)
  a_ = min(a + v, b + v)
  b_ = min(a + 10 - v + 1, b + 10 - v + 1 - 2)
  a = a_
  b = b_
  
print(min(a, b))