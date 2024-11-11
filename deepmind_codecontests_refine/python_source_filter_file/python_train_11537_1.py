from bisect import bisect_left
A, B, Q, *L = map(int, open(0).read().split())
s = L[:A]
t = L[A:A+B]
x = L[A+B:]

s = [-float('inf')]+s+[float('inf')]
t = [-float('inf')]+t+[float('inf')]
for c in x:
  br = bisect_left(t,c)
  ar = bisect_left(s,c)
  bl = br-1
  al = ar-1
  print(min(s[ar]-t[bl]+min(s[ar]-c,c-t[bl]),t[br]-s[al]+min(t[br]-c,c-s[al]),
            -min(t[bl],s[al]),max(s[ar],t[br])-c))