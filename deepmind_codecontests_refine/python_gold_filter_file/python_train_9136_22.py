n = int(input())
a = list(map(int, input().split()))

if n == 2:
  if a[0] >= a[1] and (a[0] - a[1]) % 2 == 0:
    print((a[0] - a[1]) // 2)
  else:
    print(-1)
else:
  num = 0
  for i in range(2, n):
    num ^= a[i]
  
  _and = (a[0] + a[1] - num)
  if  _and % 2 != 0 or a[0] < _and // 2 or (_and // 2) & num != 0:
    print(-1)
  else:
    _and //= 2
    
    max_2 = 1
    while max_2 <= num:
      max_2 *= 2
    
    a0 = _and
    while max_2 >= 1:
      if num & max_2 != 0 and a0 + max_2 <= a[0]:
        a0 += max_2
      max_2 //= 2
    
    if a0 != 0:
      print(a[0] - a0)
    else:
      print(-1)