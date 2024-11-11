import math

N = int(input())
a = list(map(int,input().split()))
m = max(a)
c = [0] * (m+1)

for i in a:
  c[i] += 1

pairwise = True
for i in range(2, m, 1):
  cnt = 0
  for j in range(i, m, i):
    cnt += c[j]
    if cnt > 1:
      pairwise = False
      break
if pairwise:
  print("pairwise coprime")
  exit()

g = 0
for i in range(N):
  g = math.gcd(g, a[i])
if g == 1:
  print("setwise coprime")
  exit()

print("not coprime")