from sys import stdin
def read(): return map(int, stdin.readline().split())

read()
a = list(read())
x = max(a)
for y in a:
  if x % y != 0:
    x = -1
    break

print(x)
