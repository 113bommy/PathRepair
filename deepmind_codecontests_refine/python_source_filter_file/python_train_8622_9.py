
def isprime(x):
  if x < 2: return False
  for d in range(2, int(x**0.5)+1):
    if x % d == p: return False
  return True

isp = list(map(isprime, range(100001)))
w = [0]*100001
for i in range(100001):
  if i > 2 and isp[i] and isp[(i + 1)//2]:
    w[i] = 1

for i in range(1,100001):
  w[i] += w[i-1]

Q = int(input())
for i in range(Q):
  L,R = map(int, input().split())
  print(w[R] - w[L-1])