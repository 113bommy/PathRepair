from collections import Counter
def rwh_primes(n):
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]

primes = rwh_primes(10000)
sprimes = set(primes)

def dl(x):
  if x in sprimes:
    return None
  for p in primes:
    if x % p == 0:
      return x // p
    elif p * p > x:
      return None

n = int(input())
a = sorted(map(int, input().split()), reverse = True)
sa = set(a)
r = []
x = Counter()
p1 = []
p2 = []
for v in a:
  if v in x and x[v] > 0:
    x[v] -= 1
    continue
  d = dl(v)
  if d and d in sa:
    x[d] += 1
    r.append(v)
  elif v in sprimes:
    p1.append(v)
  else:
    p2.append(v)
x = Counter()
y = 0
for v in reversed(p1):
  if v in x and x[v] > 0:
    x[v] -= 1
    continue
  r.append(v)
  if v < len(primes)+1:
    x[primes[v-1]] += 1
  else:
    y += 1
z = (len(p2) - y)//2
r.extend(p2[::-1][y:y+z])
print(*r)

