n = int(input())
s = input()
if n>=11:
  t = n//11
  c = s.count('8')
  print(min(c, t))
else:
  print(0)