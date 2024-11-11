import math

n,k = [int(x) for x in input().split()]

if (k*(k+1))//2 > n:
  print(-1)
else:
  b = (k*(k+1))//2
  f = []
  f2 = []
  for x in range(1,int(math.ceil(k**0.5))+1):
    if k%x == 0:
      f.append(x)
      f2.append(k//x)
  f += f2[::-1]

  low = 0
  high = len(f)-1

  while low <= high:
    mid = (low+high)//2
    if f[mid]*b <= n:
      low = mid+1
    else:
      high = mid-1

  cool = f[high]
  l = [x*cool for x in range(1,k+1)]
  l[-1] += n-cool*b

  print(' '.join([str(x) for x in l]))
