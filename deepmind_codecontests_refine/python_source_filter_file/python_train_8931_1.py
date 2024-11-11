n,k = list(map(int,input().split()))
S = 0
for i in range(1,n+1):
  p = 1
  t = 1
  while i*t < k:
    t += 2
    p /= 2
  S += p/n
print(S)