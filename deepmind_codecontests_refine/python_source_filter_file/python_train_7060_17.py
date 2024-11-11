from bisect import bisect
n = int(input())
a = [int(x) for x in input().split()]

r = 0
s = []
for i in a:
  r += i
  s.append(r)

def bs(x,y):
  b = bisect(x, y)
  if abs(x[b-1] - y) < abs(x[b] - y):
    b = b-1
  return b

m = 10**20
for i in range(2, n-1):
  k = bs(s, s[i] / 2)
  l = bs(s, (s[n] + s[i]) / 2)
  s4 = [s[k],s[i]-s[k],s[l]-s[i],s[n]-s[l]]
  m = min(m, max(s4) - min(s4))

print(m)