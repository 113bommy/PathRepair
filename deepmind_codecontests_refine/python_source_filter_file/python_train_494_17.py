import math

n = int(input())
ab = []
for i in range(n):
  ab.append(tuple(map(int,input().split())))
MOD = 1000000007

d = {}
zero = 0
for a,b in ab:
  if a == 0 and b == 0:
    zero += 1
    continue
  g = math.gcd(a,b)
  a //= g
  b //= g
  if b < 0:
    a,b = -a,-b
  elif a < 0 and b == 0:
    a = -a
  rot90 = False
  if a <= 0:
    a,b = b,-a
    rot90 = True
  if (a,b) in d:
    if rot90:
      d[(a,b)][1] += 1
    else:
      d[(a,b)][0] += 1
  else:
    if rot90:
      d[(a,b)] = [0,1]
    else:
      d[(a,b)] = [1,0]
print(d)

ans = 1
for k,v in d.items():
  tmpans = pow(2,v[0],MOD)+pow(2,v[1],MOD)-1
  tmpans %= MOD
  ans *= tmpans
ans -= 1
ans += zero
print(ans%MOD)