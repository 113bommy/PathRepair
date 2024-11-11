n,p,q,r = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))

max1 = {}
min1 = {}
max2 = {}
min2 = {}
maxval1 = a[0]
minval1 = a[0]
maxval2 = a[0]
minval2 = a[0]

for i in range(n):
  j = n-1-i
  maxval1 = max(maxval1, a[i])
  max1[i] = maxval1
  minval1 = min(minval1, a[i])
  min1[i] = minval1
  maxval2 = max(maxval2, a[j])
  max2[j] = maxval2
  minval2 = min(minval2, a[j])
  min2[j] = minval2


x = None
for i in range(n):
  y = q*a[i]
  if p > 0:
    y += p*max1[i]
  else:
    y += p*min1[i]
  if r > 0:
    y += r*max2[i]
  else:
    y += r*min2[i]
  if x is None or x < y:
    x = y

print(x)