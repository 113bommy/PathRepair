from math import sqrt

a, b, c = map(int, input().split())
det = b * b - 4 * a * c
if a == 0:
  if b == 0 and c == 0:
    print(-1)
  elif c != 0:
    print(0)
  else:
    print(1)
    p = round(-c / b, 5)
    print(p)
elif det < 0:
  print(0)
elif det == 0:
  print(1)
  p = round(-b / (a * 2), 5)
  print(p)
else:
  print(2)
  neu = - b + sqrt(det)
  p = round(neu / (2 * a), 5)
  neu = - b - sqrt(det)
  q = round(neu / (2 * a), 5)
  if p > q:
    p, q = q, p
  print(p)
  print(q)

'''
And the shadow of the day
Will embrace the word in grey
And the sun will set for you
'''