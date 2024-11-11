a, b, c = map(int, input().split())
A = 0
for x in range(a, b+1):
  if c % x == 0:
    A += 1
print(A)