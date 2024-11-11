N = int(input())

def check(p):
  _N = N
  while _N%p == 0:
    _N //= p
  return (_N-1)%p == 0

n = int(N**0.5) + 1
P0 = set([N])
P1 = set([N-1])
for i in range(2, n+1):
  if (N-1)%i == 0:
    P1.add(i)
    P1.add((N-1)//i)
  if N%i == 0:
    P0.add(i)
    P0.add(N//i)

P2.discard(1)
P1.discard(1)
ans = len(P1)
for p in P0:
  ans += check(p)

print(ans)