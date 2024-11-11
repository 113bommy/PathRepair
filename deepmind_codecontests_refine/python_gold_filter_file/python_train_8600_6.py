n = int(input())
while n:
  n-=1
  num = int(input())
  if num % 4 == 0:
    print(num//4)
  elif num % 4 == 1:
    print( (num//4 - 2 + 1) if (num//4 - 2 +1) > 0 else -1 )
  elif num % 4 == 2:
    print( num//4 if num//4 > 0 else -1 )
  elif num % 4 == 3:
    print( (num//4 - 2 + 1) if (num//4 - 2 ) > 0 else -1 )