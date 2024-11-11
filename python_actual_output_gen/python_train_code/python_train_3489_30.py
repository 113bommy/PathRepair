a,b = map(int, input().split())
draw = 0
if a == b:
  print('0 6 0')
else:

  if (a+b)%2 == 0:
    draw = 1
  else:
    draw = 0

  mid = (a+b)//2

  wina = (mid-a) + (a - 1) + 1
  if draw == 1:
    wina -= 1 
  print(mid-a, a)
  winb = b-(mid+1) + (6 - b) + 1

  if 6-a < 6-b:
    wina, winb = winb, wina
  print("{} {} {}".format(wina, draw, winb))