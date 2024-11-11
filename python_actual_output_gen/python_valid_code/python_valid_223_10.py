s = int(input())
while s >0:
  if s%7 == 0:
    print('Yes')
    break
  s -= 4
    
if s<0:
  print('No')