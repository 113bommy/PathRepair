n = int(input())
s = int(input())
def f(b, n):
  if n < b:
    return n
  return f(b, n//b) + n%b
if n == s:
  print(n+1)
  exit()
U = int(n**0.5)
for b in range(2, U+1):
  if f(b, n) == s:
    print(b)
    exit()
for p in range(U-1, 0, -1):
  if (n-s)%p:
    continue
  b = (n-s)//p + 1
  if b < 2:
    continue
  if f(b, n) == s:
    print(b)
    exit()
print(-1)