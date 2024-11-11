import bisect

MAX = 60000

#エラトステネスの篩
is_prime = [True for _ in range(MAX)]
is_prime[0] = is_prime[1] = False
for i in range(2, int(MAX ** (1 / 2)) + 1):
  if is_prime[i]:
    for j in range(i ** 2, MAX, i):
      is_prime[j] = False

primes = [i for i in range(MAX) if is_prime[i]]

while True:
  try:
    n = int(input())
    ind = bisect.bisect_left(primes, n)
    if primes[ind] == n:
      print(primes[ind - 1], primes[ind + 1])
    else:
      print(primes[ind], primes[ind + 1])

  except EOFError:
    break
