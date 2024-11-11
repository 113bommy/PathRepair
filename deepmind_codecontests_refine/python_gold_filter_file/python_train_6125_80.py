a,b,c,d = map(int, input().split())
a, c = a+b, c+d
if a == c:
  print('Balanced')
else:
  print(['Right', 'Left'][a > c])
