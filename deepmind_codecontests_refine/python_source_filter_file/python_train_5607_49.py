x,y = map(int,input().split())
if abs(x) == abs(y):
  print(0 if a == b else 1)
elif x < y:
  print(min(y - x,abs(y + x) + 1))
else:
  print(min(abs(y+x),abs(y-x))+ 1 if a * b <= 0 else min(abs(y+x),abs(y-x))+ 2)
