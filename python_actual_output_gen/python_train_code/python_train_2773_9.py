n = int(input())
l = list(map(int, input().split()))

if n == 1:
  print('{0} {1}'.format(1, 0))
elif n == 2:
  print('{0} {1}'.format(1, 1))
else:

  a = 1
  b = 1

  i = 0
  j = n - 1

  consumA = l[0]
  consumB = l[n-1]

  while a + b < n:							                 # 1 1 1, consumA=2, i=1, a=2, j=1, consumB=2
    if (consumA <= consumB):
      i+=1
      consumA+=l[i]
      a+=1

    if (consumB < consumA and i != j):
      j-=1
      consumB+=l[j]
      b+=1

  print('{0} {1}'.format(a, b))

