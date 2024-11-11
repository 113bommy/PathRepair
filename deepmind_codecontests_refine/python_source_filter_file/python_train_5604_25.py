N = int(input())

def is_prime(n):
  if n == 1:
    return False
  for i in range(2,int(n**0.5)+1):
    if n % i == 0:
      return False
    return True

p = []
for i in range(2, 55555+1):
  if is_prime(i) and i % 5 == 1:
    p.append(i)

print(*p[:N])