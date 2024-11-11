t = int(input())
i = 1
while i <= t:
  x = int(input())
  all_numbers = x * (x + 1)  / 2
  m = 0
  n = 0
  while n < x :
    n = 2 ** (m + 1) - 1
    m += 1
  m -= 1  
  r = 2 **(m + 1) - 1 
  r = -r 
  result = all_numbers  + r
  print(int(r + result))
  i += 1