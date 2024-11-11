n = int(input())

def isprime(p):
  if p < 2:
    return False
  for i in range(2, p):
    if p % i == 0:
      return False
  return True

sol = []

for i in range(3, 55555+1, 10):
  if isprime(i):
    sol.append(i)
  if len(sol) >= n:
    break
print(sol)