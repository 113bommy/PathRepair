n,k = [int(i) for i in input().split()]

a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

c = [y//x for x,y in zip(a,b)]
mindex = c.index(min(c))

while k > 0:
  b[mindex] += 1
  c[mindex] = b[mindex] // a[mindex]
  k -= 1

  mindex = c.index(min(c))
  print(min(c))
