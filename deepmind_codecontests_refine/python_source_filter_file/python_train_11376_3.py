t = int(input())
while t:
  n, l = [int(x) for x in input().split()]
  arr = [int(x) for x in input().split()]
  t = 0
  p1, p2 = 0, l
  v1, v2 = 1, 1
  m1, m2 = 0, n-1
  while m1<=m2 and m1<n and m2>=0:
    k1 = (arr[m1]-p1)/v1
    k2 = (p2-arr[m2])/v2
    if k1<k2:
      t += k1
      p1 = arr[m1]
      v1 += 1
      p2 -= k1*v2
      m1 += 1
    elif k1>k2:
      t += k2
      p2 = arr[m2]
      v2 += 1
      m2 -= 1
      p1 += k2*v1
    else:
      t += k1
      p1 = arr[m1]
      p2 = arr[m2]
      m1 += 1
      m2 -= 1
      v1 += 1
      v2 += 1
  print(t+(p2-p1)/(v1+v2))
  t -= 1