n = int(input())

if not n % 2:
  print(n // 2)
else:
  def primes_sieve(limit):
    a = [True] * limit
    a[0] = a[1] = False

    for (i, isprime) in enumerate(a):
      if isprime:
        for n in range(i*i, limit, i):
          a[n] = False

    return a

  sieve = primes_sieve(1000100)

  for i in range(len(sieve)):
    if sieve[i]:
      if not n % i:
        print(((n - i) // 2) + 1)
        exit()
  
  print(1)