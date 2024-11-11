def divisors(n):
  small = []
  large = []
  i = 1
  while i * i <= n:
    if not n % i:
      small.append(i)
      large.append(n // i)
    i += 1
  if small[-1] == large[-1]:
    large.pop()
  return small + large[::-1]

n = int(input())
res = set(divisors(n - 1))
res.remove(1)

for d in divisor(n):
  if d == 1:
    continue
  now = n
  # simulation
  while not now % d:
    now //= now
  if now % d == 1:
    res.add(d)

print(len(res))